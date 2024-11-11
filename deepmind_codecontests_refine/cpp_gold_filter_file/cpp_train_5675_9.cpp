#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double x, y;
double v, t;
double vx, vy, wx, wy;
bool can(double T) {
  double windX = vx * min(t, T) + wx * max(0.0, T - t);
  double windY = vy * min(t, T) + wy * max(0.0, T - t);
  double VX = (x - windX) / T;
  double VY = (y - windY) / T;
  return (VX * VX + VY * VY <= v * v);
}
int main() {
  double x_ziel, y_ziel;
  cin >> x >> y >> x_ziel >> y_ziel;
  x = x_ziel - x;
  y = y_ziel - y;
  cin >> v >> t;
  cin >> vx >> vy >> wx >> wy;
  double left = eps, right = 1.0 / eps;
  while (right - left > eps) {
    double m = (left + right) / 2.0;
    if (can(m))
      right = m;
    else
      left = m;
  }
  printf("%.8lf", (left + right) / 2.0);
  return 0;
}
