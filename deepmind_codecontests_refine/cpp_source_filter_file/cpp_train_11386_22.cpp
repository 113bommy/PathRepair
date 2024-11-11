#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
double fabs(double x) { return x > 0 ? x : -x; }
int main() {
  double y1, y2, yw;
  cin >> y1 >> y2 >> yw;
  double xb, yb, r;
  cin >> xb >> yb >> r;
  yw -= r;
  double yp = y1 + r;
  double xw = xb * (yw - yp) / (2 * yw - yp - yb);
  double A, B, C;
  B = 1;
  A = -(yw - yp) / xw;
  C = -yp;
  double l2 = fabs(B * y2 + C) * fabs(B * y2 + C) / (A * A + B * B);
  if (r * r > l2)
    cout << -1 << '\n';
  else
    printf("%.7lf\n", xw);
  return 0;
}
