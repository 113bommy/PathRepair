#include <bits/stdc++.h>
using namespace std;
const int N = 200;
const double pi = acos(-1.0);
int k;
long long l, r, c[220][220], s[220][220], invk = 1;
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return ans;
}
struct Complex {
  long long x, y;
  Complex(long long _x = 0, long long _y = 0) {
    x = _x;
    y = _y;
  }
};
Complex operator+(Complex a, Complex b) {
  return Complex((a.x + b.x) % 1000000007, (a.y + b.y) % 1000000007);
}
Complex operator-(Complex a, Complex b) {
  return Complex((a.x - b.x + 1000000007) % 1000000007,
                 (a.y - b.y + 1000000007) % 1000000007);
}
Complex operator*(Complex a, Complex b) {
  return Complex((a.x * b.x + a.y * b.y % 1000000007 * 5) % 1000000007,
                 (a.x * b.y + a.y * b.x) % 1000000007);
}
Complex operator/(Complex a, Complex b) {
  a = a * Complex(b.x, 1000000007 - b.y);
  b = b * Complex(b.x, 1000000007 - b.y);
  long long inv = qpow(b.x, 1000000007 - 2);
  a.x = a.x * inv % 1000000007;
  a.y = a.y * inv % 1000000007;
  return a;
}
Complex qpow(Complex a, long long y) {
  Complex ans = Complex(1, 0);
  while (y) {
    if (y & 1) ans = ans * a;
    a = a * a;
    y >>= 1;
  }
  return ans;
}
void init() {
  s[0][0] = 1;
  c[0][0] = 1;
  for (register int i = 1; i <= N; i++) {
    c[i][0] = 1;
    for (register int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
      s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * (i - 1)) % 1000000007;
    }
  }
  for (register int i = 1; i <= k; i++) invk = invk * i % 1000000007;
  invk = qpow(invk, 1000000007 - 2);
}
Complex calc(Complex a, long long n) {
  Complex tmp = Complex(1, 0);
  if ((a.x == 1) && (!a.y))
    return Complex((n + 1) % 1000000007, 0);
  else
    return (qpow(a, n + 1) - tmp) / (a - tmp);
}
long long solve(long long n) {
  Complex a = Complex(500000004, 500000004),
          b = Complex(500000004, 1000000007 - 500000004);
  long long ans = 0;
  for (register int i = 0; i <= k; i++) {
    long long now = s[k][i];
    if ((k - i) & 1) now = (1000000007 - now) % 1000000007;
    Complex sum = Complex(0, 0);
    for (register int j = 0; j <= i; j++) {
      Complex tmp1 = Complex(0, 0);
      if (j & 1)
        tmp1.x = 1000000007 - c[i][j];
      else
        tmp1.x = c[i][j];
      tmp1 = tmp1 * calc(qpow(b, j) * qpow(a, i - j), n);
      sum = sum + tmp1;
    }
    Complex inv = Complex();
    if (i & 1)
      inv.y = qpow(5, i / 2);
    else
      inv.x = qpow(5, i / 2);
    sum = sum / inv;
    ans = (ans + now * sum.x) % 1000000007;
  }
  ans = ans * invk % 1000000007;
  return ans;
}
int main() {
  scanf("%d%lld%lld", &k, &l, &r);
  init();
  printf("%lld", (solve(r + 2) - solve(l + 1) + 1000000007) % 1000000007);
  return 0;
}
