#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double xx, double yy) {
    x = xx;
    y = yy;
  }
  point() { x = y = 0; }
};
double a, b, c, ax, ay, bx, by;
double solve(int id, double para) {
  double ans;
  if (id)
    ans = -(a * para + c) / b;
  else
    ans = -(b * para + c) / a;
  return ans;
}
int main() {
  cin >> a >> b >> c >> ax >> ay >> bx >> by;
  double ans = abs(ax - bx) + abs(ay - by);
  if (ax != bx && ay != by && a != 0 && b != 0) {
    double k1 = -a / b, k2 = (ay - by) / (ax - bx);
    if (k1 * k2 > 0) {
      point p1(ax, solve(1, ax)), p2(bx, solve(1, bx)), p3(solve(0, ay), ay),
          p4(solve(0, by), by);
      point pb, pe;
      int ct = 0;
      if ((p1.y - ay) * (p1.y - by) <= 0) {
        pb = p1;
        ct++;
      }
      if ((p2.y - ay) * (p2.y - by) <= 0) {
        if (ct)
          pe = p2;
        else
          pb = p2;
        ct++;
      }
      if (ct < 2 && (p3.x - ax) * (p3.x - bx) <= 0) {
        if (ct)
          pe = p3;
        else
          pb = p3;
        ct++;
      }
      if (ct < 2 && (p4.x - ax) * (p4.x - bx) <= 0) pe = p4;
      double changedis = abs(pb.x - pe.x) + abs(pb.y - pe.y) -
                         sqrt(pow(pb.x - pe.x, 2) + pow(pb.y - pe.y, 2));
      ans -= changedis;
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
