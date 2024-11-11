#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535;
int main() {
  int a, b, m;
  cin >> a >> b >> m;
  int vx, vy, vz;
  cin >> vx >> vy >> vz;
  double t = (double)m / (-vy);
  double x = (double)a / 2 + t * vx;
  double z = t * vz;
  while (z < 0) z += 2 * b;
  while (z > 2 * b) z -= 2 * b;
  if (x > b) z = 2 * b - z;
  while (x < 0) x += 2 * a;
  while (x > 2 * a) x -= 2 * a;
  if (x > a) x = 2 * a - x;
  printf("%.10f %.10f\n", x, z);
  return 0;
}
