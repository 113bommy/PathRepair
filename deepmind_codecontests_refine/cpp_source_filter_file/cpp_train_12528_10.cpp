#include <bits/stdc++.h>
using namespace std;
char board[55][55];
void copy(char a[55][55], int row, int col, char b[55][55]) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      a[i][j] = b[i][j];
    }
  }
}
void dfs(char a[55][55], int row, int col) {
  if (a[row][col] != '#')
    return;
  else {
    a[row][col] = '.';
    dfs(a, row - 1, col);
    dfs(a, row + 1, col);
    dfs(a, row, col - 1);
    dfs(a, row, col + 1);
  }
}
bool check(char b[55][55], int row, int col) {
  int count = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j] == '#') {
        count++;
      }
    }
  }
  if (count < 2) {
    return false;
  }
  char a[55][55];
  copy(a, row, col, b);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (a[i][j] == '#') {
        dfs(a, i, j);
        bool f = true;
        for (int m = 0; m < row; m++) {
          for (int n = 0; n < col; n++) {
            if (a[m][n] == '#') {
              f = false;
            }
          }
        }
        if (f)
          return true;
        else
          copy(a, row, col, b);
      }
    }
  }
  return false;
}
int main() {
  int row, col;
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> board[i][j];
    }
  }
  if (!check(board, row, col)) {
    cout << "-1" << endl;
    return 0;
  }
  char a[55][55];
  copy(a, row, col, board);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (a[i][j] == '#') {
        a[i][j] = '.';
        if (!check(a, row, col)) {
          cout << "1" << endl;
          return 0;
        }
        a[i][j] = '#';
      }
    }
  }
  cout << "2" << endl;
  return 0;
}
