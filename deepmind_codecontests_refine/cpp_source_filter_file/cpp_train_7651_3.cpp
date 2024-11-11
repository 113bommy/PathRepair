#include <bits/stdc++.h>
using namespace std;
long long dp[40][40][50];
int main() {
  memset(dp, 0x7f, sizeof(dp));
  for (int i = 1; i <= 30; i++)
    for (int j = 1; j <= 30; j++) {
      if (i * j <= 50) dp[i][j][i * j] = 0;
      dp[i][j][0] = 0;
    }
  for (int i = 1; i <= 30; i++)
    for (int j = 1; j <= 30; j++)
      for (int k = 0; k <= min(i * j, 50); k++) {
        for (int p = 1; p < i; p++)
          for (int k2 = 0; k2 <= k; k2++)
            dp[i][j][k] =
                min(dp[i][j][k], dp[p][j][k2] + dp[i - p][j][k - k2] + j * j);
        for (int p = 1; p < j; p++)
          for (int k2 = 0; k2 <= k; k2++)
            dp[i][j][k] =
                min(dp[i][j][k], dp[i][p][k2] + dp[i][j - p][k - k2] + i * i);
      }
  int T, n, m, k;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    printf("%lld\n", dp[n][m][k]);
  }
  return 0;
}
