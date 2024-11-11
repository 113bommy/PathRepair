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
const long double eps = 1e-12, PI = 3.1415926535897932;
int Dcmp(long double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct Line {
  long double a, b, c;
  Line() {}
  Line(long double a, long double b, long double c) : a(a), b(b), c(c) {}
  inline long double F(long double x) { return -(a * x + c) / b; }
} a[MAXN];
struct Point {
  long double x, y;
  Point() {}
  Point(long double x, long double y) : x(x), y(y) {}
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
} P[MAXN];
long long ans;
int n, m;
Point GetInter(Line l1, Line l2) {
  if (Dcmp(l1.b) == 0) std::swap(l1, l2);
  long double x = (l2.b * l1.c / l1.b - l2.c) / (l2.a - l2.b * l1.a / l1.b);
  return Point(x, l1.F(x));
}
void Solve() {
  static long double V[MAXN];
  int tot = 0;
  for (int i = 1, _ = n; i <= _; ++i)
    if (a[i].c != 0) a[++tot] = a[i];
  ans += (long long)tot * ((long long)(n - tot) * ((n - tot) - 1) / 2);
  n = tot;
  for (int i = 1, _ = n; i <= _; ++i)
    P[i] = GetInter(a[i], Line(a[i].b, -a[i].a, 0));
  for (int i = 1, _ = n; i <= _; ++i) {
    tot = 0;
    for (int j = i + 1, _ = n; j <= _; ++j) {
      ++tot;
      Point s = P[i] - P[j];
      if (Dcmp(s.x) == 0)
        V[tot] = 1e50;
      else
        V[tot] = s.y / s.x;
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
    std::cin >> a[i].a >> a[i].b >> a[i].c;
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
