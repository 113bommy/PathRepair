#include <bits/stdc++.h>
static const long long MAXN = 1005;
static const long long MAXD = 11;
static const long long MAX_MODULUS = 1e9 + 7;
template <typename T>
inline T min(const T a, const T b) {
  return a < b ? a : b;
}
long long n, d, mod;
inline long long fpow(long long base, long long exp) {
  long long ans = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) (ans *= base) %= mod;
    base = (long long)base * base % mod;
  }
  return ans;
}
inline long long _inv(const long long x) { return fpow(x, mod - 2); }
long long inv[MAXD];
inline void calc_inversions() {
  for (long long i = 1; i < MAXD; ++i) inv[i] = _inv(i);
}
inline long long binom_2(const long long x) {
  return (long long)x * (x - 1) % mod * inv[2] % mod;
}
long long f[MAXN][MAXD][MAXN] = {{{0}}};
signed main() {
  scanf("%I64d%I64d%I64d", &n, &d, &mod);
  if (n <= 2) {
    puts("1");
    return 0;
  }
  calc_inversions();
  for (long long i = 0; i <= n; ++i) f[0][0][i] = 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= d; ++j)
      for (long long k = 1; k <= min(i, (n + 1) / 2); ++k) {
        long long binom_begin = (k == 1 ? 1 : f[k - 1][d - 1][k - 1]);
        long long binom_val = 1;
        for (long long t = 0; t <= i / k && t <= j; ++t) {
          f[i][j][k] =
              ((long long)f[i][j][k] +
               binom_val * f[i - k * t][j - t][min(i - k * t, k - 1)]) %
              mod;
          binom_val =
              (long long)binom_val * (binom_begin + t) % mod * inv[t + 1] % mod;
        }
      }
  long long ans =
      (f[n - 1][d][(n - 1) / 2] +
       ((n & 1) ? 0 : binom_2(f[n / 2 - 1][d - 1][(n - 1) / 2] + 1))) %
      mod;
  printf("%I64d\n", ans);
  return 0;
}
