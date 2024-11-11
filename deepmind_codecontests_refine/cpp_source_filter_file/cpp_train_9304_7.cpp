#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-6;
struct halfplane {
  long double a, b, c;
};
long double faabs(long double a) { return a < 0 ? -a : a; }
halfplane draw(long double sx, long double sy, long double ex, long double ey,
               long double x, long double y) {
  halfplane p = {1.0 * (ey - sy), 1.0 * (sx - ex), -1};
  p.c = -p.a * sx - p.b * sy;
  if (p.a * x + p.b * y + p.c < 0) {
    p.a = -p.a;
    p.b = -p.b;
    p.c = -p.c;
  }
  return p;
}
long double ccw(pair<long double, long double> a,
                pair<long double, long double> b,
                pair<long double, long double> c) {
  long double dx1 = b.first - a.first;
  long double dy1 = b.second - a.second;
  long double dx2 = c.first - a.first;
  long double dy2 = c.second - a.second;
  return dx1 * dy2 - dy1 * dx2;
}
pair<long double, long double> cross(halfplane a, halfplane b) {
  long double det = a.a * b.b - a.b * b.a;
  long double d1 = a.b * b.c - a.c * b.b;
  long double d2 = a.c * b.a - a.a * b.c;
  if (faabs(det) < eps) return pair<long double, long double>(-1e9, -1e9);
  return pair<long double, long double>(d1 / det, d2 / det);
}
long double dist(pair<long double, long double> a,
                 pair<long double, long double> b) {
  return hypot(b.first - a.first, b.second - a.second);
}
long double solve(vector<halfplane> &v) {
  vector<pair<long double, long double> > pnts, calc;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      pair<long double, long double> t = cross(v[i], v[j]);
      if (t.first < -1e8) continue;
      bool bad = 0;
      for (int k = 0; k < v.size(); k++) {
        if (t.first * v[k].a + t.second * v[k].b + v[k].c < -eps) {
          bad = 1;
          break;
        }
      }
      if (!bad) pnts.push_back(t);
    }
  }
  if (pnts.empty()) return 0;
  for (auto &i : pnts) {
    bool bad = 0;
    for (auto &j : calc) {
      if (dist(i, j) < eps) {
        bad = 1;
        break;
      }
    }
    if (!bad) calc.push_back(i);
  }
  swap(calc[0], *min_element(calc.begin(), calc.end()));
  sort(calc.begin() + 1, calc.end(),
       [&](const pair<long double, long double> &a,
           const pair<long double, long double> &b) {
         long double tmp = ccw(calc[0], a, b);
         if (faabs(tmp) < eps) return dist(calc[0], a) < dist(calc[0], b);
         return tmp > 0;
       });
  long double ret = 0;
  for (int i = 1; i < calc.size() - 1; i++) {
    ret += ccw(calc[0], calc[i], calc[i + 1]);
  }
  return ret;
}
int main() {
  int w, h, ang;
  cin >> w >> h >> ang;
  vector<halfplane> v;
  pair<long double, long double> a[4] = {{1.0 * w, 1.0 * h},
                                         {1.0 * w, -1.0 * h},
                                         {-1.0 * w, -1.0 * h},
                                         {-1.0 * w, 1.0 * h}};
  for (int i = 0; i < 4; i++) {
    pair<long double, long double> p1 = a[i], p2 = a[(i + 1) & 3];
    v.push_back(draw(p1.first, p1.second, p2.first, p2.second, 0.0, 0.0));
  }
  long double rad = (acos(-1) * ang) / 180.0;
  for (int i = 0; i < 4; i++) {
    a[i] = pair<long double, long double>(
        a[i].first * cos(rad) - a[i].second * sin(rad),
        a[i].first * sin(rad) + a[i].second * cos(rad));
  }
  for (int i = 0; i < 4; i++) {
    pair<long double, long double> p1 = a[i], p2 = a[(i + 1) & 3];
    v.push_back(draw(p1.first, p1.second, p2.first, p2.second, 0.0, 0.0));
  }
  printf("%.10Lf", solve(v) * 0.125);
}
