#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, -1, 1, 1, -1};
struct P {
  long double x, y;
  P() {}
  P(long double a, long double b) : x(a), y(b) {}
  P operator-(const P &other) const { return P(x - other.x, y - other.y); }
  long double dist(const P &other) const {
    return hypot(x - other.x, y - other.y);
  }
};
const int N = 1e5 + 4;
int d1, d2;
int n;
P a[N], b[N];
struct V {
  long double x, y;
  V() {}
  V(long double a, long double b) : x(a), y(b) {}
  V(P p) : x(p.x), y(p.y) {}
  V scale(long double s) { return V(x * s, y * s); }
};
V v1, v2;
P p1, p2;
long double f(long double x) {
  V t1, t2;
  t1 = v1.scale(x);
  t2 = v2.scale(x);
  P cur1, cur2;
  cur1 = {p1.x + t1.x, p1.y + t1.y};
  cur2 = {p2.x + t2.x, p2.y + t2.y};
  return cur1.dist(cur2);
}
long double ternaryS(long double st = 0.0, long double en = 1.0) {
  for (int i = 0; i < 50; i++) {
    long double md1 = st + (en - st) / 3;
    long double md2 = en - (en - st) / 3;
    if (f(md1) < f(md2))
      en = md2;
    else
      st = md1;
  }
  return f(st);
}
bool eq(long double a, long double b) { return fabs(a - b) <= 1e-9; }
int main() {
  scanf("%d", &n);
  scanf("%d %d", &d1, &d2);
  for (int i = 0; i < n; ++i) {
    int x1, yy1, x2, y2;
    scanf("%d %d %d %d", &x1, &yy1, &x2, &y2);
    a[i].x = x1, a[i].y = yy1, b[i].x = x2, b[i].y = y2;
  }
  long long ans = 0;
  bool f = true;
  long double lst;
  for (int i = 0; i + 1 < n; ++i) {
    v1 = a[i + 1] - a[i], v2 = b[i + 1] - b[i];
    p1 = a[i], p2 = b[i];
    long double smal = ternaryS();
    long double f1, f3;
    f1 = p1.dist(p2);
    f3 = a[i + 1].dist(b[i + 1]);
    f |= (f1 > d2);
    if (f && smal <= d1) ans++, f = false;
  }
  printf("%lld\n", ans);
}
