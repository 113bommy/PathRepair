#include <bits/stdc++.h>
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
const long long MOD = 1000000007;
long long f, w, h, fact[200005], ifact[200005], res, tot;
long long power(long long A, long long B) {
  long long res = 1;
  while (B) {
    if (B & 1) res = res * A % MOD;
    B >>= 1;
    A = A * A % MOD;
  }
  return res;
}
long long C(long long n, long long m) {
  if (n == m) return 1;
  if (0 <= n && n <= m) return fact[m] * ifact[n] % MOD * ifact[m - n] % MOD;
  return 0;
}
signed main() {
  std::ios::sync_with_stdio(false);
  fact[0] = 1;
  for (long long i = 1; i <= 200001; ++i) fact[i] = fact[i - 1] * i % MOD;
  ifact[200001] = power(fact[200001], MOD - 2);
  for (long long i = 200001; i; --i) ifact[i - 1] = ifact[i] * i % MOD;
  std::cin >> f >> w >> h;
  for (long long i = 0; i <= w / (h + 1); ++i) {
    long long lw = w - i * (h + 1);
    res = (res + C(i - 1, lw + i - 1) *
                     (C(i - 2, f - 1) + 2 * C(i - 1, f - 1) + C(i, f - 1)) %
                     MOD) %
          MOD;
  }
  for (long long i = 0; i <= w; ++i)
    tot = (tot + C(i - 1, w - 1) *
                     (C(i - 2, f - 1) + 2 * C(i - 1, f - 1) + C(i, f - 1)) %
                     MOD) %
          MOD;
  std::cout << res * power(tot, MOD - 2) % MOD << std::endl;
  return 0;
}
