#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int N = 2010;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  void print() {}
} p;
struct Line {
  double a, b, c;
  void in() { scanf("%lf%lf%lf", &a, &b, &c); }
} a[N], l1[N], l2[N];
inline double square(const Point &a) { return a.x * a.x + a.y * a.y; }
inline int sig(const double &a) {
  if (a > eps) return 1;
  if (a < -eps) return -1;
  return 0;
}
void zu(Line l, Point &p) {
  if (l.a == 0 && l.b == 0) {
    p.x = p.y = 0;
    return;
  }
  if (l.a == 0) {
    p.x = 0, p.y = l.c / l.b;
    return;
  }
  if (l.b == 0) {
    p.x = l.c / l.a, p.y = 0;
    return;
  }
  p.y = l.c * l.b / (l.b * l.b + l.a * l.a);
  p.x = l.c * l.a / (l.b * l.b + l.a * l.a);
}
Point b[N], c[N];
inline double xmul(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline int quadrant(const Point &a) {
  const int ans[3][3] = {{4, 3, 2}, {5, 0, 1}, {6, 7, 8}};
  return ans[1 - sig(a.y)][sig(a.x) + 1];
}
inline bool cmpp(const Point &a, const Point &b) {
  int p = quadrant(a), q = quadrant(b);
  if (p != q) return p < q;
  double x = xmul(a, b);
  if (sig(x)) return x > 0;
  return square(a) < square(b);
}
inline bool operator==(const Point &a, const Point &b) {
  return sig(a.x - b.x) == 0 && sig(a.y - b.y) == 0;
}
int vis[N];
int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  int cc = 0, nn = 0;
  for (int i = 0; i < n; i++) {
    a[i].in();
    if (sig(a[i].c) == 0)
      l2[cc++] = a[i];
    else
      l1[nn++] = a[i];
  }
  n = cc;
  cc = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      cc++;
      for (int j = i + 1; j < n; j++) {
        if (sig(l2[i].a * l2[j].b - l2[i].b * l2[j].a) == 0 &&
            sig(l2[i].a * l2[j].c - l2[i].c * l2[j].a) == 0)
          vis[j] = 1;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  ans = 1ll * nn * cc * (cc - 1) / 2 * 3;
  n = nn;
  nn = 0;
  for (int i = 0; i < n; i++) a[i] = l1[i];
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      l1[nn++] = a[i];
      for (int j = i + 1; j < n; j++) {
        if (sig(a[i].a * a[j].b - a[i].b * a[j].a) == 0 &&
            sig(a[i].a * a[j].c - a[i].c * a[j].a) == 0)
          vis[j] = 1;
      }
    }
  }
  n = nn;
  for (int i = 0; i < n; i++) {
    a[i] = l1[i];
    zu(a[i], b[i]);
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0, tp = 0;
    Point yd = Point(-b[i].x, -b[i].y);
    for (int j = 0; j < n; j++)
      if (i != j) {
        Point tmp = Point(b[j].x - b[i].x, b[j].y - b[i].y);
        if (sig(tmp.y) < 0) tmp.x = -tmp.x, tmp.y = -tmp.y;
        if (!sig(tmp.y) && !sig(tmp.x)) {
          tp++;
          continue;
        }
        if (sig(tmp.y) == 0 && sig(tmp.x) < 0) tmp.x = -tmp.x;
        c[cnt++] = tmp;
      }
    sort(c, c + cnt, cmpp);
    int now = 1;
    for (int j = 1; j < cnt; j++) {
      if (sig(xmul(c[j], c[j - 1])) == 0) {
        now++;
      } else {
        if (sig(xmul(yd, c[j - 1])) != 0)
          ans = (ans + 1ll * now * (now - 1) / 2);
        now = 1;
      }
    }
    if (sig(xmul(yd, c[cnt - 1])) != 0) ans = (ans + 1ll * now * (now - 1) / 2);
  }
  ans = ans / 3;
  printf("%I64d\n", ans);
}
