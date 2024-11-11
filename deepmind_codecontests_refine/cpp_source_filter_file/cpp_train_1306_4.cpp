#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  string board[n];
  for (int i = 0; i < n; ++i) cin >> board[i];
  int row_sums[n + 1];
  row_sums[0] = 0;
  for (int i = 1; i <= n; ++i) {
    row_sums[i] = row_sums[i - 1];
    for (int j = 0; j < m; ++j)
      if (board[i - 1][j] == '*') ++row_sums[i];
  }
  int col_sums[m + 1];
  col_sums[0] = 0;
  for (int i = 1; i <= m; ++i) {
    col_sums[i] = col_sums[i - 1];
    for (int j = 0; j < n; ++j)
      if (board[j][i - 1] == '*') ++col_sums[i];
  }
  int ansI = -1;
  int ansJ = -1;
  for (int i = 0; ansI == -1 && i < n; ++i)
    for (int j = 0; ansI == -1 && j < m; ++j) {
      int r = row_sums[i + 1] - row_sums[i];
      int c = col_sums[i + 1] - col_sums[i];
      int x = board[i][j] == '*' ? -1 : 0;
      if (r + c + x == row_sums[n]) {
        ansJ = i + 1;
        ansI = j + 1;
      }
    }
  if (ansI == -1)
    cout << "NO" << endl;
  else
    cout << "YES\n" << ansI << " " << ansJ << endl;
}
