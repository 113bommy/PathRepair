#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void boost() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  boost();
  long long r, x1, x2, y1, y2;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  double d = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))) * 1.000;
  long long dd = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
  if (dd == 0) {
    double xx = (x1 + r) / 2.00;
    double yy = y1;
    printf("%.15lf %.15lf %0.15lf", xx, yy, r / 2.00);
  } else if (dd > (r * r)) {
    cout << x1 << " " << y1 << " " << r << "\n";
  } else {
    double xx = ((d + r) * 1.00 * x1 - (r * x2 * 1.00)) / d * 1.00;
    double yy = (((d + r) * 1.00 * y1) - (r * y2 * 1.00)) / d * 1.00;
    double rr = (r + d) / 2 * 1.00;
    printf("%.15lf %.15lf %.15lf\n", (xx + x2) / 2.00, (yy + y2) / 2.00, rr);
  }
  return 0;
}
