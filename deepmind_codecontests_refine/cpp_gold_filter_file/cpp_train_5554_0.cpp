#include <bits/stdc++.h>
using namespace std;
const static double pi = acos(-1.0), eps = 1e-8;
pair<double, double> p, s;
double vp, vs, r, R1, R2, TL1, TL2, TNG1, TNG2;
double PP_dis(pair<double, double> x, pair<double, double> y) {
  return sqrt((x.first - y.first) * (x.first - y.first) +
              (x.second - y.second) * (x.second - y.second));
}
bool check(double x) {
  pair<double, double> p0;
  p0.first = p.first * cos(vp * x) - p.second * sin(vp * x);
  p0.second = p.first * sin(vp * x) + p.second * cos(vp * x);
  double TNG = acos((p0.first * s.first + p0.second * s.second) / R1 / R2);
  if (TNG < 0.0) TNG += pi;
  TNG -= TNG1 + TNG2;
  if (TNG <= 0.0) return (x >= (PP_dis(s, p0) / vs));
  return x >= ((TNG * r + TL1 + TL2) / vs);
}
int main() {
  scanf("%lf %lf %lf", &p.first, &p.second, &vp);
  scanf("%lf %lf %lf %lf", &s.first, &s.second, &vs, &r);
  R1 = sqrt(p.first * p.first + p.second * p.second);
  TL1 = sqrt(R1 * R1 - r * r);
  TNG1 = asin(TL1 / R1);
  R2 = sqrt(s.first * s.first + s.second * s.second);
  TL2 = sqrt(R2 * R2 - r * r);
  TNG2 = asin(TL2 / R2);
  vp /= R1;
  double l = 0.0, r = 1e9, mid;
  while (r - l > eps) {
    mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.6lf\n", l);
  return 0;
}
