#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
double t1, t2, cx, cy, sx, sy, hx, hy, cs, ch, sh;
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool circle_inter_point(double x1, double y1, double r1, double x2, double y2,
                        double r2, double &rx1, double &ry1, double &rx2,
                        double &ry2) {
  double vx = x2 - x1, vy = y2 - y1;
  double d = dist(x1, y1, x2, y2);
  if (d > r1 + r2 + eps) return false;
  if (d < r1 - r2 + eps) {
    rx1 = x2 - r2, ry1 = y2;
    rx2 = x2 + r2, ry2 = y2;
    return true;
  } else if (d < r2 - r1 + eps) {
    rx1 = x1 - r1, ry1 = y1;
    rx2 = x1 + r1, ry2 = y1;
    return true;
  }
  vx = vx / d * r1, vy = vy / d * r1;
  double cosa = min(1.0 - eps, (r1 * r1 + d * d - r2 * r2) / r1 / d / 2);
  double sina = sqrt(1 - cosa * cosa);
  rx1 = x1 + vx * cosa - vy * sina, ry1 = y1 + vx * sina + vy * cosa;
  rx2 = x1 + vx * cosa + vy * sina, ry2 = y1 - vx * sina + vy * cosa;
  return true;
}
bool in_circle(double x, double y, double r, double x0, double y0) {
  return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r + eps;
}
bool circle_inter(double x1, double y1, double r1, double x2, double y2,
                  double r2, double x3, double y3, double r3) {
  double rx1, ry1, rx2, ry2;
  if (r1 < 0 || r2 < 0 || r3 < 0) return false;
  if (circle_inter_point(x1, y1, r1, x2, y2, r2, rx1, ry1, rx2, ry2)) {
    if (in_circle(x3, y3, r3, rx1, ry1)) return true;
    if (in_circle(x3, y3, r3, rx2, ry2)) return true;
  }
  if (circle_inter_point(x1, y1, r1, x3, y3, r3, rx1, ry1, rx2, ry2)) {
    if (in_circle(x2, y2, r2, rx1, ry1)) return true;
    if (in_circle(x2, y2, r2, rx2, ry2)) return true;
  }
  if (circle_inter_point(x2, y2, r2, x3, y3, r3, rx1, ry1, rx2, ry2)) {
    if (in_circle(x1, y1, r1, rx1, ry1)) return true;
    if (in_circle(x1, y1, r1, rx2, ry2)) return true;
  }
  return false;
}
int main() {
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &t1, &t2, &cx, &cy, &hx, &hy, &sx, &sy);
  cs = dist(cx, cy, sx, sy), ch = dist(cx, cy, hx, hy),
  sh = dist(sx, sy, hx, hy);
  if (cs + sh <= ch + t2) {
    printf("%.18lf\n", min(cs + sh + t1, ch + t2));
  } else {
    double begin = 0, end = min(cs + t1, ch + t2), mid;
    while (begin + eps < end) {
      mid = (begin + end) / 2;
      if (circle_inter(cx, cy, mid, sx, sy, cs + t1 - mid, hx, hy,
                       ch + t2 - mid)) {
        begin = mid;
      } else {
        end = mid;
      }
    }
    printf("%.18lf\n", begin);
  }
  return 0;
}
