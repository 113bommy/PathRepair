#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double EPS = 1e-9;
const int IT = 1000;
double f(double T, double X1, double Y1, double X2, double Y2, double XU,
         double YU, double V) {
  X1 += T * XU;
  Y1 += T * YU;
  double dx = X1 - X2;
  double dy = Y1 - Y2;
  return max(0., sqrt(dx * dx + dy * dy) - T * V);
}
double g(double T, double X1, double Y1, double X2, double Y2, double XU,
         double YU, double XW, double YW, double V, double ST) {
  X1 += ST * XU + (T - ST) * XW;
  Y1 += ST * YU + (T - ST) * YW;
  double dx = X1 - X2;
  double dy = Y1 - Y2;
  return max(0., sqrt(dx * dx + dy * dy) - T * V);
}
double X1, Y1, X2, Y2, V, T, XU, YU, XW, YW;
void solve() {
  double L = 0, R = T;
  for (int it = 0; it < IT; it++) {
    double M1 = L + (R - L) / 3;
    double M2 = R - (R - L) / 3;
    double f1 = f(M1, X1, Y1, X2, Y2, XU, YU, V);
    double f2 = f(M2, X1, Y1, X2, Y2, XU, YU, V);
    if (f1 - 1e-12 < f2) {
      R = M2;
    } else {
      L = M1;
    }
  }
  double T1 = L;
  if (fabs(f(T1, X1, Y1, X2, Y2, XU, YU, V)) < EPS) {
    printf("%.12lf\n", T1);
  } else {
    L = T;
    R = 1e9;
    for (int it = 0; it < IT; it++) {
      double M1 = L + (R - L) / 3;
      double M2 = R - (R - L) / 3;
      double f1 = g(M1, X1, Y1, X2, Y2, XU, YU, XW, YW, V, T);
      double f2 = g(M2, X1, Y1, X2, Y2, XU, YU, XW, YW, V, T);
      if (f1 - 1e-12 < f2) {
        R = M2;
      } else {
        L = M1;
      }
    }
    printf("%.12lf\n", L);
  }
}
int main() {
  while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &X1, &Y1, &X2, &Y2,
               &V, &T, &XU, &YU, &XW, &YW) == 10) {
    solve();
  }
}
