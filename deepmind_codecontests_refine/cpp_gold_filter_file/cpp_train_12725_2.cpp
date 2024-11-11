#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long mod = 998244353;
const long long phi = mod - 1;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long n, m, l, r;
int main() {
  scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
  long long k = n * m;
  if (n * m % 2 == 1)
    printf("%lld\n", qpow(r - l + 1, k));
  else {
    long long inv2 = qpow(2, mod - 2);
    long long p = r / 2 - (l - 1) / 2, q = r - l + 1 - p;
    printf("%lld\n", (qpow((p + q) % mod, k) + qpow((p - q + mod) % mod, k)) %
                         mod * inv2 % mod);
  }
  return 0;
}
