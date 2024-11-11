#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
struct point {
  double first, second;
  point(double first = 0, double second = 0) : first(first), second(second) {}
  point operator-(point a) { return point(first - a.first, second - a.second); }
  double operator^(point a) { return first * a.second - second * a.first; }
  double operator*(point a) { return first * a.first + second * a.second; }
  double nor() { return sqrt(*this * *this); }
  void input() { scanf("%lf %lf", &first, &second); }
  void print() { printf("%lf %lf\n", first, second); }
};
const double pi = acos(-1);
int intersect(point a, point b, double r) {
  double ab = (a - b).nor(), aa = a.nor(), bb = b.nor();
  double mid = min(aa, bb);
  if (aa * aa < bb * bb + ab * ab || bb * bb < aa * aa + ab * ab)
    smin(mid, fabs(a ^ b) / ab);
  return mid < r - 1e-8;
}
void tangent_of_circle(double r, point a, double *al) {
  double be = acos(r / a.nor());
  al[0] = atan2(a.second, a.first) - be;
  al[1] = atan2(a.second, a.first) + be;
}
double calc(point a, double al, point b, double be, double r) {
  point c = point(cos(al) * r, sin(al) * r);
  point d = point(cos(be) * r, sin(be) * r);
  if (intersect(a, c, r)) return 1e200;
  if (intersect(b, d, r)) return 1e200;
  double ans = (a - c).nor() + (b - d).nor();
  double mid = fabs(al - be);
  smin(mid, 2 * pi - mid);
  return ans + mid * r;
}
point a, b;
double vp, v, r, R, al, be;
int can(double t) {
  point c = point(cos(al * t + be) * R, sin(al * t + be) * R);
  if (!intersect(b, c, r)) return (b - c).nor() / v < t + 1e-8;
  double tb[4], tc[4];
  tangent_of_circle(r, b, tb);
  tangent_of_circle(r, c, tc);
  double mid = 1e200;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      smin(mid, calc(b, tb[i], c, tc[j], r));
    }
  return mid / v < t + 1e-8;
}
int main() {
  a.input();
  scanf("%lf", &vp);
  b.input();
  scanf("%lf%lf", &v, &r);
  R = a.nor();
  al = vp / R, be = atan2(a.second, a.first);
  double st = 0, ed = 1e10;
  for (int i = 0; i < 100; i++) {
    double mid = (st + ed) / 2;
    if (can(mid))
      ed = mid;
    else
      st = mid;
  }
  printf("%.10lf\n", ed);
  return 0;
}
