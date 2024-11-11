#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9, beps = 1e-9;
int x[10005], y[10005], z[10005];
int vs, vp, ig;
double sum;
double timego(double xc1, double yc1, double zc1, double xcur, double ycur,
              double zcur, double vcur) {
  double vsp =
      sqrt(double((xcur - xc1) * (xcur - xc1) + (ycur - yc1) * (ycur - yc1) +
                  (zcur - zc1) * (zcur - zc1)));
  vsp /= vcur * 1.0;
  return vsp;
}
double dist(double x2, double y2, double z2, double x3, double y3, double z3) {
  return sqrt(double((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) +
                     (z3 - z2) * (z3 - z2)));
}
void getans(double xs, double ys, double zs, double lx, double ly, double lz,
            double rx, double ry, double rz) {
  double midx = (lx + rx) / 2.0;
  double midy = (ly + ry) / 2.0;
  double midz = (lz + rz) / 2.0;
  while (dist(lx, ly, lz, rx, ry, rz) > beps) {
    if (timego(xs, ys, zs, midx, midy, midz, vp) <
        sum + timego(x[ig], y[ig], z[ig], midx, midy, midz, vs) + eps) {
      rx = midx;
      ry = midy;
      rz = midz;
    } else {
      lx = midx;
      ly = midy;
      lz = midz;
    }
    midx = (lx + rx) / 2.0;
    midy = (ly + ry) / 2.0;
    midz = (lz + rz) / 2.0;
  }
  printf("\n%.10lf", timego(xs, ys, zs, midx, midy, midz, vp));
  printf("\n%.10lf %.10lf %.10lf", rx, ry, rz);
}
int main() {
  int n, i, xs, ys, zs;
  scanf("%d", &n);
  for (i = 0; i < n + 1; i++) {
    scanf("%d%d%d", &x[i], &y[i], &z[i]);
  }
  scanf("%d%d", &vp, &vs);
  scanf("%d%d%d", &xs, &ys, &zs);
  if ((xs == x[0]) && (ys == y[0]) && (zs == z[0])) {
    printf("YES");
    printf("\n0.0000000000");
    printf("\n%d %d %d", xs, ys, zs);
    return 0;
  }
  sum = 0;
  for (i = 1; i < n + 1; i++) {
    if (timego(xs, ys, zs, x[i], y[i], z[i], vp) <
        sum + timego(x[i - 1], y[i - 1], z[i - 1], x[i], y[i], z[i], vs) +
            eps) {
      printf("YES");
      ig = i - 1;
      getans(xs, ys, zs, x[i - 1], y[i - 1], z[i - 1], x[i], y[i], z[i]);
      return 0;
    }
    sum += timego(x[i - 1], y[i - 1], z[i - 1], x[i], y[i], z[i], vs);
  }
  printf("NO");
  return 0;
}
