#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  char ch = getchar();
  int i = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    i = (i << 1) + (i << 3) + ch - '0';
    ch = getchar();
  }
  return i * f;
}
const int N = 2e5 + 50;
const double eps = 1e-5;
const double PI = acos(-1.0);
const double PI2 = PI * 2;
inline double fix(double x) {
  while (x < -PI) x += PI2;
  while (x > PI) x -= PI2;
  return x;
}
inline int sgn(double x) { return (x > eps) - (x < -eps); }
inline int cmp(double x, double y) { return sgn(x - y); }
double a[N * 2];
int n, tot;
inline int nxt(int i) { return (i == n) ? 2 : i + 1; }
struct P {
  double x, y;
  double slope;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  friend inline P operator-(const P &a, const P &b) {
    return P(a.x - b.x, a.y - b.y);
  }
  friend inline double operator*(const P &a, const P &b) {
    return a.x * b.y - a.y * b.x;
  }
  friend inline bool operator<(const P &a, const P &b) {
    return a.slope < b.slope;
  }
  friend inline bool left(const P &a, const P &b, const P &c) {
    return sgn((c - b) * (a - b)) >= 0;
  }
} p[N];
struct L {
  P a, b;
  double slope;
  L() {}
  L(P _a, P _b) {
    a = _a, b = _b;
    slope = atan2(b.y - a.y, b.x - a.x);
  }
  friend inline bool operator<(const L &a, const L &b) {
    if (cmp(a.slope, b.slope)) return a.slope < b.slope;
    return sgn((a.b - b.a) * (a.a - b.a)) < 0;
  }
  friend inline P inter(const L &a, const L &b) {
    double k1 = (a.b - b.a) * (a.a - b.a);
    double k2 = (a.a - b.b) * (a.b - b.b);
    double t = k1 / (k1 + k2);
    return P(b.a.x + (b.b.x - b.a.x) * t, b.a.y + (b.b.y - b.a.y) * t);
  }
} l[N * 2];
inline bool judge(const L &a, const L &b, const L &c) {
  P o = inter(a, b);
  return sgn((c.a - o) * (c.b - o)) <= 0;
}
inline double hpi() {
  sort(l + 1, l + tot + 1);
  n = 0;
  for (int i = 1; i <= tot; i++) {
    if (i == 1 || cmp(l[i].slope, l[i - 1].slope)) ++n;
    l[n] = l[i];
  }
  int L = 1, R = 2;
  for (int i = 3; i <= n; i++) {
    while (L < R && judge(l[R - 1], l[R], l[i])) --R;
    while (L < R && judge(l[L + 1], l[L], l[i])) ++L;
    l[++R] = l[i];
  }
  while (L < R + 1 && judge(l[L + 1], l[L], l[R])) ++L;
  while (L < R + 1 && judge(l[R], l[R - 1], l[L])) --R;
  n = 0;
  l[R + 1] = l[L];
  for (int i = L; i <= R; i++) p[++n] = inter(l[i], l[i + 1]);
  p[n + 1] = p[1];
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += p[i] * p[i + 1];
  return fabs(ans) / 2.0;
}
inline void solve() {
  n = rd();
  tot = 0;
  for (int i = 1; i <= n; i++) p[i].x = rd(), p[i].y = rd();
  for (int i = 2; i <= n; i++)
    p[i].slope = fix(atan2(p[i].y - p[1].y, p[i].x - p[1].x)),
    a[++tot] = p[i].slope, a[++tot] = fix(p[i].slope + PI);
  sort(p + 2, p + n + 1);
  sort(a + 1, a + tot + 1);
  for (int i = 1; i < tot; i++)
    if (cmp(a[i], a[i + 1]) == 0) {
      printf("%.10f\n", 0);
      return;
    }
  tot = 0;
  for (int p1 = 2, p2 = 3; p1 <= n;) {
    if (!left(p[1], p[p1], p[nxt(p1)])) {
      ++p1;
      p2 = nxt(p1);
      continue;
    }
    l[++tot] = L(p[p1], p[nxt(p1)]);
    while (nxt(p2) != p1 && left(p[1], p[p1], p[nxt(p2)])) p2 = nxt(p2);
    l[++tot] = L(p[p1], p[p2]);
    ++p1;
  }
  l[++tot] = L(P(1e6, 1e6), P(-1e6, 1e6));
  l[++tot] = L(P(-1e6, 1e6), P(-1e6, -1e6));
  l[++tot] = L(P(-1e6, -1e6), P(1e6, -1e6));
  l[++tot] = L(P(1e6, -1e6), P(1e6, 1e6));
  printf("%.10f\n", (double)hpi());
}
int main() {
  for (int T = rd(); T; T--) solve();
}
