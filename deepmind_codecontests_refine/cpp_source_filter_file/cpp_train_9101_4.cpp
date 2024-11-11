#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;
long long num[M][M], dp[5][M][M];
long long max(long long x, long long y) { return x > y ? x : y; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%I64d", &num[i][j]);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[1][i][j] =
          max(max(dp[1][i - 1][j], dp[1][i][j - 1]) + num[i][j], dp[1][i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      dp[2][i][j] =
          max(max(dp[2][i - 1][j], dp[2][i][j + 1]) + num[i][j], dp[2][i][j]);
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      dp[3][i][j] =
          max(max(dp[3][i + 1][j], dp[3][i][j - 1]) + num[i][j], dp[3][i][j]);
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      dp[4][i][j] =
          max(max(dp[4][i + 1][j], dp[4][i][j + 1]) + num[i][j], dp[4][i][j]);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long ans1 = 0;
      ans1 = (dp[1][i - 1][j] + dp[4][i + 1][j] + dp[2][i][j + 1] +
              dp[3][i][j - 1]);
      ans = max(ans, ans1);
      ans1 = (dp[1][i][j - 1] + dp[4][i][j + 1] + dp[2][i - 1][j] +
              dp[3][i + 1][j]);
      ans = max(ans, ans1);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
