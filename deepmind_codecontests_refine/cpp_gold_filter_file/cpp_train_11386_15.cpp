#include <bits/stdc++.h>
using namespace std;
long double yy1, yy2, yw, xb, yb, r;
int main() {
  cin >> yy1 >> yy2 >> yw;
  cin >> xb >> yb >> r;
  long double rr = xb - 0.1;
  long double ll = 1.0000000;
  long double re;
  long double tg;
  while (rr - ll > 0.000000001) {
    re = (rr + ll) / 2.000000000;
    tg = (xb - re) / (yw - yb - r);
    if (yw - re / tg - r > yy1 + r + 0.000000001)
      ll = re;
    else
      rr = re;
  }
  tg = (xb - ll) / (yw - yb - r);
  long double xx = ll - (yw - r - yy2) * tg;
  long double dist =
      (yy2 - (yw - ll / tg - r)) * xx /
      sqrt(xx * xx + (yy2 - (yw - ll / tg - r)) * (yy2 - (yw - ll / tg - r)));
  if (yw - ll / tg - r < yy2 - r - 0.000000001 &&
      yw - ll / tg - r > yy1 + r + 0.000000001 && dist > r + 0.000000001)
    cout << setprecision(20) << ll << endl;
  else
    cout << "-1" << endl;
  return 0;
}
