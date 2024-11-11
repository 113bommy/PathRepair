#include <bits/stdc++.h>
long long dp[105][105][15];
long long f[105];
char a[105];
int main() {
  long long len, n;
  scanf("%lld%lld%s", &len, &n, a + 1);
  for (long long i = 1; i <= len; i++) dp[a[i] - '0'][i][i] = 1;
  f[0] = f[1] = 2;
  for (long long i = 2; i <= n; i++) f[i] = (f[i - 1] * f[i - 2]) % 1000000007;
  for (long long i = 2; i <= n; i++)
    for (long long l = 1; l <= len; l++)
      for (long long r = l; r <= len; r++) {
        dp[i][l][r] =
            (dp[i][l][r] +
             (r == len ? f[i - 2] : 1) * dp[i - 1][l][r] % 1000000007 +
             (l == 1 ? f[i - 1] : 1) * dp[i - 2][l][r] % 1000000007) %
            1000000007;
        for (long long k = l; k < r; k++)
          dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 2][k + 1][r]) %
                        1000000007;
      }
  printf("%lld\n", dp[n][1][len]);
}
