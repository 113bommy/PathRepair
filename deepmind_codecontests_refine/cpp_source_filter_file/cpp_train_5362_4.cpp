#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
double x1, y_1, x2, y2, vmax, tt, u1, u2, u3, u4;
double poskus(double t) {
  double tx = x1;
  double ty = y_1;
  if (t <= tt)
    tx += u1 * t;
  else
    tx += u1 * tt + u3 * (t - tt);
  if (t < tt)
    ty += u2 * t;
  else
    ty += u2 * tt + u4 * (t - tt);
  return (hypot(x2 - tx, y2 - ty) <= vmax * t);
}
int main() {
  cin >> x1 >> y_1 >> x2 >> y2;
  cin >> vmax >> tt;
  cin >> u1 >> u2;
  cin >> u3 >> u4;
  cout << fixed << setprecision(12);
  double l = 0, d = 5000000;
  int st = 400;
  while (st--) {
    double s = (l + d) / 2;
    if (poskus(s))
      d = s;
    else
      l = s;
  }
  cout << l << "\n";
  return 0;
}
