#include <bits/stdc++.h>
using namespace std;
long long i, j, n, m, k, x, p, r0, r1, a00, a01, a10, a11, l, k1, k2, pp;
long long liel;
set<long long> s[20];
long long M = 10000000000000;
long long K = 100000;
long long r(long long a, long long b) {
  long long q;
  long long a1, a2, b1, b2;
  a %= M;
  b %= M;
  a1 = a / K;
  a2 = a % K;
  b1 = b / K;
  b2 = b % K;
  long long t;
  t = (a1 * b1);
  t %= M;
  t *= K;
  liel = max(liel, t);
  t %= M;
  t *= K;
  liel = max(liel, t);
  t %= M;
  q = t;
  t = (a1 * b2);
  t %= M;
  t *= K;
  liel = max(liel, t);
  t %= M;
  q += t;
  t = (a2 * b1);
  t %= M;
  t *= K;
  liel = max(liel, t);
  t %= M;
  q += t;
  t = (a2 * b2);
  t %= M;
  liel = max(liel, t);
  q += t;
  q %= M;
  return q;
}
long long f(long long y) {
  y--;
  if (y < 0) {
    return 0;
  }
  long long a[2][2];
  a[0][0] = 1;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = 0;
  long long rez[2][1];
  rez[0][0] = 1;
  rez[1][0] = 0;
  long long i = 1;
  while (i <= y) {
    l = y ^ i;
    if (y > l) {
      r0 = r(a[0][0] % M, rez[0][0] % M) + r(a[0][1] % M, rez[1][0] % M);
      r1 = r(a[1][0] % M, rez[0][0] % M) + r(a[1][1] % M, rez[1][0] % M);
      r0 %= M;
      r1 %= M;
      rez[0][0] = r0;
      rez[1][0] = r1;
      y ^= i;
    }
    a00 = r(a[0][0] % M, a[0][0] % M) + r(a[0][1] % M, a[1][0] % M);
    a01 = r(a[0][0] % M, a[0][1] % M) + r(a[0][1] % M, a[1][1] % M);
    a10 = r(a[1][0] % M, a[0][0] % M) + r(a[1][1] % M, a[1][0] % M);
    a11 = r(a[1][0] % M, a[0][1] % M) + r(a[1][1] % M, a[1][1] % M);
    a00 %= M;
    a01 %= M;
    a10 %= M;
    a11 %= M;
    a[0][0] = a00;
    a[0][1] = a01;
    a[1][0] = a10;
    a[1][1] = a11;
    i *= 2;
  }
  return rez[0][0];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  s[0].insert(0);
  p = 1;
  i = 1;
  x = 10;
  while (i <= 14) {
    j = p;
    pp = p;
    k1 = f(0);
    k2 = f(1);
    while (f(j + 1) % x != k2 % x || f(j) % x != k1 % x) {
      j += p;
    }
    p = j;
    for (long long k : s[i - 1]) {
      if (f(k) == n) {
        cout << k;
        return 0;
      }
      j = k;
      while (j < p) {
        if (f(j) % x == n % x) {
          s[i].insert(j);
        }
        j += pp;
      }
    }
    x *= 10;
    i++;
  }
  cout << -1;
  return 0;
}
