#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
const int L = 1001;
long long gcdex(long long a, long long b, long long& x, long long& y) {
  long long ax = 1, ay = 0;
  long long bx = 0, by = 1;
  while (b) {
    long long r = a / b;
    long long t = a - r * b;
    a = b;
    b = t;
    long long tx = ax - r * bx;
    ax = bx;
    bx = tx;
    long long ty = ay - r * by;
    ay = by;
    by = ty;
  }
  x = ax;
  y = ay;
  return a;
}
long long modinv(long long a, long long mod) {
  long long x, y;
  gcdex(a, mod, x, y);
  if (x < 0) {
    x += mod;
  }
  return x;
}
long long powmod(long long p, long long n, long long mod) {
  long long q = p % mod;
  long long pow = 1;
  while (n) {
    if (n & 1) {
      pow *= q;
      pow %= mod;
    }
    q = q * q;
    q %= mod;
    n /= 2;
  }
  return pow;
}
const int N = 1e6 + 1;
template <int S>
struct Comb {
  long long r[S + 1];
  long long f[S + 1];
  long long mod;
  Comb(int m) {
    mod = m;
    f[0] = 1;
    r[0] = 1;
    for (long long i = 1; i <= S; i++) {
      f[i] = i * f[i - 1] % m;
      r[i] = modinv(i, m) * r[i - 1] % m;
    }
  }
  long long c(int n, int i) {
    if (i < 0 || n < i) {
      return 0;
    }
    return f[n] * r[i] % mod * r[n - i] % mod;
  }
};
Comb<N> comb(M);
long long C(int n, int i) { return comb.c(n, i); }
long long mem[L][L];
long long ps[L];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    ps[i] = 1;
    for (int j = 0; j < n; j++) {
      ps[i] *= i;
      ps[i] %= M;
    }
  }
  if (m == 1) {
    cout << powmod(k, n, M) << endl;
    return 0;
  }
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    long long v = 0;
    long long s = 1;
    for (int j = i; j >= 1; j--) {
      v += (M + s) % M * ps[j] % M * C(i, j) % M;
      v %= M;
      s *= -1;
    }
    for (int j = 0; j <= i; j++) {
      ret += C(k, i) * v % M * v % M * C(i, j) % M * powmod(j, n * (m - 2), M) %
             M * C(k - i, i - j) % M;
      ret %= M;
    }
  }
  cout << ret << endl;
  return 0;
}
