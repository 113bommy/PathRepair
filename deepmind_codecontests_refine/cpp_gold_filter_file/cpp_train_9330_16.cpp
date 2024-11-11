#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dp[1000005][3], tot, mu[1000005], ans, fac[1000005], inv[1000005];
long long po(long long b, int p) {
  long long re = 1;
  while (p) {
    if (p % 2) re = re * b % 1000000007;
    b = b * b % 1000000007;
    p /= 2;
  }
  return re;
}
int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < 1000005; i++)
    inv[i] = po(fac[i] = fac[i - 1] * i % 1000000007, 1000000007 - 2);
  scanf("%d%d", &n, &m);
  if (n <= 2) {
    printf("0\n");
    return 0;
  }
  dp[0][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;
  mu[n - 2] = 1;
  for (int i = n - 3; i >= 1; i--) mu[i] = mu[i + 1] * (i + 2) % 1000000007;
  for (int i = 1; i <= n - 2; i++) {
    dp[i][0] = dp[i][2];
    if (i > m)
      dp[i][0] = (dp[i][0] -
                  dp[i - m][2] * fac[i - 1] % 1000000007 * inv[i - m - 1] %
                      1000000007 +
                  1000000007) %
                 1000000007;
    dp[i + 1][1] = (dp[i][1] + dp[i][0]) % 1000000007;
    dp[i + 1][2] = (dp[i][2] * i + dp[i][0]) % 1000000007;
    tot = tot * (i + 1) % 1000000007;
    if (i >= m)
      tot =
          (tot + dp[i - m][0] * fac[i] % 1000000007 * inv[i - m] % 1000000007) %
          1000000007;
    ans = (ans + tot * mu[i]) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
