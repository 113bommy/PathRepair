#include <bits/stdc++.h>
using namespace std;
double t;
double vmx;
double vx, vy, wx, wy;
double x, y;
double dist(double X, double Y) {
  return sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
}
bool ok(double mid) {
  double X, Y;
  if (x < t)
    X = vx * mid, Y = vy * mid;
  else {
    X = vx * t + (mid - t) * wx;
    Y = vy * t + (mid - t) * wy;
  }
  return dist(X, Y) <= vmx * mid;
}
int main() {
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x = x2 - x1, y = y2 - y1;
  cin >> vmx >> t;
  cin >> vx >> vy >> wx >> wy;
  double ini = 0, fim = 1e12;
  for (int vezez = 0; vezez < 1000; vezez++) {
    double mid = 0.5 * (fim + ini);
    if (ok(mid))
      fim = mid;
    else
      ini = mid;
  }
  printf("%.20f\n", ini);
  return 0;
}
