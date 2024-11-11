#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, m, vx, vy, vz;
  cin >> a >> b >> m >> vx >> vy >> vz;
  double t = -m / (double)vy;
  double x = vx * t + 1000000.5 * a;
  double z = vz * t;
  z = z - (int)(z / 2 / b) * 2 * b;
  x = x - (int)(x / 2 / a) * 2 * a;
  if (x > a) x = 2 * a - x;
  if (z > b) z = 2 * b - z;
  printf("%.8lf %.8lf\n", x, z);
  return 0;
}
