#include <bits/stdc++.h>
template <typename T>
bool Chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool Chkmin(T &x, T y) {
  return y < x ? x = y, true : false;
}
const int MAXN = 2e3 + 1e3;
const double eps = 1e-12, PI = 3.1415926535897932;
int Dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct Line {
  double a, b, c;
  Line() {}
  Line(double a, double b, double c) : a(a), b(b), c(c) {}
  inline double F(double x) { return (a * x + c) / (-b); }
} a[MAXN];
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
} P[MAXN];
long long ans;
int n, m;
Point GetInter(Line l1, Line l2) {
  if (Dcmp(l1.b) == 0) std::swap(l1, l2);
  double x = (l2.b * l1.c / l1.b - l2.c) / (l2.a - l2.b * l1.a / l1.b);
  return Point(x, l1.F(x));
}
void Solve() {
  static double V[MAXN];
  int tot = 0;
  for (int i = 1, _ = n; i <= _; ++i)
    if (Dcmp(a[i].c) != 0) a[++tot] = a[i];
  ans += (long long)tot * ((long long)(n - tot) * ((n - tot) - 1) / 2);
  n = tot;
  for (int i = 1, _ = n; i <= _; ++i)
    P[i] = GetInter(a[i], Line(a[i].b, -a[i].a, 0));
  for (int i = 1, _ = n; i <= _; ++i) {
    tot = 0;
    for (int j = i + 1, _ = n; j <= _; ++j) {
      Point s = P[i] - P[j];
      V[++tot] = atan2(s.y, s.x);
      while (Dcmp(V[tot]) <= 0) V[tot] += PI;
    }
    std::sort(V + 1, V + tot + 1);
    int last = 0;
    for (int j = 1, _ = tot; j <= _; ++j)
      if (Dcmp(V[last + 1] - V[j]) != 0) {
        ans += ((long long)(j - last - 1) * ((j - last - 1) - 1) / 2);
        last = j - 1;
      }
    ans += ((long long)(tot - last) * ((tot - last) - 1) / 2);
  }
  printf("%lld\n", ans);
}
void Input() {
  scanf("%d", &n);
  for (int i = 1, _ = n; i <= _; ++i) {
    scanf("%lf%lf%lf", &a[i].a, &a[i].b, &a[i].c);
    a[i].c *= -1;
  }
}
int main() {
  if (fopen("D.in", "r") != NULL) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
  }
  Input();
  Solve();
  return 0;
}
