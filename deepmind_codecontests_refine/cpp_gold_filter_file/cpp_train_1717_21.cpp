#include <bits/stdc++.h>
using namespace std;
struct matr {
  long long a1, a2, b1, b2;
} emp;
long long n, k, l, m;
matr fib;
matr mulmatr(matr a, matr b) {
  matr c;
  c.a1 = a.a1 * b.a1 + a.a2 * b.b1;
  c.a2 = a.a1 * b.a2 + a.a2 * b.b2;
  c.b1 = a.b1 * b.a1 + a.b2 * b.b1;
  c.b2 = a.b1 * b.a2 + a.b2 * b.b2;
  c.a1 %= m;
  c.a2 %= m;
  c.b1 %= m;
  c.b2 %= m;
  return c;
}
matr binmatr(matr x, long long exp) {
  if (exp == 0) {
    return emp;
  }
  if (exp % 2) {
    return mulmatr(binmatr(x, exp - 1), x);
  }
  matr t = binmatr(x, exp >> 1);
  return mulmatr(t, t);
}
long long binpow(long long x, long long exp) {
  if (exp == 0) {
    return 1 % m;
  }
  if (exp % 2) {
    return (binpow(x, exp - 1) * (x % m)) % m;
  }
  long long t = binpow(x, exp >> 1);
  return ((t % m) * (t % m)) % m;
}
long long solve() {
  long long p = min(l, 60ll);
  if (k >= (1ll << p)) return 0ll;
  emp.a1 = emp.b2 = 1 % m;
  fib.a1 = 0;
  fib.a2 = fib.b1 = fib.b2 = 1 % m;
  long long ans = 1 % m;
  matr test = binmatr(fib, n + 1);
  long long poww = binpow(2, n);
  long long zero = test.b2;
  long long one = ((poww - zero) % m + m) % m;
  for (int i = 0; i < l; i++) {
    long long x = (k >> i) & 1;
    if (x) {
      ans = ((ans % m) * (one % m)) % m;
    } else {
      ans = ((ans % m) * (zero % m)) % m;
    }
  }
  return ans;
}
int main() {
  cin >> n >> k >> l >> m;
  cout << solve();
  return 0;
}
