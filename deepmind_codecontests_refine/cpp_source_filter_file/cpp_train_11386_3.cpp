#include <bits/stdc++.h>
using namespace std;
long double yy1, yy2, yw, xb, yb, r, xx;
int main() {
  cin >> yy1 >> yy2 >> yw >> xb >> yb >> r;
  if (yy2 - yy1 <= 2 * r || xb <= r) {
    cout << -1 << "\n";
    return 0;
  }
  yw -= r;
  yy1 += r;
  xx = xb * (yw - yy1) / (-yb - yy1 + 2 * yw);
  cout << fixed;
  cout.precision(10);
  if (xx * (yy2 - yy1) / (yw - yy1) <= r ||
      xx * xx + (yw - yy2) * (yw - yy2) <= r * r ||
      xx * (yy2 - yy1) / sqrt(xx * xx + (yw - yy1) * (yw - yy1) <= r)) {
    cout << -1 << "\n";
    return 0;
  }
  cout << xx << "\n";
  return 0;
}
