#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k;
bool solve(vector<vector<char>>& board) {
  function<bool(int, int, int)> check = [&](int row, int x, int y) {
    if (x > y) swap(x, y);
    if (((y - x) & 1) || (y - x) / 2 < k || row + (y - x) / 2 >= n)
      return false;
    int a = row + (y - x) / 2, b = (x + y) / 2;
    while (a >= row) {
      if (board[a][b] == '.') return false;
      --a, --b;
    }
    a = row + (y - x) / 2, b = (x + y) / 2;
    while (a >= row) {
      if (board[a][b] == '.') return false;
      --a, ++b;
    }
    return true;
  };
  function<void(int, int, int)> fill = [&](int row, int x, int y) {
    if (x > y) swap(x, y);
    int a = row + (y - x) / 2, b = (x + y) / 2;
    while (a >= row) {
      board[a][b] = 'X';
      --a, --b;
    }
    a = row + (y - x) / 2, b = (x + y) / 2;
    while (a >= row) {
      board[a][b] = 'X';
      --a, ++b;
    }
  };
  function<void()> paint = [&]() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << board[i][j] << " ";
      cout << endl;
    }
  };
  int i, j, t;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (board[i][j] == '*') {
        for (t = 0; t < m; ++t) {
          if (board[i][t] != '.' && check(i, j, t)) {
            fill(i, j, t);
          }
        }
      }
      if (board[i][j] == '*') return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> board[i][j];
      }
    }
    if (solve(board))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
