#include <bits/stdc++.h>
using namespace std;
int main() {
  long double a, b, m, vx, vy, vz;
  long double dx, dy, dz;
  cin >> a >> b >> m >> vx >> vy >> vz;
  long double finalx, finaly, finalz;
  finaly = 0;
  dy = -m / vy;
  finalx = a / 2 + dy * vx;
  finalz = vz * dy;
  while (finalx < 0 || finalz < 0 || finalx > a || finalz > b) {
    if (finalx < 0) {
      finalx *= -1;
      continue;
    }
    if (finalz < 0) {
      finalz *= -1;
      continue;
    }
    if (finalx > a) {
      finalx = 2 * a - finalx;
      continue;
    }
    if (finalz > b) {
      finalz = 2 * b - finalz;
    }
  }
  double ansz, ansx;
  ansx = finalx;
  ansz = finalz;
  printf("%.10lf %.10lf", ansx, ansz);
  return 0;
}
