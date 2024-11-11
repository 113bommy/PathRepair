#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double pi = 3.1415926535897932384626;
map<int, int> exist[200402];
int bas = 100021;
struct point {
  double x, y;
  void in() {
    scanf("%lf%lf", &x, &y);
    exist[(int)x + bas][(int)y] = 1;
  }
  double dist() { return sqrt(x * x + y * y); }
};
point operator-(point a, point b) {
  a.x -= b.x, a.y -= b.y;
  return a;
}
point modify(double x, double y) {
  point p;
  p.x = x, p.y = y;
  return p;
}
double operator*(point a, point b) { return (a.x * b.x + a.y * b.y); }
double operator^(point a, point b) { return a.x * b.y - a.y * b.x; }
point pts[132];
int n;
double lastcover(point x) {
  double ct = 1e9;
  for (int i = 1; i <= n; i++) ct = min(ct, (x - pts[i]).dist());
  return ct;
}
double angle(point a, point b) { return acos((a * b) / a.dist() / b.dist()); }
point xin(point a, point b, point c) {
  double xa = a.x, xb = b.x, xc = c.x, ya = a.y, yb = b.y, yc = c.y;
  double x1 = xa, y1 = ya, x2 = xb, y2 = yb, x3 = xc, y3 = yc;
  double d = 2 * (xa - xb) * (yc - yb) - 2 * (ya - yb) * (xc - xb);
  double x = (yc - yb) * (xa * xa + ya * ya - xb * xb - yb * yb) -
             (ya - yb) * (xc * xc + yc * yc - xb * xb - yb * yb);
  double y = (xa - xb) * (xc * xc + yc * yc - xb * xb - yb * yb) -
             (xc - xb) * (xa * xa + ya * ya - xb * xb - yb * yb);
  return modify(x / d, y / d);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) pts[i].in();
  double nowans = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) {
        if (i == j or j == k or i == k) continue;
        double a1, a2, a3;
        a1 = (pts[i] - pts[j]).dist();
        a2 = (pts[i] - pts[k]).dist();
        a3 = (pts[k] - pts[j]).dist();
        if (((pts[j] - pts[i]) ^ (pts[k] - pts[i])) < eps and
            fabs(a2 * a2 - a3 * a3 + a1 * a1) < eps) {
          if (exist[(int)(pts[j].x + pts[k].x - pts[i].x + bas)]
                   [(int)(pts[j].y + pts[k].y - pts[i].y)])
            if (lastcover(modify((pts[j].x + pts[k].x) / 2,
                                 (pts[j].y + pts[k].y) / 2)) >
                (modify((pts[j].x + pts[k].x) / 2, (pts[j].y + pts[k].y) / 2) -
                 pts[i])
                        .dist() -
                    eps)
              nowans =
                  max(nowans, lastcover(modify((pts[j].x + pts[k].x) / 2,
                                               (pts[j].y + pts[k].y) / 2)));
        } else if (a1 * a1 + a2 * a2 - a3 * a3 > eps and
                   a1 * a1 + a3 * a3 - a2 * a2 > eps and
                   a2 * a2 + a3 * a3 - a1 * a1 > eps)
          if (lastcover(xin(pts[i], pts[j], pts[k])) >
              (xin(pts[i], pts[j], pts[k]) - pts[i]).dist() - eps)
            nowans = max(nowans, lastcover(xin(pts[i], pts[j], pts[k])));
      }
  if (nowans < eps)
    cout << -1;
  else
    printf("%.12lf\n", nowans);
  return 0;
}
