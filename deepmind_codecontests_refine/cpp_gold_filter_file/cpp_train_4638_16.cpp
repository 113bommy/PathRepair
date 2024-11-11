#include <bits/stdc++.h>
using namespace std;
int64_t inf = 2e18;
struct Point {
  double first, second, z;
  Point() {}
  Point(double a) : first(a), second(a), z(a) {}
  Point(double a, double b, double c) : first(a), second(b), z(c) {}
};
double dist(Point const& p1, Point const& p2) {
  return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
              (p1.second - p2.second) * (p1.second - p2.second) +
              (p1.z - p2.z) * (p1.z - p2.z));
}
Point operator-(Point const& p1, Point const& p2) {
  return {p2.first - p1.first, p2.second - p1.second, p2.z - p1.z};
}
Point operator+(Point const& p1, Point const& p2) {
  return {p2.first + p1.first, p2.second + p1.second, p2.z + p1.z};
}
Point operator*(Point const& p, double q) {
  return {p.first * q, p.second * q, p.z * q};
}
Point operator/(Point const& p, double q) {
  return {p.first / q, p.second / q, p.z / q};
}
int32_t main() {
  int64_t n, vp, vs;
  cin >> n;
  double sum = 0;
  vector<double> ps(n + 1, 0);
  Point beg;
  vector<Point> p(n + 1);
  for (int64_t i = 0; i < n + 1; i++)
    cin >> p[i].first >> p[i].second >> p[i].z;
  cin >> vp >> vs;
  cin >> beg.first >> beg.second >> beg.z;
  for (int64_t i = 0; i < n + 1; i++) {
    if (i) {
      sum += dist(p[i], p[i - 1]);
      ps[i] = sum / vs;
    }
  }
  Point loc;
  double l = 0, r = sum / vs;
  if (r < dist(beg, p[n]) / vp) return cout << "NO" << endl, 0;
  for (; abs(l - r) > 1e-10;) {
    int64_t ind = 0;
    double t = (l + r) / 2;
    for (; ps[ind + 1] < t; ind++)
      ;
    loc =
        (p[ind] - p[ind + 1]) / dist(p[ind + 1], p[ind]) * (t - ps[ind]) * vs +
        p[ind];
    if (dist(loc, beg) / vp <= t)
      r = t;
    else
      l = t;
  }
  cout << setprecision(6) << fixed;
  cout << "YES" << endl
       << l << endl
       << loc.first << ' ' << loc.second << ' ' << loc.z << ' ';
  return 0;
}
