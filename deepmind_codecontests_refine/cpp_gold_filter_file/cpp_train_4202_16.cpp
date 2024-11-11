#include <bits/stdc++.h>
using namespace std;
double solve(double x, double a) {
  double x0 = 0;
  bool isneg = (x <= 0);
  if (isneg) x = a - x;
  int q = (x / a);
  double r = x - q * a;
  x = r;
  if ((q % 2) == 0) {
    x0 = x;
  } else {
    x0 = a - x;
  }
  if (isneg) x0 = a - x0;
  return x0;
}
bool eq(double a, double b) { return abs(a - b) <= 1E-10; }
int main() {
  double a, b, m;
  cin >> a >> b >> m;
  double vx, vy, vz;
  cin >> vx >> vy >> vz;
  double sx = a / 2, sy = m, sz = 0;
  double t = (-m) / vy;
  double x = sx + t * vx;
  double y = sy + t * vy;
  double z = sz + t * vz;
  assert(eq(y, 0));
  double x0, z0;
  {
    x0 = solve(x, a);
    z0 = solve(z, b);
  }
  {}
  cout << fixed << setprecision(10) << x0 << " " << z0 << endl;
}
