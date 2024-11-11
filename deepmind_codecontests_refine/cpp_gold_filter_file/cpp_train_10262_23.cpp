#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const double invR = 100000;
const double eps = 1e-5;
struct Point {
  double x, y;
  bool operator<(const Point &b) const {
    if (x != b.x)
      return x < b.x;
    else
      return y < b.y;
  }
  Point operator+(const Point &b) const { return (Point){x + b.x, y + b.y}; }
  Point operator-(const Point &b) const { return (Point){x - b.x, y - b.y}; }
  Point operator*(const double &b) const { return (Point){x * b, y * b}; }
  double det(const Point &b) { return x * b.y - y * b.x; }
  double getdis(const Point &b) {
    return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
  }
};
struct Line {
  double a, b, c;
  void init(Point u, Point v) {
    if (u.x == v.x) {
      a = 1;
      b = 0;
      c = -u.x;
    } else {
      double k = (v.y - u.y) / (v.x - u.x);
      double m = v.y - k * v.x;
      a = k;
      b = -1;
      c = m;
    }
  }
  double calc(Point u) { return a * u.x + b * u.y + c; }
  double getdis(Point u) {
    return fabs((a * u.x + b * u.y + c) / sqrt(a * a + b * b));
  }
};
Point red[maxn], blue[maxn], curred[maxn], curblue[maxn];
vector<Point> calcConvexHull(vector<Point> &p) {
  static vector<Point> convexHull;
  convexHull.clear();
  int n = p.size();
  sort(p.begin(), p.end());
  convexHull.resize(static_cast<unsigned int>(n * 2));
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (
        k > 1 &&
        (convexHull[k - 1] - convexHull[k - 2]).det(p[i] - convexHull[k - 1]) <
            0)
      k--;
    convexHull[k++] = p[i];
  }
  int t = k;
  for (int i = n - 2; i >= 0; i--) {
    while (
        k > t &&
        (convexHull[k - 1] - convexHull[k - 2]).det(p[i] - convexHull[k - 1]) <
            0)
      k--;
    convexHull[k++] = p[i];
  }
  convexHull.resize(static_cast<unsigned int>(k - 1));
  return convexHull;
}
Point inverse(Point o, Point t) {
  if (o.x == t.x && o.y == t.y) return o;
  double d1 = o.getdis(t);
  double d2 = invR * invR / d1;
  return o + (t - o) * (d2 / d1);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  static vector<Point> p;
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", &red[i].x, &red[i].y), p.push_back(red[i]);
  for (int i = 1; i <= m; i++)
    scanf("%lf%lf", &blue[i].x, &blue[i].y), p.push_back(blue[i]);
  vector<Point> convexHull = calcConvexHull(p);
  for (auto u : convexHull) {
    for (int i = 1; i <= n; i++) {
      if (u.x == red[i].x && u.y == red[i].y) {
        puts("-1");
        return 0;
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    p.clear();
    for (int j = 1; j <= n; j++) curred[j] = inverse(blue[i], red[j]);
    for (int j = 1; j <= m; j++) {
      curblue[j] = inverse(blue[i], blue[j]);
      p.push_back(curblue[j]);
    }
    convexHull = calcConvexHull(p);
    for (int j = 0; j < convexHull.size(); j++) {
      Point u = convexHull[j], v;
      for (int j2 = 1; j2 <= n; j2++) {
        v = curred[j2];
        Line l;
        l.init(u, v);
        bool flg = true;
        for (auto k : convexHull) {
          if (l.calc(blue[i]) * l.calc(k) < 0) {
            flg = false;
            break;
          }
        }
        if (flg) {
          if (fabs(l.getdis(blue[i])) > eps)
            ans = max(ans, invR * invR / l.getdis(blue[i]) / 2);
        }
      }
      v = convexHull[(j + 1) % convexHull.size()];
      Line l;
      l.init(u, v);
      bool flg = false;
      for (int k = 1; k <= n; k++) {
        if (l.calc(curred[k]) * l.calc(blue[i]) <= 0) {
          flg = true;
          break;
        }
      }
      if (flg) {
        if (fabs(l.getdis(blue[i])) > eps)
          ans = max(ans, invR * invR / l.getdis(blue[i]) / 2);
      }
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
