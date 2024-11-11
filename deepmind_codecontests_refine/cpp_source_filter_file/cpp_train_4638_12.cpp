#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
class Point {
 public:
  double x, y, z;
  Point(double a = 0, double b = 0, double c = 0) { x = a, y = b, z = c; }
  Point mid(Point pb) {
    return Point((x + pb.x) / 2, (y + pb.y) / 2, (z + pb.z) / 2);
  }
  bool equal(Point pb) {
    if (fabs(x - pb.x) > eps || fabs(y - pb.y) > eps || fabs(z - pb.z) > eps)
      return false;
    return true;
  }
  double length(Point pb) {
    double lx = fabs(x - pb.x), ly = fabs(y - pb.y), lz = fabs(z - pb.z);
    return sqrt(lx * lx + ly * ly + lz * lz);
  }
};
Point p[10010];
double pastTime[10010];
Point binary(Point pa, Point pb, Point pp, double vs, double vp, double pst) {
  Point low = pa, high = pb, st = pa, mid;
  double ls, lp, ts, tp;
  while (!low.equal(high)) {
    mid = low.mid(high);
    ls = st.length(mid) + pst;
    lp = pp.length(mid);
    ts = ls / vs, tp = lp / vp;
    if (fabs(ts - tp) < eps)
      return mid;
    else if (ts < tp)
      low = mid;
    else
      high = mid;
  }
  return Point(100000, 0, 0);
}
int main() {
  int n;
  double vs, vp;
  Point pp;
  pastTime[0] = 0;
  while (cin >> n) {
    Point pt;
    bool yn = false;
    for (int i = 0; i < n + 1; i++) cin >> p[i].x >> p[i].y >> p[i].z;
    cin >> vp >> vs;
    cin >> pp.x >> pp.y >> pp.z;
    for (int i = 0; i < n; i++) {
      pastTime[i + 1] = pastTime[i] + p[i].length(p[i + 1]);
      pt = binary(p[i], p[i + 1], pp, vs, vp, pastTime[i]);
      if (pt.x < 10010) {
        yn = true;
        break;
      }
    }
    if (yn) {
      puts("YES");
      printf("%.7f\n", pp.length(pt) / vp);
      printf("%.7f %.7f %.7f\n", pt.x, pt.y, pt.z);
    } else
      puts("NO");
  }
  return 0;
}
