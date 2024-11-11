#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, m;
  cin >> a >> b >> m;
  int vx, vy, vz;
  cin >> vx >> vy >> vz;
  double t = (double)m / (-vy);
  double xm;
  int xd;
  if (vx > 0) {
    xm = fmod((a / 2.0) + (vx * t), a);
    xd = abs(((a / 2.0) + (vx * t))) / a;
    if (xd % 2 == 1) {
      xm = a - xm;
    }
  } else {
    xm = fmod((a / 2.0) + (-vx * t), a);
    xd = abs(((a / 2.0) + (-vx * t))) / a;
    if (xd % 2 == 0) {
      xm = a - xm;
    }
  }
  double zm = fmod(vz * t, b);
  int zd = abs((vz * t)) / b;
  if (zd % 2 == 1) {
    zm = b - zm;
  }
  cout << setprecision(7) << fixed << xm << " " << zm << endl;
  return 0;
}
