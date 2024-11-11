#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
struct Circle {
  double x;
  double y;
  double r;
};
double c[12] = {0.0, 0.0,         0.0, 1.0 / 6.0,     0.0, 3.0 / 40.0,
                0.0, 5.0 / 112.0, 0.0, 35.0 / 1152.0, 0.0, 63.0 / 2816.0};
double half(double x, double y, double r1, double r2) {
  double l = sqrt(x * x + y * y);
  double v = (r1 * r1 - r2 * r2 + x * x + y * y) / (2.0 * l);
  double a = 0.0;
  if (sqrt(2.0) * x < r1) {
    a = acos(v / r1);
  } else {
    double s = sqrt(((r1 + r2) * (r1 + r2) - x * x - y * y) *
                    (x * x + y * y - (r1 - r2) * (r1 - r2))) /
               4.0;
    double u = 2.0 * s / l;
    if (u / r1 < 0.1) {
      double A = 1.0;
      double B = 2.0 * (u / r1) * (v / r1);
      double w = 0.0;
      for (int i = 0; i < 12; i++) {
        w += A * c[i];
        A *= B;
      }
      return r1 * r1 * w * 0.5;
    } else {
      a = asin(u / r1);
    }
  }
  return r1 * r1 * (2 * a - sin(2 * a)) * 0.5;
}
double calc(Circle c1, Circle c2) {
  c2.x -= c1.x;
  c2.y -= c1.y;
  c1.x = 0;
  c1.y = 0;
  if ((c1.r + c2.r) * (c1.r + c2.r) - (c2.x * c2.x + c2.y * c2.y) < EPS) {
    return 0.0;
  } else if ((c2.x * c2.x + c2.y * c2.y) - (c2.r - c1.r) * (c2.r - c1.r) <
             EPS) {
    return min(c1.r, c2.r) * min(c1.r, c2.r) * PI;
  } else {
    double ret = half(c2.x, c2.y, c1.r, c2.r) + half(c2.x, c2.y, c2.r, c1.r);
    return ret;
  }
}
int main() {
  Circle b[2];
  for (int i = 0; i < 2; i++) {
    cin >> b[i].x >> b[i].y >> b[i].r;
  }
  printf("%.10f\n", calc(b[0], b[1]));
  return 0;
}
