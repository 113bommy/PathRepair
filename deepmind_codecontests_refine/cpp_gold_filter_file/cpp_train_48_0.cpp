#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 1e2 + 5, M = 3e3 + 5, P = 1e9 + 7;
int n, m, a[N], b[N], p[M];
long long ca[M], cb[M], ans;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long exgcd(long long a, long long b, long long &x, long long &y,
                long long d = 0) {
  return b ? (d = exgcd(b, a % b, y, x), y -= a / b * x, d) : (x = 1, y = 0, a);
}
long long qpow(long long a, long long b) {
  long long c = 1;
  for (; b; b >>= 1, a = a * a % P)
    if (b & 1) c = c * a % P;
  return c;
}
int lg(int a, int b) {
  int c = 0;
  for (; b % a == 0; ++c, b /= a)
    ;
  return c;
}
void work(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0)
      for (p[++m] = i; n % i == 0; n /= i)
        ;
  if (n != 1) p[++m] = n;
}
long long solve(long long A, long long B, long long C) {
  if (!A) return 0;
  if (!B) return C / A;
  long long x, y, d;
  exgcd(A, -B, x, y);
  x *= C, y *= -C, x %= -B, x += -B, x %= -B, y = (C - A * x) / B;
  if (y < 0) d = (-y + A - 1) / A, x += -B * d, y += A * d;
  return x;
}
void work(int a, int b) {
  bool fl1 = false, fl2 = false;
  long long x, y, A, B, C;
  for (int i = 1; i <= m; ++i) {
    long long _A = cb[i], _B = -lg(p[i], b), _C = lg(p[i], a) - ca[i],
              d = gcd(_A, -_B);
    if (!_A && !_B)
      (_C) ? (puts("-1"), exit(0)) : void();
    else {
      (_C % d) ? (puts("-1"), exit(0)) : void(), _A /= d, _B /= d, _C /= d;
      if (fl2)
        (_A * x + _B * y != _C) ? (puts("-1"), exit(0)) : void();
      else if (!fl1)
        fl1 = true, A = _A, B = _B, C = _C;
      else if (_A == A && _B == B)
        (_C != C) ? (puts("-1"), exit(0)) : void();
      else {
        long long a = _A * B - _B * A, b = _C * B - _B * C;
        (b % a) ? (puts("-1"), exit(0)) : void(), x = b / a;
        a = _B * A - B * _A, b = _C * A - C * _A;
        (b % a) ? (puts("-1"), exit(0)) : void(), y = b / a;
        fl2 = true, (x < 0 || y < 0) ? (puts("-1"), exit(0)) : void();
      }
    }
  }
  if (fl2)
    for (int i = 1; i <= m; ++i) ca[i] += x * cb[i], cb[i] = 0;
  else {
    long long x = solve(A, B, C);
    for (int i = 1; i <= m; ++i) ca[i] += x * cb[i], cb[i] *= -B;
  }
}
int main() {
  n = read(), ans = 1;
  for (int i = 1; i <= n; ++i)
    a[i] = read(), b[i] = read(), work(a[i]), work(b[i]);
  sort(p + 1, p + 1 + m), m = unique(p + 1, p + 1 + m) - p - 1;
  for (int i = 1; i <= m; ++i) ca[i] = lg(p[i], a[1]), cb[i] = lg(p[i], b[1]);
  for (int i = 2; i <= n; ++i) work(a[i], b[i]);
  for (int i = 1; i <= m; ++i) ans = ans * qpow(p[i], ca[i]) % P;
  printf("%lld\n", ans);
  return 0;
}
