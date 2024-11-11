#include <bits/stdc++.h>
using namespace std;
double SqrDist(double a[2]) { return a[0] * a[0] + a[1] * a[1]; }
double SqrDist(double a[2], double b[2]) {
  return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}
double SqrDist(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void GetCenter(double x[3], double y[3], double o[2]) {
  o[0] = o[1] = 0.0;
  double u[2], v[2], a[2], b[2], c[2];
  u[0] = x[0] - x[1], u[1] = y[0] - y[1];
  v[0] = x[2] - x[1], v[1] = y[2] - y[1];
  a[0] = x[1], a[1] = y[1];
  b[0] = x[0], b[1] = y[0];
  c[0] = x[2], c[1] = y[2];
  double p = SqrDist(u);
  double q = SqrDist(v);
  double r =
      2.0 * ((b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]));
  o[0] = a[0] - ((b[1] - a[1]) * q - (c[1] - a[1]) * p) / r;
  o[1] = a[1] + ((b[0] - a[0]) * q - (c[0] - a[0]) * p) / r;
}
int main() {
  double x[3], y[3], c[2];
  while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]) {
    GetCenter(x, y, c);
    double d[3];
    d[0] = SqrDist(c[0], c[1], x[0], y[0]);
    d[1] = SqrDist(c[0], c[1], x[1], y[1]);
    d[2] = SqrDist(c[0], c[1], x[2], y[2]);
    double r = sqrt(d[0]);
    double g[3];
    g[0] = SqrDist(x[0], y[0], x[1], y[1]);
    g[1] = SqrDist(x[1], y[1], x[2], y[2]);
    g[2] = SqrDist(x[2], y[2], x[0], y[0]);
    double ans = 1e30;
    for (int n = 3; n <= 100; n++) {
      double s[101][2];
      double ad = 2.0 * acos(-1.0) / ((double)n);
      for (int i = 0; i < n; i++) {
        s[i][0] = r * cos(ad * i);
        s[i][1] = r * sin(ad * i);
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (j != i) {
            for (int k = 0; k < n; k++) {
              if (k != i && k != j) {
                double h[3];
                h[0] = SqrDist(s[i], s[j]);
                h[1] = SqrDist(s[j], s[k]);
                h[2] = SqrDist(s[k], s[i]);
                if (fabs(g[0] - h[0]) <= 1e-2 && fabs(g[1] - h[1]) <= 1e-2 &&
                    fabs(g[2] - h[2]) <= 1e-2) {
                  double ar = s[0][0] * s[1][1] - s[0][1] * s[1][0];
                  ar *= n;
                  ar /= 2.0;
                  ans = min(ar, ans);
                }
              }
            }
          }
        }
      }
    }
    printf("%.8lf\n", ans);
  }
}
