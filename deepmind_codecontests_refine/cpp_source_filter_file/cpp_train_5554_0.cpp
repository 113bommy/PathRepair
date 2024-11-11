#include <bits/stdc++.h>
using namespace std;
double xp, yp, vp, x, y, v, r, stang, rr, nang, tx, ty, l, rb, m;
double gett(double p) {
  double qx = x + (ty - x) * p;
  double qy = y + (tx - y) * p;
  return sqrt(qx * qx + qy * qy);
}
pair<double, double> solve1(double x, double y) {
  double gyp = x * x + y * y;
  double k1 = gyp - rb * rb;
  pair<double, double> ans;
  ans.first = sqrt(k1);
  gyp = sqrt(gyp);
  ans.second = acos(rb / gyp);
  return ans;
}
double solve() {
  double l, r;
  double m1, m2;
  l = 0;
  r = 1;
  while (l < r - 1e-13) {
    m1 = l * 2 + r;
    m2 = l + 2 * r;
    m1 /= 3;
    m2 /= 3;
    if (gett(m1) < gett(m2))
      r = m2;
    else
      l = m1;
  }
  if (gett(l) >= rb) return sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
  double ang1, ang2, spang;
  ang1 = atan2(ty, tx);
  ang2 = atan2(y, x);
  spang = fabs(ang1 - ang2);
  pair<double, double> p1, p2;
  if (2 * M_PI - spang < spang) spang = 2 * M_PI - spang;
  p1 = solve1(fabs(x), fabs(y));
  p2 = solve1(fabs(tx), fabs(ty));
  spang -= p1.second;
  spang -= p2.second;
  return p1.first + p2.first + spang * rb;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> xp >> yp >> vp;
  cin >> x >> y >> v >> rb;
  stang = atan2(yp, xp);
  rr = xp * xp + yp * yp;
  rr = sqrt(rr);
  l = 0;
  r = 1e7;
  while (l < r - 1e-13) {
    m = l + r;
    m /= 2;
    nang = stang + (vp * m / rr);
    tx = rr * cos(nang);
    ty = rr * sin(nang);
    if (solve() > m * v)
      l = m;
    else
      r = m;
  }
  cout.precision(10);
  cout << fixed << l << endl;
  cin.get();
  cin.get();
  return 0;
}
