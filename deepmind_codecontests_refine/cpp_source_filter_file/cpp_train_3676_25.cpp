#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20, MAXDIG = 4, MAXT = 10;
long long dp[MAXN + 5][MAXDIG + 5][MAXT + 5][2];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  dp[2][2][1][1] = 1;
  dp[2][3][1][1] = 2;
  dp[2][4][1][1] = 3;
  for (int i = 3; i <= n; i++)
    for (int j = 1; j <= 4; j++)
      for (int k = 0; k <= t; k++)
        for (int r = 1; r <= 4; r++) {
          if (r < j) dp[i][j][k][1] += dp[i - 1][r][k][1];
          if (r > j && k > 0) dp[i][j][k][1] += dp[i - 1][r][k - 1][0];
          if (r > j)
            dp[i][j][k][0] += dp[i - 1][r][k][0],
                dp[i][j][k][0] += dp[i - 1][r][k][1];
        }
  long long ans = 0;
  for (int i = 1; i <= 4; i++) ans += dp[n][i][t][0];
  printf("%lld\n", ans);
  return 0;
}
