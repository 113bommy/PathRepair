#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  vector<vector<vector<int>>> dp(
      m, vector<vector<int>>(1 << n, vector<int>(1 << n, n * m)));
  int full = (1 << n) - 1;
  for (int j = 0; j <= full; ++j) {
    int mask = (j | (j >> 1) | (j << 1)) & full;
    dp[0][j][full & ~mask] = __builtin_popcount(j);
  }
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      int mask = (j | (j >> 1) | (j << 1)) & full;
      int popcount = __builtin_popcount(j);
      for (int k = 0; k < (1 << n); ++k) {
        if ((k & ~mask) == 0) {
          for (int l = 0; l < (1 << n); ++l) {
            int rem = full & ~mask & ~l;
            dp[i][j][rem] = min(dp[i][j][rem], dp[i - 1][l][k] + popcount);
          }
        }
      }
    }
  }
  int ans = 50;
  for (int k = 0; k < (1 << n); ++k) {
    ans = min(ans, dp[m - 1][k][0]);
  }
  cout << n * m - ans << endl;
  return 0;
}
