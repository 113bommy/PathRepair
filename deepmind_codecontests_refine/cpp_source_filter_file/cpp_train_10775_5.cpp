#include <bits/stdc++.h>
using namespace std;
struct circle {
  complex<long double> p;
  long double r;
};
const long double eps = 1e-12;
const long double PI = 2 * acos(0);
long double sign(long double x) { return x < -eps ? -1 : x > eps; }
long double area_intersect(circle C, circle D) {
  if (C.r > D.r) swap(C, D);
  long double d = abs(C.p - D.p);
  if (sign(d - C.r - D.r) > 0) return 0.0;
  if (sign(d - abs(C.r - D.r)) < 0) return C.r * C.r * PI;
  long double r1 = C.r, r2 = D.r;
  long double alpha = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
  long double area = r2 * r2 * (alpha - sin(alpha) * cos(alpha));
  alpha = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
  area += r1 * r1 * (alpha - sin(alpha) * cos(alpha));
  return area;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long double x1, y1, x2, y2, r1, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  cout.precision(12);
  cout << fixed << area_intersect({{x1, y1}, r1}, {{x2, y2}, r2}) << '\n';
  return 0;
}
