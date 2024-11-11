#include <bits/stdc++.h>
using namespace std;
struct pt {
  double x, y, z;
};
pt* mas;
int n;
const double eps = 1e-6;
double dist2(double x, double y, double z, pt a) {
  return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z);
}
double distmax(double x, double y, double z) {
  double md = 0, mi;
  for (int i = 0; i < n; ++i)
    if (dist2(x, y, z, mas[i]) > md) {
      mi = i;
      md = dist2(x, y, z, mas[i]);
    }
  return md;
}
double tern_z(double x, double y) {
  double zl = -1e4, zr = 1e4, tmp, p1, p2;
  while (zr - zl > eps) {
    tmp = (zr - zl) / 3;
    p1 = zl + tmp;
    p2 = zr - tmp;
    if (distmax(x, y, p1) < distmax(x, y, p2))
      zr = p2;
    else
      zl = p1;
  }
  return zl;
}
double tern_y(double x) {
  double yl = -1e4, yr = 1e4, tmp, p1, p2;
  while (yr - yl > eps) {
    tmp = (yr - yl) / 3;
    p1 = yl + tmp;
    p2 = yr - tmp;
    if (distmax(x, p1, tern_z(x, p1)) < distmax(x, p2, tern_z(x, p2)))
      yr = p2;
    else
      yl = p1;
  }
  return yl;
}
double tern_x() {
  double xl = -1e4, xr = 1e4, tmp, p1, p2;
  while (xr - xl > eps) {
    tmp = (xr - xl) / 3;
    p1 = xl + tmp;
    p2 = xr - tmp;
    if (distmax(p1, tern_y(p1), tern_z(p1, tern_y(p1))) <
        distmax(p2, tern_y(p2), tern_z(p2, tern_y(p2))))
      xr = p2;
    else
      xl = p1;
  }
  return xl;
}
int main() {
  scanf("%d", &n);
  mas = new pt[n];
  for (int i = 0; i < n; ++i)
    scanf("%lf%lf%lf", &mas[i].x, &mas[i].y, &mas[i].z);
  double x = tern_x();
  double y = tern_y(x);
  double z = tern_z(x, y);
  printf("%.6lf %.6lf %.6lf", x, y, z);
  return 0;
}
