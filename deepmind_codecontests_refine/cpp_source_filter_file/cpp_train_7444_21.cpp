#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
const int maxn = 1e5 + 10;
struct Point {
  long double x, y;
  Point(long double a = 0, long double b = 0) : x(a), y(b) {}
} p[maxn];
int tot, n;
long double P, Q;
Point st[maxn];
int top;
long double cross(Point p0, Point p1, Point p2) {
  Point a = Point(p1.x - p0.x, p1.y - p0.y);
  Point b = Point(p2.x - p0.x, p2.y - p0.y);
  return a.x * b.y - a.y * b.x;
}
int sgn(long double x) { return (x > eps) - (x < -eps); }
long double dis(Point a, Point b) {
  return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}
bool cmp1(Point a, Point b) {
  if (sgn(a.x - b.x) == 0) return a.y < b.y;
  return a.x < b.x;
}
bool cmp(Point a, Point b) {
  int t = sgn(cross(p[0], a, b));
  if (t == 0) return sgn(dis(p[0], a) - dis(p[0], b)) < 0;
  return t > 0;
}
void solve() {
  sort(p, p + tot, cmp1);
  sort(p + 1, p + tot, cmp);
  top = -1;
  for (int i = 0; i < tot; i++) {
    while (top >= 2 && sgn(cross(st[top - 1], st[top], p[i])) < 0) top--;
    st[++top] = p[i];
  }
  st[top + 1] = st[0];
  long double res = 1e30;
  for (int i = 0; i <= top; i++) {
    if (sgn(cross(st[i], Point(0, 0), Point(P, Q))) *
            sgn(cross(st[i + 1], Point(0, 0), Point(P, Q))) <=
        0) {
      long double s1 = cross(st[i], Point(P, Q), st[i + 1]);
      long double s2 = cross(Point(0, 0), st[i], st[i + 1]);
      res = min(res, (s1 + s2 + 0.0) / s2);
    }
  }
  cout << setiosflags(ios::fixed);
  cout << setprecision(10) << res << endl;
}
int main() {
  cin >> n >> P >> Q;
  long double x, y;
  long double Mx = 0, My = 0;
  tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p[tot++] = Point(x, y);
    Mx = max(Mx, x);
    My = max(My, y);
  }
  p[tot++] = Point(0, My);
  p[tot++] = Point(Mx, 0);
  solve();
  return 0;
}
