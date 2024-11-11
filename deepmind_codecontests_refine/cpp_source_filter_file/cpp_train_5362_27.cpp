#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = (1 << 29);
const double EPS = 0.000000000001;
const double Pi = acos(-1.0);
double X1, Y1, X2, Y2;
double vm, t1;
double vx, vy, wx, wy;
double dist(double x, double y, double x0, double y0) {
  double tx = x - x0, ty = y - y0;
  return sqrt(tx * tx + ty * ty);
}
bool check(double t) {
  if (t < t1 + EPS) {
    double x = X2 - vx * t, y = Y2 - vy * t;
    double d = dist(x, y, X1, X1);
    if (vm * t > d - EPS) return 1;
    return 0;
  } else {
    double x0 = X2 - vx * t1, y0 = Y2 - vy * t1;
    double x = x0 - wx * (t - t1), y = y0 - wy * (t - t1);
    double d = dist(x, y, X1, X1);
    if (vm * t > d - EPS) return 1;
    return 0;
  }
}
double bin(double l, double r) {
  double res = r;
  while (l < r - EPS) {
    double m = (l + r) / 2;
    if (check(m))
      res = r = m;
    else
      l = m;
  }
  return res;
}
int main() {
  while (cin >> X1 >> Y1 >> X2 >> Y2 >> vm >> t1 >> vx >> vy >> wx >> wy) {
    double t = bin(0, INF);
    printf("%.7f\n", t);
  }
  return 0;
}
