#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 1e6 + 5;
long long n, m, sum1, sum2, inv[N], a[N], b[N], f[55][55][55];
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    if (a[i] == 0)
      sum2 += b[i];
    else
      sum1 += b[i];
  }
  sum1 %= mod;
  sum2 %= mod;
  inv[0] = inv[1] = 1;
  for (long long i = 2; i <= 100000; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (long long x = 1; x <= n; x++) {
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    long long ans = 0;
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j <= i; j++) {
        for (long long k = 0; k <= i; k++) {
          if (!f[i][j][k]) continue;
          long long v = f[i][j][k];
          if (a[x]) {
            f[i + 1][j + 1][k + 1] =
                (f[i + 1][j + 1][k + 1] +
                 v * (b[x] + j) % mod * inv[sum1 + sum2 + 2 * k - i]) %
                mod;
            f[i + 1][j][k + 1] =
                (f[i + 1][j][k + 1] + v * (sum1 + k - (b[x] + j)) % mod *
                                          inv[sum1 + sum2 + 2 * k - i]) %
                mod;
            f[i + 1][j][k] =
                (f[i + 1][j][k] +
                 v * (sum2 - (i - k)) % mod * inv[sum1 + sum2 + 2 * k - i]) %
                mod;
          } else {
            f[i + 1][j + 1][k] =
                (f[i + 1][j + 1][k] +
                 v * (b[x] - j) % mod * inv[sum1 + sum2 + 2 * k - i]) %
                mod;
            f[i + 1][j][k] =
                (f[i + 1][j][k] + v * (sum2 - (i - k) - (b[x] - j)) % mod *
                                      inv[sum1 + sum2 + 2 * k - i]) %
                mod;
            f[i + 1][j][k + 1] =
                (f[i + 1][j][k + 1] +
                 v * (sum1 + k) % mod * inv[sum1 + sum2 + 2 * k - i]) %
                mod;
          }
        }
      }
    }
    for (long long j = 0; j <= m; j++)
      for (long long k = 0; k <= m; k++) {
        if (!f[m][j][k]) continue;
        long long v;
        if (a[x])
          v = b[x] + j;
        else
          v = b[x] - j;
        ans = (ans + v * f[m][j][k]) % mod;
      }
    printf("%lld\n", (ans % mod + mod) % mod);
  }
  return 0;
}
