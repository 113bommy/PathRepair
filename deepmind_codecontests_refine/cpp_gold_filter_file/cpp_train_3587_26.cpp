#include <bits/stdc++.h>
int const N = 2010;
long long const INF = (long long)1e18;
int a[N][N];
int pref[N][N];
long long dp[N][N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i] + j);
      pref[i][j + 1] = pref[i][j] + a[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    dp[0][i] = pref[0][i];
  }
  for (int i = 1; i < n; ++i) {
    if (i % 2 == 0) {
      dp[i][1] = -INF;
      long long best = dp[i - 1][1];
      for (int j = 2; j <= m; ++j) {
        dp[i][j] = best + pref[i][j];
        best = std::max(best, dp[i - 1][j]);
      }
    } else {
      dp[i][m] = -INF;
      long long best = dp[i - 1][m];
      for (int j = m - 1; j > 0; --j) {
        dp[i][j] = best + pref[i][j];
        best = std::max(best, dp[i - 1][j]);
      }
    }
  }
  long long ans = -INF;
  for (int i = 1; i <= m; ++i) {
    ans = std::max(ans, dp[n - 1][i]);
  }
  printf("%I64d\n", ans);
}
