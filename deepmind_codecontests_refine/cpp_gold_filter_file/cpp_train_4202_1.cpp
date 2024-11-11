#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 9;
const double eps = 1e-9;
double a, b, m, vx, vy, vz;
int main() {
  cin >> a >> b >> m >> vx >> vy >> vz;
  double cx = a / 2, cy = m, cz = 0;
  double T = -cy / vy;
  cx += vx * T;
  cz += vz * T;
  while (true) {
    if (cx < 0) {
      cx = -cx;
    } else if (cx > a) {
      cx = 2.0 * a - cx;
    } else
      break;
  }
  while (true) {
    if (cz < 0) {
      cz = -cz;
    } else if (cz > b) {
      cz = 2.0 * b - cz;
    } else
      break;
  }
  cout << fixed << setprecision(7) << cx << ' ' << cz;
  return 0;
}
