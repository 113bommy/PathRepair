#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long i, i0, n, m, a, b;
void extgcd(long long a, long long b, long long& d, long long& x,
            long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long n) {
  long long d, x, y;
  extgcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
long long qpow(long long a, long long b, long long mod) {
  long long r = 1, t = a;
  while (b) {
    if (b & 1) r = (r * t) % mod;
    b >>= 1;
    t = (t * t) % mod;
  }
  return r;
}
int main() {
  scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
  long long ans = 0, p = 1, q = 1, r = qpow(m, n - 2, mod);
  if (n == 2) {
    printf("1\n");
    return 0;
  }
  ans += 2 * qpow(n, n - 3, mod) % mod * r % mod;
  for (i = 1; i <= min(m - 1, n - 2); i++) {
    r *= inv(m, mod);
    p *= (m - i) * (n - 1 - i) % mod;
    q *= i;
    p %= mod, q %= mod, r %= mod;
    if (i == n - 2)
      ans += p * qpow(q, mod - 2, mod) % mod * r;
    else
      ans += p * inv(q, mod) % mod * (2 + i) % mod * qpow(n, n - 3 - i, mod) %
             mod * r;
    ans %= mod;
  }
  printf("%lld\n", ans);
  return 0;
}
