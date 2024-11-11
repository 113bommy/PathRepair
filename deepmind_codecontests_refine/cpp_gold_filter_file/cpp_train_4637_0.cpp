#include <bits/stdc++.h>
using namespace std;
int n;
int x[10003];
int y[10003];
int z[10003];
int vp, vs;
double start[10003];
int Px, Py, Pz;
double getdist(double x1, double y1, double z1, double x2, double y2,
               double z2) {
  x1 -= x2;
  y1 -= y2;
  z1 -= z2;
  return sqrt(x1 * x1 + y1 * y1 + z1 * z1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n + 1; i++) {
    scanf("%d%d%d", x + i, y + i, z + i);
  }
  scanf("%d%d", &vp, &vs);
  scanf("%d%d%d", &Px, &Py, &Pz);
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      start[i] = 0;
    } else {
      start[i] = start[i - 1] +
                 getdist(x[i - 1], y[i - 1], z[i - 1], x[i], y[i], z[i]) /
                     (double)vs * (double)vp;
    }
  }
  for (int i = 0; i < n; i++) {
    double px = x[i] - Px;
    double py = y[i] - Py;
    double pz = z[i] - Pz;
    double vx = x[i + 1] - x[i];
    double vy = y[i + 1] - y[i];
    double vz = z[i + 1] - z[i];
    double vsize = getdist(x[i], y[i], z[i], x[i + 1], y[i + 1], z[i + 1]) /
                   (double)vs * (double)vp;
    vx /= vsize;
    vy /= vsize;
    vz /= vsize;
    px -= vx * start[i];
    py -= vy * start[i];
    pz -= vz * start[i];
    double a = vx * vx + vy * vy + vz * vz - 1;
    double b = 2 * (px * vx + py * vy + pz * vz);
    double c = px * px + py * py + pz * pz;
    if (fabs(a) < 1e-9) {
      double x1 = -c / b;
      if (x1 >= start[i] - 1e-8 && x1 <= start[i + 1] + 1e-8) {
        printf("YES\n");
        printf("%.10f\n", x1 / vp);
        printf("%.10f %.10f %.10f\n", px + x1 * vx + Px, py + x1 * vy + Py,
               pz + x1 * vz + Pz);
        return 0;
      }
    } else {
      double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
      double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
      if (x2 < x1) {
        swap(x1, x2);
      }
      if (x1 >= start[i] - 1e-8 && x1 <= start[i + 1] + 1e-8) {
        printf("YES\n");
        printf("%.10f\n", x1 / vp);
        printf("%.10f %.10f %.10f\n", px + x1 * vx + Px, py + x1 * vy + Py,
               pz + x1 * vz + Pz);
        return 0;
      }
      if (x2 >= start[i] - 1e-8 && x2 <= start[i + 1] + 1e-8) {
        printf("YES\n");
        printf("%.10f\n", x2 / vp);
        printf("%.10f %.10f %.10f\n", px + x2 * vx + Px, py + x2 * vy + Py,
               pz + x2 * vz + Pz);
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
