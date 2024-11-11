#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using std::cerr;
using std::cin;
using std::cos;
using std::cout;
using std::endl;
using std::make_pair;
using std::max;
using std::min;
using std::next_permutation;
using std::pair;
using std::priority_queue;
using std::queue;
using std::random_shuffle;
using std::set;
using std::sin;
using std::sort;
using std::sqrt;
using std::stack;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;
const long double PI = 3.14159265358979323846;
struct line {
  double a, b, c;
};
line getline(double x1, double y1, double x2, double y2) {
  line res;
  res.a = y2 - y1;
  res.b = x1 - x2;
  res.c = -(res.a * x1 + res.b * y1);
  return res;
}
int main() {
  int xp, yp, vp;
  int x, y, r, v;
  cin >> xp >> yp >> vp >> x >> y >> v >> r;
  double t1 = 0, t2 = 20000;
  double R = sqrt((double)(xp * xp + yp * yp));
  double phi0 = acos(double(xp) / R);
  double w = (double)(vp) / R;
  if (yp < 0) phi0 = 2 * PI - phi0;
  while (t2 - t1 > 0.000000001) {
    double t = (t2 + t1) / 2;
    double phi = phi0 + t * w;
    phi = phi - 2 * PI * (int)(phi / (2 * PI));
    double xx = R * cos(phi);
    double yy = R * sin(phi);
    line pr = getline(x, y, xx, yy);
    double d = abs(pr.c) / (sqrt((double)(pr.a * pr.a + pr.b * pr.b)));
    double time;
    double d1 = sqrt((double)(x * x + y * y));
    double dd;
    if (d1 > R) {
      double xxx = xx + (xx - x) * 0.0000001;
      double yyy = yy + (yy - y) * 0.0000001;
      dd = sqrt(xxx * xxx + yyy * yyy);
    } else {
      double xxx = x + (x - xx) * 0.0000001;
      double yyy = y + (y - yy) * 0.0000001;
      dd = sqrt(xxx * xxx + yyy * yyy);
    }
    if ((d > r) || ((d1 > r) && (dd < R) && (dd < d1))) {
      time = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y)) / v;
    } else {
      double dist =
          sqrt((d1 - r) * (d1 + r)) + sqrt((double)((R - r) * (R + r)));
      double alpha = acos((x * xx + y * yy) / R / d1);
      alpha = alpha - acos((double)(r) / d1) - acos((double)(r) / R);
      dist += alpha * r;
      time = dist / v;
    }
    if (time > t) {
      t1 = t;
    } else
      t2 = t;
  }
  printf("%0.10f\n", t1);
  return 0;
}
