#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool f = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? -x : x;
}
struct P {
  long long x, y;
  friend inline P operator-(const P &A, const P &B) {
    return (P){A.x - B.x, A.y - B.y};
  }
};
inline long long Cross(const P &A, const P &B) {
  return (A.x * B.y - B.x * A.y);
}
inline long long Area2(const P &A, const P &B, const P &C) {
  return abs(Cross(C - A, B - A));
}
const int N = 500010;
const long long mod = 1e9 + 7;
int n;
P p[N];
long long q[N];
long long now, s, ans;
long long x, y, xy, yx, x2, y2, xy2, yx2, X, Y, XY, XY2;
int main() {
  n = read();
  for (int i = (0), end_i = (n); i < end_i; i++)
    p[i].x = read(), p[i].y = read();
  for (int i = (1), end_i = (n - 1); i < end_i; i++)
    s += Area2(p[0], p[i], p[i + 1]);
  for (int i = (0), end_i = (n); i < end_i; i++)
    q[i] = (-p[i].x * p[(i + 1) % n].y + p[i].y * p[(i + 1) % n].x) % mod;
  for (int i = (0), end_i = (n - 1); i < end_i; i++) {
    (XY += q[i]) %= mod;
    X = (X + p[(i + 1) % n].x) % mod;
    Y = (Y + p[(i + 1) % n].y) % mod;
    (XY2 += XY) %= mod;
  }
  for (int i = 0, j = 0, k = 0, l = n - 1; i < n; i++) {
    for (; i == j || now + Area2(p[i], p[j], p[(j + 1) % n]) <= s / 2;
         now += Area2(p[i], p[j], p[(j + 1) % n]), j = (j + 1) % n) {
      (xy += q[j]) %= mod;
      x = (x + p[(j + 1) % n].x) % mod;
      y = (y + p[(j + 1) % n].y) % mod;
      (xy2 += xy) %= mod;
      ++k;
      X = (X - p[(j + 1) % n].x) % mod;
      Y = (Y - p[(j + 1) % n].y) % mod;
      (XY2 -= xy) %= mod;
      --l;
    }
    ans = (ans + (s % mod) * (k - l - 2) % mod +
           ((XY2 + p[i].x * Y - p[i].y * X) - (xy2 + p[i].x * y - p[i].y * x)) *
               2 % mod) %
          mod;
    now -= Area2(p[i], p[i + 1], p[j]);
    long long tmp = q[i];
    (xy -= tmp) %= mod;
    x = (x - p[(i + 1) % n].x) % mod;
    y = (y - p[(i + 1) % n].y) % mod;
    (xy2 -= tmp * k) %= mod;
    --k;
    XY = (XY - tmp) % mod;
    (XY2 -= tmp * l) %= mod;
    tmp = q[(i - 1 + n) % n];
    X = (X + p[i].x) % mod;
    Y = (Y + p[i].y) % mod;
    (XY += tmp) %= mod;
    (XY2 += XY) %= mod;
    ++l;
  }
  printf("%lld", (ans + mod) % mod * ((mod + 1) / 2) % mod);
  return 0;
}
