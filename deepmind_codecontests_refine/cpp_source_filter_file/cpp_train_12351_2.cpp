#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2010;
int f[N][N], g[N], dp[N];
int p[N], ip[N];
int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod) {
    if (y & 1) ret = 1ll * ret * x % mod;
  }
  return ret;
}
int main() {
  int i, j;
  int x, y, n;
  scanf("%d", &n);
  scanf("%d%d", &x, &y);
  x = 1ll * x * power(y, mod - 2);
  p[0] = 1;
  for (i = 1; i <= n; i++) p[i] = 1ll * p[i - 1] * x % mod;
  ip[0] = 1;
  for (i = 1; i <= n; i++) ip[i] = 1ll * ip[i - 1] * (1 - x + mod) % mod;
  f[0][0] = 1;
  for (i = 1; i <= n; i++)
    for (j = 0; j <= i; j++)
      f[i][j] = (1ll * f[i - 1][j] * p[j] +
                 (j == 0 ? 0 : 1ll * f[i - 1][j - 1] * ip[i - j])) %
                mod;
  g[1] = 1;
  for (i = 2; i <= n; i++) {
    g[i] = 1;
    for (j = 1; j <= i - 1; j++) g[i] = (g[i] - 1ll * g[j] * f[i][j]) % mod;
    g[i] = (g[i] + mod) % mod;
  }
  dp[1] = 0;
  for (i = 2; i <= n; i++) {
    dp[i] = i * (i - 1) / 2;
    dp[i] = 1ll * dp[i] * g[i] % mod;
    for (j = 1; j <= i - 1; j++)
      dp[i] = (dp[i] + 1ll * g[j] * f[i][j] % mod *
                           (dp[j] + j * (j - 1) / 2 + dp[i - j])) %
              mod;
    dp[i] = 1ll * dp[i] * power(1 - g[i] + mod, mod - 2) % mod;
  }
  dp[n] = (dp[n] + mod) % mod;
  dp[n] = (dp[n] + n * (n - 1) / 2) % mod;
  printf("%d\n", dp[n]);
  return 0;
}
