#include <bits/stdc++.h>
using namespace std;
long long ans = 0, dp[5000][5000], sum[5000], num[5000];
int main() {
  int n, m, k, i, j;
  for (i = 0; i < 5000; i++)
    for (j = 0; j < 5000; j++) dp[i][j] = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) scanf("%lld", &num[i]);
  sum[0] = num[0];
  for (i = 1; i < n; i++) sum[i] = num[i] + sum[i - 1];
  dp[0][m - 1] = sum[m - 1];
  for (i = m; i < n; i++) dp[0][i] = sum[i] - sum[i - m];
  for (i = 1; i < k; i++) {
    long long mn = 0;
    for (j = (i + 1) * m - 1; j < n; j++) {
      mn = max(mn, dp[i - 1][j - m]);
      dp[i][j] = dp[0][j] + mn;
    }
  }
  for (i = 0; i < n; i++) ans = max(ans, dp[k - 1][i]);
  printf("%lld\n", ans);
}
