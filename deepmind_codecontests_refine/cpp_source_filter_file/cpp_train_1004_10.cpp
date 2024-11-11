#include <bits/stdc++.h>
const long long mod = 1000000007;
long long n, p, _2[60], a[60];
long long f[60][2][2][2], ans;
signed main() {
  scanf("%lld%lld", &n, &p);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  _2[0] = 1;
  for (long long i = 1; i <= n; i++) _2[i] = _2[i - 1] * 2 % mod;
  f[0][0][0][0] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long p = 0; p <= 1; p++)
      for (long long b = 0; b <= 1; b++)
        for (long long w = 0; w <= 1; w++) {
          long long x = f[i - 1][p][b][w];
          if (a[i] != 0) {
            if (b) {
              if (i == 1) continue;
              (f[i][p][b][w] += x * _2[i - 2] % mod) %= mod;
              (f[i][p ^ 1][b][w | 1] += x * _2[i - 2] % mod) %= mod;
            } else
              (f[i][p ^ 1][b][w | 1] += x * _2[i - 1] % mod) %= mod;
          }
          if (a[i] != 1) {
            if (w) {
              if (i == 1) continue;
              (f[i][p][b][w] += x * _2[i - 2] % mod) %= mod;
              (f[i][p ^ 1][b | 1][w] += x * _2[i - 2] % mod) %= mod;
            } else
              (f[i][p ^ 1][b | 1][w] += x * _2[i - 1] % mod) %= mod;
          }
        }
  for (long long b = 0; b <= 1; b++)
    for (long long w = 0; w <= 1; w++) (ans += f[n][p][b][w] %= mod);
  printf("%lld\n", ans);
}
