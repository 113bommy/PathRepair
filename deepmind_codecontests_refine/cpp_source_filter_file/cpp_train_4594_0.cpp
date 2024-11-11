#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;
const double EPS = 1e-3;
double a, b, c, x0, kok, x1, kek;
double getx(double y) {
  if (abs(a) < EPS) {
    return -INF;
  }
  return (-c - b * y) / a;
}
double gety(double x) {
  if (abs(b) < EPS) {
    return -INF;
  }
  return (-c - a * x) / b;
}
double d(double x0, double kok, double x1, double kek) {
  return sqrtl((x0 - x1) * (x0 - x1) + (kok - kek) * (kok - kek));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> c >> x0 >> kok >> x1 >> kek;
  double x2, y2, x3, y3;
  x2 = getx(kok);
  y2 = gety(x0);
  x3 = getx(kek);
  y3 = gety(x1);
  cout << setprecision(10) << fixed
       << min(abs(x0 - x1) + abs(kok - kek),
              min(min(abs(x0 - x2) + d(x2, kok, x3, kek) + abs(x1 - x3),
                      abs(kok - y2) + d(x0, y2, x1, y3) + abs(kek - y3)),
                  min(abs(x0 - x2) + d(x2, kok, x1, y3) + abs(kek - y3),
                      abs(x0 - x2) + d(x2, kok, x3, kek) + abs(x1 - x3))))
       << endl;
  return 0;
}
