#include <bits/stdc++.h>
char str[105];
long long dp[105][105][105], F[105] = {1, 1};
long long Pow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y % 2) ans = ans * x % 1000000007;
    x = x * x % 1000000007;
    y /= 2;
  }
  return ans;
}
int main(void) {
  int n, m, i, j, k, p, len;
  scanf("%d%d%s", &n, &m, str + 1);
  for (i = 1; i <= n; i++) {
    if (str[i] == '1')
      dp[1][i][i] = 1;
    else
      dp[0][i][i] = 1;
  }
  for (i = 2; i <= m; i++) F[i] = (F[i - 1] + F[i - 2]) % (1000000007 - 1);
  for (p = 2; p <= m; p++) {
    for (len = 1; len <= n; len++) {
      for (i = 1; i + len - 1 <= n; i++) {
        j = i + len - 1;
        dp[p][i][j] = (dp[p - 1][i][j] + dp[p - 2][i][j]) % 1000000007;
        for (k = i; k <= j - 1; k++)
          dp[p][i][j] = (dp[p][i][j] + dp[p - 1][i][k] * dp[p - 2][k + 1][j]) %
                        1000000007;
        if (i == 1)
          dp[p][i][j] =
              (dp[p][i][j] + (Pow(2, F[p - 1]) - 1) * dp[p - 2][i][j]) %
              1000000007;
        if (j == n)
          dp[p][i][j] =
              (dp[p][i][j] + dp[p - 1][i][j] * (Pow(2, F[p - 2]) - 1)) %
              1000000007;
      }
    }
  }
  printf("%lld\n", dp[m][1][n]);
  return 0;
}
