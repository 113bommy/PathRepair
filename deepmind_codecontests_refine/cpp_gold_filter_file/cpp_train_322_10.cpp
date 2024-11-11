#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long inv[5110], fac[5110], s_inv[5110];
void prepare() {
  fac[0] = inv[0] = s_inv[0] = 1;
  inv[1] = s_inv[1] = fac[1] = 1;
  for (long long i = (2); i <= (5100); ++i) {
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    s_inv[i] = s_inv[i - 1] * inv[i] % MOD;
    fac[i] = fac[i - 1] * i % MOD;
  }
}
long long c(long long n, long long k) {
  if (n == k) return 1;
  if (k > n || k < 0) return 0;
  return fac[n] * s_inv[k] % MOD * s_inv[n - k] % MOD;
}
long long g(long long s, long long p, long long m) {
  long long ret = 0, sign = -1;
  for (long long i = (0); i <= (p); ++i) {
    sign *= -1;
    ret =
        (ret + sign * c(p, i) % MOD * c(s - i * (m + 1) + p - 1, p - 1) % MOD) %
        MOD;
  }
  return ret;
}
long long power(long long x, long long y) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}
int main() {
  prepare();
  long long p, s, r;
  scanf("%lld %lld %lld", &p, &s, &r);
  long long P = 0, Q = c(s - r + p - 1, p - 1);
  for (long long t = (r); t <= (s); ++t)
    for (long long q = 1; q * t <= s && q <= p; ++q) {
      P = (P +
           c(p - 1, q - 1) * g(s - q * t, p - q, t - 1) % MOD * inv[q] % MOD) %
          MOD;
    }
  printf("%lld\n", P * power(Q, MOD - 2) % MOD);
  return 0;
}
