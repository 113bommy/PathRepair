#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:50000000")
string problem_name = "a";
void init() { freopen((problem_name + ".in").c_str(), "rt", stdin); }
int main() {
  double a, b, m, vx, vy, vz;
  cin >> a >> b >> m >> vx >> vy >> vz;
  double t = -m / vy;
  double x = a / 2.;
  double t2 = t;
  if (t * abs(vx) <= x) {
    x += t * vx;
  } else {
    if (vx < 0)
      x = 0;
    else
      x = a;
    t -= (a / 2.) / abs(vx);
    vx = -vx;
    while (t * abs(vx) >= a) {
      t -= a / abs(vx);
      if (vx < 0)
        x -= a;
      else
        x += a;
      vx = -vx;
    }
    x += t * vx;
  }
  t = t2;
  double z = 0;
  if (vz < 0) vz = -vz;
  while (t * abs(vz) >= b) {
    t -= b / abs(vz);
    if (vz < 0)
      z -= b;
    else
      z += b;
    vz = -vz;
  }
  z += t * vz;
  printf("%.8lf %.8lf\n", x, z);
  return 0;
}
