#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
struct circle {
  pair<double, double> p;
  double r;
};
inline int sign(double x) { return x < -eps ? -1 : x > eps; }
pair<double, double> operator*(const pair<double, double> &l,
                               const pair<double, double> &r) {
  return {l.first * r.first - l.second * r.second,
          l.first * r.second + l.second * r.first};
}
pair<double, double> operator-(const pair<double, double> &l,
                               const pair<double, double> &r) {
  return {l.first - r.first, l.second - r.second};
}
inline double dot(pair<double, double> &a, pair<double, double> &b) {
  return (pair<double, double>(a.second, a.first) * b).first;
}
inline double cross(pair<double, double> &a, pair<double, double> &b) {
  return (pair<double, double>(a.second, a.first) * b).second;
}
inline int ccw(pair<double, double> a, pair<double, double> b,
               pair<double, double> c) {
  b = b - a;
  c = c - a;
  if (cross(b, c) > 0) return +1;
  if (cross(b, c) < 0) return -1;
  if (dot(b, c) < 0) return +2;
  if (dot(b, b) < dot(c, c)) return -2;
  return 0;
}
inline double dist(pair<double, double> a, pair<double, double> b) {
  double d1 = a.first - b.first, d2 = a.second - b.second;
  return sqrt(d1 * d1 + d2 * d2);
}
inline pair<double, double> three_point_circle(pair<double, double> A,
                                               pair<double, double> B,
                                               pair<double, double> C) {
  double yDelta_a = B.second - A.second;
  double xDelta_a = B.first - A.first;
  double yDelta_b = C.second - B.second;
  double xDelta_b = C.first - B.first;
  pair<double, double> center = pair<double, double>(0, 0);
  double aSlope = yDelta_a / xDelta_a;
  double bSlope = yDelta_b / xDelta_b;
  center.first = (aSlope * bSlope * (A.second - C.second) +
                  bSlope * (A.first + B.first) - aSlope * (B.first + C.first)) /
                 (2 * (bSlope - aSlope));
  center.second = -1 * (center.first - (A.first + B.first) / 2) / aSlope +
                  (A.second + B.second) / 2;
  return center;
}
inline int intersect(circle C, circle D) {
  double d = dist(C.p, D.p);
  if (sign(d - C.r - D.r) > 0) return 0;
  if (sign(d - abs(C.r - D.r)) < 0) return 1;
  double a = (C.r * C.r - D.r * D.r + d * d) / (2 * d);
  double h = sqrt(C.r * C.r - a * a);
  if (sign(h) == 0) return 2;
  return 3;
}
inline pair<double, double> rotacion(pair<double, double> x, double ang) {
  return {x.first * cos(ang) - x.second * sin(ang),
          x.first * sin(ang) + x.second * cos(ang)};
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  pair<double, double> a, b;
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  a = {x1, y1}, b = {x2, y2};
  int n;
  cin >> n;
  vector<circle> v(n);
  for (auto &i : v) {
    double x, y, r;
    cin >> x >> y >> r;
    i = {{x, y}, r};
  }
  if (x1 > x2) swap(a, b);
  double ang = asin((a.second - b.second) / dist(a, b));
  for (auto &c : v) c.p = rotacion(c.p, ang);
  a = rotacion(a, ang);
  b = rotacion(b, ang);
  double r = dist(a, b) / 2.0;
  double x = (a.first + b.first) / 2.0;
  vector<vector<pair<double, double>>> s(2);
  for (auto &c : v) {
    bool op = c.p.second > a.second;
    double fb = a.second - r, e = a.second, sb;
    while (e - fb > eps) {
      double m = (fb + e) / 2.0;
      pair<double, double> center =
          three_point_circle(a, pair<double, double>(x, m), b);
      int d = intersect(c, {center, dist(center, a)});
      if (op) {
        if (d == 0)
          fb = m;
        else
          e = m;
      } else {
        if (d == 0)
          e = m;
        else
          fb = m;
      }
    }
    sb = a.second - r, e = a.second;
    while (e - sb > eps) {
      double m = (sb + e) / 2.0;
      pair<double, double> center =
          three_point_circle(a, pair<double, double>(x, m), b);
      int d = intersect(c, {center, dist(center, a)});
      if (op) {
        if (d != 1)
          sb = m;
        else
          e = m;
      } else {
        if (d != 1)
          e = m;
        else
          sb = m;
      }
    }
    if (abs(fb - sb) > eps) {
      s[0].push_back(
          {dist(three_point_circle(a, pair<double, double>(x, fb), b), a),
           dist(three_point_circle(a, pair<double, double>(x, sb), b), a)});
      if (s[0].back().second < s[0].back().first)
        swap(s[0].back().first, s[0].back().second);
    }
  }
  for (auto &c : v) {
    bool op = c.p.second < a.second;
    double fb = a.second, e = a.second + r, sb;
    while (e - fb > eps) {
      double m = (fb + e) / 2.0;
      pair<double, double> center =
          three_point_circle(a, pair<double, double>(x, m), b);
      int d = intersect(c, {center, dist(center, a)});
      if (op) {
        if (d == 0)
          e = m;
        else
          fb = m;
      } else {
        if (d == 0)
          fb = m;
        else
          e = m;
      }
    }
    sb = a.second, e = a.second + r;
    while (e - sb > eps) {
      double m = (sb + e) / 2.0;
      pair<double, double> center =
          three_point_circle(a, pair<double, double>(x, m), b);
      int d = intersect(c, {center, dist(center, a)});
      if (op) {
        if (d != 1)
          e = m;
        else
          sb = m;
      } else {
        if (d != 1)
          sb = m;
        else
          e = m;
      }
    }
    if (abs(fb - sb) > eps) {
      s[1].push_back(
          {dist(three_point_circle(a, pair<double, double>(x, fb), b), a),
           dist(three_point_circle(a, pair<double, double>(x, sb), b), a)});
      if (s[1].back().second < s[1].back().first)
        swap(s[1].back().first, s[1].back().second);
    }
  }
  double ans = 1e13;
  for (int i = 0; i < 2; ++i) {
    s[i].push_back({r, r});
    s[i].push_back({1e13, 1e13});
    sort(s[i].begin(), s[i].end());
    double last = dist(a, b) / 2.0;
    for (auto x : s[i]) {
      if (x.first - eps > last) {
        ans = min(ans, last);
        break;
      }
      last = max(last, x.second);
    }
  }
  cout << setprecision(10) << fixed << ans << "\n";
  return 0;
}
