#include <bits/stdc++.h>
long long n, x;
long long f[510][510];
long long c[510][510];
inline long long min(long long a, long long b) { return a < b ? a : b; }
signed main() {
  scanf("%lld%lld", &n, &x);
  for (long long i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j]) % 998244353;
  }
  f[n][0] = 1;
  for (long long i = n; i > 1; i--)
    for (long long j = 0; j < x; j++)
      if (f[i][j]) {
        long long t = 1, r = min(j + i - 1, x);
        for (long long k = i; k >= 0; k--) {
          (f[k][r] += f[i][j] * c[i][k] % 998244353 * t) %= 998244353;
          (t *= r - j) %= 998244353;
        }
      }
  long long ans = 0;
  for (long long i = 0; i <= x; i++) (ans += f[0][i]) %= 998244353;
  printf("%lld", ans);
}
