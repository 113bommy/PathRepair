#include <bits/stdc++.h>
using namespace std;
int n, m, k, dp[55][2123], a[55][2123], pre[2123], suf[2123];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      a[i][j] += a[i][j - 1];
    }
  for (int j = k; j <= m; ++j)
    dp[2][j] = a[1][j] - a[1][j - k] + a[2][j] - a[2][j - k];
  for (int j = k; j <= m; ++j) pre[j] = max(pre[j - 1], dp[2][j]);
  for (int j = m; j >= k; --j) suf[j] = max(suf[j + 1], dp[2][j]);
  for (int i = 3; i <= n + 1; ++i) {
    for (int j = k; j <= m; ++j) {
      for (int r = j - k + 1; r <= j; ++r)
        dp[i][j] = max(dp[i][j], dp[i - 1][r] + a[i - 1][j] - a[i - 1][r]);
      for (int r = j + 1; r <= min(j + k - 1, m); ++r)
        dp[i][j] =
            max(dp[i][j], dp[i - 1][r] + a[i - 1][r - k] - a[i - 1][j - k]);
      dp[i][j] = max(dp[i][j], pre[j - k] + a[i - 1][j] - a[i - 1][j - k]);
      dp[i][j] = max(dp[i][j], suf[j + k] + a[i - 1][j] - a[i - 1][j - k]);
      dp[i][j] += a[i][j] - a[i][j - k];
    }
    for (int j = k; j <= m; ++j) pre[j] = max(pre[j - 1], dp[i][j]);
    for (int j = m; j >= k; --j) suf[j] = max(suf[j + 1], dp[i][j]);
  }
  int res = 0;
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= m; ++j) res = max(res, dp[i][j]);
  printf("%d\n", res);
  return 0;
}
