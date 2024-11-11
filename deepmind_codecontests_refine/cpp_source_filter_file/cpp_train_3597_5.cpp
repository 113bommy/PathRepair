#include <bits/stdc++.h>
using namespace std;
const long long N = 1505, T = 1e5 + 5;
const long long MOD = 1e9 + 7;
long long n, m, a, _a, b, t;
long long frac[T], ifrac[T];
long long ksm(long long x, long long k) {
  long long res = 1;
  for (; k; k >>= 1, x = x * x % MOD)
    if (k & 1) res = res * x % MOD;
  return res;
}
long long C(long long n, long long m) {
  if (n < m || n < 0 || m < 0) return 0;
  return frac[n] * ifrac[m] % MOD * ifrac[n - m] % MOD;
}
long long f[N], g[N], h[N], func[T], sum[N];
signed main() {
  cin >> n >> m >> a >> b >> t;
  a = a * ksm(b, MOD - 2) % MOD, _a = (1 - a + MOD) % MOD;
  frac[0] = 1;
  for (long long i = 1; i <= t; ++i) frac[i] = frac[i - 1] * i % MOD;
  ifrac[t] = ksm(frac[t], MOD - 2);
  for (long long i = t; i >= 1; --i) ifrac[i - 1] = ifrac[i] * i % MOD;
  for (long long i = 0; i <= t; ++i)
    func[i] = C(t, i) * ksm(a, i) % MOD * ksm(_a, t - i) % MOD;
  for (long long i = 1; i <= m; ++i) sum[i] = (sum[i - 1] + func[i - 1]) % MOD;
  g[m] = 1;
  for (long long i = 1; i <= m + 1; ++i) f[i] = (f[i - 1] + g[i - 1]) % MOD;
  for (long long i = 1; i <= m; ++i)
    h[i] = (h[i - 1] + f[i] * func[i - 1]) % MOD;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j)
      g[j] = ((f[m + 1] - f[m - j + 1] + MOD) * sum[j] % MOD - h[j] + MOD) %
             MOD * func[m - j] % MOD;
    for (long long j = 1; j <= m + 1; ++j) f[j] = (f[j - 1] + g[j - 1]) % MOD;
    for (long long j = 1; j <= m; ++j)
      h[j] = h[j - 1] + f[j] * func[j - 1] % MOD;
  }
  return printf("%lld\n", f[m + 1]), 0;
}
