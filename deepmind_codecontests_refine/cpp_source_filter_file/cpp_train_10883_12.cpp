#include <bits/stdc++.h>
using namespace std;
double Dist(double x1, double y1, double x2, double y2, int pow) {
  double z = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  if (pow == 1)
    return z;
  else
    return sqrt(z);
}
const double eps = 1e-9;
const double PI = acos(-1.0);
int main() {
  int x0, y0, v, t;
  scanf("%d %d %d %d", &x0, &y0, &v, &t);
  double r0 = 1.0 * v * t;
  int n, x, y, r;
  scanf("%d", &n);
  std::vector<pair<double, int> > a;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &x, &y, &r);
    double d = Dist(x, y, x0, y0, 1);
    if (d < 1.0 * r * r + eps) {
      printf("%0.11f\n", 1.0);
      return 0;
    }
    d = sqrt(d);
    if (r + r0 < d - eps) continue;
    double angL, angR, ang;
    double angM = atan2(y - y0, x - x0);
    if (angM < 0) angM += 2 * PI;
    double tlen = sqrt(d * d - 1.0 * r * r);
    if (tlen < r0 + eps) {
      ang = asin(r / d);
    } else {
      ang = acos(d * d + r0 * r0 - 1.0 * r * r) / (2 * d * r0);
    }
    angL = angM - ang;
    angR = angM + ang;
    if (angL < 0) {
      a.push_back(make_pair(angL + 2 * PI, 1));
      a.push_back(make_pair(2 * PI, -1));
      a.push_back(make_pair(0.0, 1));
      a.push_back(make_pair(angR, -1));
    } else if (angR > 2 * PI) {
      a.push_back(make_pair(angL, 1));
      a.push_back(make_pair(2 * PI, -1));
      a.push_back(make_pair(0.0, 1));
      a.push_back(make_pair(angR - 2 * PI, -1));
    } else {
      a.push_back(make_pair(angL, 1));
      a.push_back(make_pair(angR, -1));
    }
  }
  sort(a.begin(), a.end());
  double ans = 0, last = 0;
  int c = 0;
  for (auto& p : a) {
    if (c > 0) ans += p.first - last;
    c += p.second;
    last = p.first;
  }
  ans /= 2 * PI;
  printf("%.11f\n", ans);
  return 0;
}
