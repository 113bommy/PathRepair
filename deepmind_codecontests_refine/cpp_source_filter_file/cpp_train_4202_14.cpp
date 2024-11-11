#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, m, vx, vy, vz;
  while (scanf("%lf%lf%lf", &a, &b, &m) != EOF) {
    scanf("%lf%lf%lf", &vx, &vy, &vz);
    vy = -vy;
    double x = m * vx / vy;
    double z = m * vz / vy;
    double x0 = a / 2.0 + x;
    double z0 = z;
    while (x0 < 0 || x0 > a) {
      if (x0 < 0) x0 = -x0;
      if (x0 > a) x0 = a * 2 - x0;
    }
    while (z0 < 0 || z0 > b) {
      if (z0 < 0) z0 = -z0;
      if (z0 > b) z0 = z0 - b;
    }
    printf("%.8lf %.8lf\n", x0, z0);
  }
  return 0;
}
