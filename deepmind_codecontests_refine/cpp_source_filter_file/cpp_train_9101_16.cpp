#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
long long dp[5][1010][1010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i][j - 1]) + a[i][j];
    }
    for (int j = m; j >= 1; j--) {
      dp[2][i][j] = max(dp[2][i - 1][j], dp[2][i][j + 1]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++)
      dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j - 1]) + a[i][j];
    for (int j = m; j >= 1; j--)
      dp[4][i][j] = max(dp[4][i + 1][j], dp[4][i][j - 1]) + a[i][j];
  }
  for (int i = 0; i <= n + 1; i++)
    for (int j = 1; j <= 4; j++) {
      dp[j][i][0] = -0x3f3f3f3f;
      dp[j][i][m + 1] = -0x3f3f3f3f;
    }
  for (int i = 0; i <= m + 1; i++)
    for (int j = 1; j <= 4; j++) {
      dp[j][0][i] = -0x3f3f3f3f;
      dp[j][n + 1][i] = -0x3f3f3f3f;
    }
  long long ans = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ans = max(ans, dp[1][i - 1][j] + dp[2][i][j + 1] + dp[3][i][j - 1] +
                         dp[4][i + 1][j]);
      ans = max(ans, dp[1][i][j - 1] + dp[2][i - 1][j] + dp[3][i + 1][j] +
                         dp[4][i][j + 1]);
    }
  printf("%lld\n", ans);
  return 0;
}
