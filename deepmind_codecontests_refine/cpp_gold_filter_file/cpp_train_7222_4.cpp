#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int board[4][4];
  int i, j, n = 4;
  bool flag = false;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> c;
      if (c == '#')
        board[i][j] = 1;
      else
        board[i][j] = 0;
    }
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1; j++) {
      if (board[i][j] + board[i][j + 1] + board[i + 1][j + 1] +
              board[i + 1][j] !=
          2)
        flag = true;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}
