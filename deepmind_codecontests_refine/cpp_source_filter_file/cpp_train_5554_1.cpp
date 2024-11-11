#include <bits/stdc++.h>
using namespace std;
pair<double, double> operator-(const pair<double, double>& a,
                               const pair<double, double>& b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
pair<double, double> operator+(const pair<double, double>& a,
                               const pair<double, double>& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<double, double> operator*(double a, const pair<double, double>& b) {
  return make_pair(a * b.first, a * b.second);
}
double dot(const pair<double, double>& a, const pair<double, double>& b) {
  return a.first * b.first + a.second * b.second;
}
double cross(const pair<double, double>& a, const pair<double, double>& b) {
  return a.first * b.second - a.second * b.first;
}
double len(const pair<double, double>& a) { return hypot(a.first, a.second); }
const double eps = 1e-8;
int line_circle_is(pair<double, double> a, pair<double, double> b,
                   pair<double, double> c, double rad, pair<double, double>& q,
                   pair<double, double>& r, double& sep) {
  if (len(a - b) < eps) return 0;
  double s = dot(b - a, c - a) / len(b - a),
         t1 = cross(b - a, c - a) / len(b - a);
  double t = sqrt(rad * rad - t1 * t1);
  if (s > -eps && s < len(b - a) + eps) {
    q = a + ((s - t) / len(b - a)) * (b - a);
    r = a + ((s + t) / len(b - a)) * (b - a);
    sep = 2 * asin(abs(t) / rad);
    return 2;
  } else {
    return 0;
  }
}
int first, second, v, r, x_p, y_p, v_p;
double time(double th) {
  th = -th;
  pair<double, double> a = make_pair(first, second),
                       b = make_pair(x_p * cos(th) + y_p * sin(th),
                                     -sin(th) * x_p + cos(th) * y_p),
                       A, B;
  double sep, dist;
  if (line_circle_is(a, b, make_pair(0, 0), r, A, B, sep) == 2) {
    dist = len(A - a) + sep * r + len(b - B);
  } else {
    dist = len(b - a);
  }
  return (dist / v > -th * r / v_p) ? 1e30 : -th * hypot(x_p, y_p) / v_p;
}
double angle(pair<double, double> a, pair<double, double> b,
             pair<double, double> c) {
  double d = atan2(b.second - c.second, b.first - c.first) -
             atan2(a.second - c.second, a.first - c.first);
  while (d < 0) d += 2 * acos(-1.0);
  return d;
}
double path_around_circle(pair<double, double> a, pair<double, double> b,
                          pair<double, double> c, double r) {
  double dist_to_circle = cross(b - a, c - a) / len(b - a),
         dot_p = dot(b - a, c - a) / len(b - a);
  if (dot_p > eps && dot_p < len(b - a) - eps && dist_to_circle < r - eps) {
    double crit = min(angle(a, b, c), angle(b, a, c));
    double p1, p2, p3;
    p1 = sqrt(dot(a - c, a - c) - r * r);
    p2 =
        r * ((crit - acos(-1.0)) + asin(r / len(a - c)) + asin(r / len(b - c)));
    p3 = sqrt(dot(b - c, b - c) - r * r);
    return p1 + p2 + p3;
  } else {
    return len(b - a);
  }
}
bool can_do(double t) {
  double th = -(t * v_p / hypot(x_p, y_p));
  pair<double, double> a = make_pair(first, second),
                       b = make_pair(x_p * cos(th) + y_p * sin(th),
                                     -sin(th) * x_p + cos(th) * y_p);
  return path_around_circle(a, b, make_pair(0, 0), r) / v < t + eps;
}
int main() {
  cin >> x_p >> y_p >> v_p;
  cin >> first >> second >> v >> r;
  double a = 0, b = 1e9;
  for (int i = 0; i < 100; i++) {
    double mid = (a + b) / 2;
    if (can_do(mid))
      b = mid;
    else
      a = mid;
  }
  printf("%0.9lf\n", a);
}
