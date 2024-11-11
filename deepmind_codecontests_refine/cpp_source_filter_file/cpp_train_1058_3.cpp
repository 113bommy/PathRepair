#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 55;
char a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N][MAX_N];
int pref[MAX_N][MAX_N];
void relax(int &x, int y) { x = min(x, y); }
int get_sum(int i1, int j1, int i2, int j2) {
  return pref[i2 + 1][j2 + 1] - pref[i2 + 1][j1] - pref[i1][j2 + 1] +
         pref[i1][j1];
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                   (a[i - 1][j - 1] == '#');
    }
  }
  for (int i2 = 0; i2 < n; ++i2) {
    for (int j2 = 0; j2 < n; ++j2) {
      for (int i1 = i2; i1 > -1; --i1) {
        for (int j1 = j2; j1 > -1; --j1) {
          int len_i = i2 - i1 + 1;
          int len_j = j2 - j1 + 1;
          dp[i1][j1][i2][j2] =
              (get_sum(i1, j1, i2, j2) ? max(len_i, len_j) : 0);
        }
      }
    }
  }
  for (int i2 = 0; i2 < n; ++i2) {
    for (int j2 = 0; j2 < n; ++j2) {
      for (int i1 = i2; i1 > -1; --i1) {
        for (int j1 = j2; j1 > -1; --j1) {
          for (int i = i1; i < i2; ++i) {
            relax(dp[i1][j1][i2][j2],
                  dp[i1][j1][i][j2] + dp[i + 1][j1][i2][j2]);
          }
          for (int j = i1; j < j2; ++j) {
            relax(dp[i1][j1][i2][j2],
                  dp[i1][j1][i2][j] + dp[i1][j + 1][i2][j2]);
          }
        }
      }
    }
  }
  cout << dp[0][0][n - 1][n - 1] << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests = 1;
  while (tests--) {
    solve();
  }
  return 0;
}
