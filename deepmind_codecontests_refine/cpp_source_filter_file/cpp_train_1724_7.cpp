#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
int k;
long long C[205][205], F[205][205], l, r, ans, I2, I5;
struct num {
  long long a, b;
  num(long long _a = 0, long long _b = 0) { a = _a, b = _b; }
} A, B;
long long fpm(long long x, long long y) {
  long long s = 1;
  while (y) {
    if (y & 1) s = (s * x) % mo;
    y >>= 1, x = (x * x) % mo;
  }
  return s;
}
num operator+(num p, num q) { return num((p.a + q.a) % mo, (p.b + q.b) % mo); }
num operator-(num p, num q) {
  return num((p.a - q.a + mo) % mo, (p.b - q.b + mo) % mo);
}
num operator*(num p, long long r) { return num(p.a * r % mo, p.b * r % mo); }
num operator*(long long r, num p) { return num(p.a * r % mo, p.b * r % mo); }
num operator*(num p, num q) {
  return num((p.a * q.a + 5 * p.b % mo * q.b) % mo,
             (p.a * q.b + p.b * q.a) % mo);
}
num T(num p) {
  long long x = (5 * p.b % mo * p.b - p.a * p.a) % mo;
  if (x < 0) x += mo;
  x = fpm(x, mo - 2);
  return num((mo - p.a) * x % mo, p.b * x % mo);
}
num fpm(num x, long long y) {
  num s = num(1, 0);
  while (y) {
    if (y & 1) s = s * x;
    y >>= 1, x = x * x;
  }
  return s;
}
long long S(long long n) {
  int i, j;
  long long px, res = 0;
  num pr = num(1, 0), q, now, sum;
  for (i = 0; i <= k; i++) {
    sum = num(0, 0);
    for (j = 0; j <= i; j++) {
      px = (i - j) & 1 ? mo - C[i][j] : C[i][j];
      q = fpm(A, j) * fpm(B, i - j);
      if (q.a == 1 && q.b == 0)
        now = num(n, 0);
      else
        now = fpm(q, 3) * (fpm(q, n) - num(1, 0)) * T(q - num(1, 0));
      sum = sum + now * px;
    }
    sum = sum * F[k][i] * pr;
    res = (res + sum.a) % mo;
    pr = pr * num(0, I5);
  }
  for (i = 1; i <= k; i++) res = (res * fpm(i, mo - 2)) % mo;
  return res;
}
int main() {
  int i, j;
  I2 = fpm(2, mo - 2);
  I5 = fpm(5, mo - 2);
  A = num(I2, I2);
  B = num(I2, mo - I2);
  cin >> k >> l >> r;
  C[0][0] = 1;
  for (i = 1; i < 205; i++) {
    C[i][0] = C[i][i] = 1;
    for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mo;
  }
  F[0][0] = 1;
  for (i = 1; i < 205; i++)
    for (j = 0; j <= i; j++)
      (F[i][j] += F[i - 1][j] * (mo - i + 1) + F[i - 1][j - 1]) %= mo;
  ans = (S(r) - S(l - 1) + mo) % mo;
  cout << ans;
  return 0;
}
