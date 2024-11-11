#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, m, M, s, len, ans, co, T, f, r, t, pos, pre, now;
long long mod = 998244353, mmax, mmax2, co1, co2;
long long fact[200001], inv[200001], invfac[200001];
long long a[200001];
unordered_map<long long, long long> z;
void init(long long n = 200000) {
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = (long long)i * fact[i - 1] % mod;
  inv[1] = 1;
  for (long long i = 2; i <= n; i++)
    inv[i] = mod - (long long)(mod / i) * inv[mod % i] % mod;
  invfac[0] = 1;
  for (long long i = 1; i <= n; i++)
    invfac[i] = (long long)invfac[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m) {
  return (long long)fact[n] * invfac[m] % mod * invfac[n - m] % mod;
}
int main() {
  init();
  scanf("%lld", &T);
  while (T--) {
    z.clear();
    mmax = mmax2 = -1;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      z[a[i]]++;
    }
    for (i = 1; i <= n; i++) mmax = max(mmax, a[i]);
    for (i = 1; i <= n; i++)
      if (a[i] != mmax) mmax2 = max(mmax2, a[i]);
    co1 = z[mmax], co2 = z[mmax2];
    if (mmax2 == -1 || z[mmax] >= 2)
      ans = fact[n] % mod;
    else if (mmax - mmax2 >= 2)
      ans = 0;
    else
      ans = C(n, co1 + co2) * C(co2, 1) % mod * fact[co2 + co1 - 1] % mod *
            fact[n - co1 - co2] % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
