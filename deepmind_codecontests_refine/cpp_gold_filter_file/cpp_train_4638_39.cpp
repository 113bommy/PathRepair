#include <bits/stdc++.h>
using namespace std;
int n;
double x, y, z;
double X[10005], Y[10005], Z[10005];
double vp, vs;
int cmp(double A, double B) {
  return (A < B - 1e-12) ? -1 : ((A > B + 1e-12) ? 1 : 0);
}
double dist(double x, double y, double z, double x0, double y0, double z0) {
  return sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0) + (z - z0) * (z - z0));
}
int main() {
  int n;
  cin >> n;
  for (int i = (0); i < (n + 1); i++) cin >> X[i] >> Y[i] >> Z[i];
  cin >> vp >> vs;
  cin >> x >> y >> z;
  int i = 0;
  double tiempo = 0;
  while (i < n) {
    if (cmp(dist(X[i + 1], Y[i + 1], Z[i + 1], x, y, z) / vp,
            tiempo +
                dist(X[i], Y[i], Z[i], X[i + 1], Y[i + 1], Z[i + 1]) / vs) <= 0)
      break;
    tiempo += dist(X[i], Y[i], Z[i], X[i + 1], Y[i + 1], Z[i + 1]) / vs;
    i++;
  }
  if (i == n)
    printf("NO\n");
  else {
    double lo = 0.0, hi = 1.0, alfa, xo, yo, zo;
    double dx = X[i + 1] - X[i];
    double dy = Y[i + 1] - Y[i];
    double dz = Z[i + 1] - Z[i];
    while (lo + 1e-12 < hi) {
      alfa = (lo + hi) / 2.0;
      xo = X[i] + alfa * dx;
      yo = Y[i] + alfa * dy;
      zo = Z[i] + alfa * dz;
      if (cmp(dist(xo, yo, zo, x, y, z) / vp,
              tiempo + dist(X[i], Y[i], Z[i], xo, yo, zo) / vs) <= 0)
        hi = alfa;
      else
        lo = alfa;
    }
    printf("YES\n");
    alfa = (lo + hi) / 2.0;
    xo = X[i] + alfa * dx;
    yo = Y[i] + alfa * dy;
    zo = Z[i] + alfa * dz;
    printf("%.10lf\n", tiempo + dist(X[i], Y[i], Z[i], xo, yo, zo) / vs);
    printf("%.10lf %.10lf %.10lf\n", xo, yo, zo);
  }
  return 0;
}
