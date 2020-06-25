#include <iostream>
using namespace std;
int board[9][9] = {
	{0,2,0,0,0,0,0,0,0},
	{0,0,0,6,0,0,0,0,3},
	{0,7,4,0,8,0,0,0,0},
	{0,0,0,0,0,3,0,0,2},
	{0,8,0,0,4,0,0,1,0},
	{6,0,0,5,0,0,0,0,0},
	{0,0,0,0,1,0,7,8,0},
	{5,0,0,0,0,9,0,0,0},
	{0,0,0,0,0,0,0,4,0}
};
void fill_board(int col, int row, int value)
{
	board[col - 1][row - 1] = value;
}
bool is_safe(int row, int col, int value)
{
	for (int i{}; i < 9; i++)
	{
		if (value == board[row][i])
		{
			if (i != col)
				return false;
		}
	}
	for (int i{}; i < 9; i++)
	{
		if (value == board[i][col])
		{
			if (i != row)
				return false;
		}
	}
	int xb = row / 3, yb = col / 3;
	for (int i = xb * 3; i < (xb + 1) * 3; i++)
	{
		for (int j = yb * 3; j < (yb + 1) * 3; j++)
		{
			if (value == board[i][j])
			{
				if (  i != row || j!= col   )
					return false;
			}

		}
	}


	return true;

}
void display_board()
{
	for (int i{}; i < 9; i++)
	{
		for (int j{}; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}
bool sudoku(int col , int row)
{
	if (row >= 9)
	{
		col++;
		row = 0;

	}
	
	if (col >= 9 )
		return true;

	for (int rw_c{row}; rw_c < 9 ; rw_c++)
	{
		if (board[rw_c][col] != 0)
			continue;

		for (int val {1}; val < 10; val++)
		{
			if (is_safe(rw_c, col, val))
			{
				board[rw_c][col] = val;

				if (sudoku(col,rw_c + 1) ) 
					return true;
				board[rw_c][col] = 0;
			}
		}

		return false;
	}

	if (sudoku(col + 1, 0))
	{
		return true;
	}
}


int main()
{
	bool res = sudoku(0,0);
	display_board();

}