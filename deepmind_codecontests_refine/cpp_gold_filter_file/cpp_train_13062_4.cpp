#include <bits/stdc++.h>
using namespace std;
long long ans, dp[3][710][710];
int n, m, x, y, d[710];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    dp[0][x][y] = dp[0][y][x] = 1;
    d[x]++;
    d[y]++;
  }
  for (int l = 0; l < 2; l++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dp[l][i][j])
          for (int k = 1; k <= n; k++)
            dp[l + 1][i][k] += dp[l][i][j] * dp[0][j][k];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans += dp[1][i][j] * dp[2][i][j];
  ans /= 10;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      for (int k = 1; k < j; k++)
        if (dp[0][i][k] && dp[0][i][j] && dp[0][j][k])
          ans -= (d[i] + d[j] + d[k] - 3);
  printf("%lld", ans);
  return 0;
}
