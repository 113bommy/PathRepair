#include <bits/stdc++.h>
using namespace std;
long long fact[500001];
long long extgcd(long long a, long long b, long long& x, long long& y) {
  long long d = a;
  if (b != 0LL) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
long long mod_inverse(long long a, long long m) {
  long long x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
long long mod_fact(long long n, long long p, long long& e) {
  e = 0;
  if (n == 0) return 1;
  long long res = mod_fact(n / p, p, e);
  e += n / p;
  if (n / p % 2 != 0) {
    return res * (p - fact[n % p]) % p;
  }
  return res * fact[n % p] % p;
}
long long mod_comb(long long n, long long k, long long p) {
  if (n < 0 || k < 0 || n < k) return 0;
  long long e1, e2, e3;
  long long a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2),
            a3 = mod_fact(n - k, p, e3);
  if (e1 > e2 + e3) return 0;
  return a1 * mod_inverse(a2 * a3 % p, p) % p;
}
int n, c;
int main(void) {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= 500000; i++) {
    fact[i] = fact[i - 1] * i % 1000003LL;
  }
  scanf("%d%d", &n, &c);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res = (res + mod_comb(c + i - 1, c - 1, 1000003LL)) % 1000003LL;
  }
  printf("%lld\n", res);
  return 0;
}
