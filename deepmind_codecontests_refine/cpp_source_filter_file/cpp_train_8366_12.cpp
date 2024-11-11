#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  void in() { scanf("%lf%lf", &x, &y); }
  double dist() { return sqrt(x * x + y * y); }
};
map<point, int> exist;
bool operator<(point a, point b) {
  if (fabs(a.x - b.x) < 1e-6) return a.x < b.x;
  if (fabs(a.y - b.y) < 1e-6) return a.y < b.y;
  return 0;
}
point operator-(point a, point b) {
  a.x -= b.x, a.y -= b.y;
  return a;
}
point operator+(point a, point b) {
  a.x += b.x, a.y += b.y;
  return a;
}
double operator^(point a, point b) { return a.x * b.y - a.y * b.x; }
double operator*(point a, point b) { return a.x * b.x + a.y * b.y; }
point pts[65536 * 2];
double ans = -123;
int n;
double mindis(point o) {
  double res = 1e9;
  for (int i = 1; i <= n; i++) res = min(res, (o - pts[i]).dist());
  return res;
}
point center(point a, point b, point c) {
  double xa = a.x, xb = b.x, xc = c.x, ya = a.y, yb = b.y, yc = c.y;
  double x1 = xa, y1 = ya, x2 = xb, y2 = yb, x3 = xc, y3 = yc;
  double d = 2 * (xa - xb) * (yc - yb) - 2 * (ya - yb) * (xc - xb);
  double x = (yc - yb) * (xa * xa + ya * ya - xb * xb - yb * yb) -
             (ya - yb) * (xc * xc + yc * yc - xb * xb - yb * yb);
  double y = (xa - xb) * (xc * xc + yc * yc - xb * xb - yb * yb) -
             (xc - xb) * (xa * xa + ya * ya - xb * xb - yb * yb);
  point p;
  p.x = x / d, p.y = y / d;
  return p;
}
double angle(point a, point b) {
  if ((a * b) < -1e-6) return -1;
  if ((a * b) > 1e-6) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) pts[i].in(), exist[pts[i]] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (i == j or i == k or j == k) continue;
        point a = pts[i], b = pts[j], c = pts[k];
        if (angle(a - c, b - c) == 1 and angle(b - a, c - a) == 1 and
            angle(c - b, a - b) == 1) {
          point o = center(a, b, c);
          double d = mindis(o);
          if (d >= (b - o).dist()) ans = max(ans, d);
        }
        if (angle(b - a, c - a) == 0) {
          if (exist[b + c - a]) {
            point o = b + c;
            o.x /= 2, o.y /= 2;
            double d = mindis(o);
            if (d >= (b - o).dist()) ans = max(ans, d);
          }
        }
      }
    }
  }
  if (ans < 0)
    puts("-1");
  else
    printf("%.12lf\n", ans);
  return 0;
}
