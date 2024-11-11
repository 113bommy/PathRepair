#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, m, x, ans, fac[800000], ifac[800000];
long long inv(long long x) {
  return x == 1 ? 1 : (mod - mod / x) * inv(mod % x) % mod;
}
long long pw(long long x, long long k) {
  if (k == 0) return 1;
  if (x < 0) x += mod;
  long long tmp = pw(x * x % mod, k >> 1);
  return k & 1 ? tmp * x % mod : tmp;
}
long long C(long long x, long long y) {
  return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
long long S(long long x, long long y) {
  long long ret = 0;
  for (long long i = 0; i <= y; ++i) {
    ret = (ret + pw(-1, i) * C(y, i) % mod * pw(y - i, x)) % mod;
  }
  ret = ret * ifac[y] % mod;
  return ret;
}
int main() {
  scanf("%lld%lld", &n, &m);
  fac[0] = 1;
  for (long long i = 1; i <= n + m; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[n + m] = inv(fac[n + m]);
  for (long long i = n + m - 1; i >= 0; --i)
    ifac[i] = ifac[i + 1] * (i + 1) % mod;
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &x);
    ans = (ans + x) % mod;
  }
  ans = ans * (S(n, m) + S(n - 1, m) * (n - 1) % mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
