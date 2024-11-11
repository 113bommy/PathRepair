#include <bits/stdc++.h>
using namespace std;
const int MN = 222;
int dp[MN][3];
int t[MN][3];
int n;
int f(int col, int row) {
  if (dp[col][row] != -1) return dp[col][row];
  if (col >= n + 20) return 1;
  if (t[col + 1][row]) return 0;
  int ret = 0;
  if (t[col + 2][row] == 0 && t[col + 3][row] == 0) ret |= f(col + 3, row);
  if (row <= 1) {
    if (t[col + 1][row + 1] == 0 && t[col + 2][row + 1] == 0 &&
        t[col + 3][row + 1] == 0)
      ret |= f(col + 3, row + 1);
  }
  if (row > 0) {
    if (t[col + 1][row - 1] == 0 && t[col + 2][row - 1] == 0 &&
        t[col + 3][row - 1] == 0)
      ret |= f(col + 3, row - 1);
  }
  return dp[col][row] = ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int xx = 0; xx < tt; ++xx) {
    for (int i = 0; i < MN; ++i) {
      for (int j = 0; j < 3; ++j) {
        dp[i][j] = -1;
        t[i][j] = 0;
      }
    }
    int k;
    cin >> n >> k;
    int pos = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        char q;
        cin >> q;
        if (q != '.' && q != 's') {
          t[j][i] = 1;
        }
        if (q == 's') {
          pos = i;
        }
      }
    }
    if (f(0, pos) == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
