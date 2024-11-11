#include <bits/stdc++.h>
using namespace std;
const int MaxN = 5005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const long long LINF = 1000000000000000005ll;
int dcmp(double x) { return x < -eps ? -1 : x > eps; }
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point &b) { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) { return Point(x - b.x, y - b.y); }
  Point operator*(const double &b) { return Point(x * b, y * b); }
  Point operator/(const double &b) { return Point(x / b, y / b); }
  double operator*(const Point &b) { return x * b.y - y * b.x; }
  double operator%(const Point &b) { return x * b.x + y * b.y; }
  double len() { return sqrt(x * x + y * y); }
  double len2() { return x * x + y * y; }
  void init() { scanf("%lf%lf", &x, &y); }
  bool operator==(const Point &b) const {
    return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
  }
  bool operator<(const Point &b) const {
    if (dcmp(x - b.x) != 0) return dcmp(x - b.x) < 0;
    return dcmp(y - b.y) < 0;
  }
};
struct Polygon {
  int M;
  vector<Point> p;
  void init() {
    p.resize(M);
    for (int i = 0; i < M; ++i) p[i].init();
    if (dcmp((p[1] - p[0]) * (p[2] - p[1])) < 0) reverse(p.begin(), p.end());
    p.push_back(p[0]);
  }
  Point &operator[](const int &i) { return p[i]; }
} poly[MaxN];
double xmul(Point a, Point b, Point c) { return (b - a) * (c - a); }
int n;
pair<double, int> keys[MaxN];
double get(Point a, Point b, Point c) {
  double t;
  if (fabs(a.x - b.x) > eps)
    t = (c.x - a.x) / (b.x - a.x);
  else
    t = (c.y - a.y) / (b.y - a.y);
  t = max(min(t, 1.0), 0.0);
  return t;
}
double solve() {
  double res = 0;
  for (int i = 0; i < n; ++i)
    for (int x = 0; x < poly[i].M; ++x) {
      int keysize = 0;
      for (int k = 0; k < n; ++k)
        if (k != i)
          for (int y = 0; y < poly[k].M; ++y) {
            int t1 = dcmp(xmul(poly[i][x], poly[i][x + 1], poly[k][y]));
            int t2 = dcmp(xmul(poly[i][x], poly[i][x + 1], poly[k][y + 1]));
            if (!t1 && !t2) {
              if (k < i && dcmp((poly[k][y + 1] - poly[k][y]) %
                                (poly[i][x + 1] - poly[i][x])) >= 0) {
                double d1 = get(poly[i][x], poly[i][x + 1], poly[k][y]);
                double d2 = get(poly[i][x], poly[i][x + 1], poly[k][y + 1]);
                keys[keysize++] = make_pair(d1, 1);
                keys[keysize++] = make_pair(d2, -1);
              }
            } else if ((t1 >= 0 && t2 < 0) || (t1 < 0 && t2 >= 0)) {
              double d1 = xmul(poly[k][y], poly[k][y + 1], poly[i][x]);
              double d2 = xmul(poly[k][y], poly[k][y + 1], poly[i][x + 1]);
              int t = 1;
              if (t2 >= 0) t = -1;
              keys[keysize++] = make_pair(max(min(d1 / (d1 - d2), 1.), 0.), t);
            }
          }
      sort(keys, keys + keysize);
      int cnt = 0;
      double s = 0, tmp = 0;
      bool f = 1;
      for (int j = 0; j < keysize; ++j) {
        cnt += keys[j].second;
        if (!cnt && !f) tmp = keys[j].first, f = 1;
        if (cnt && f) s += keys[j].first - tmp, f = 0;
      }
      s += 1. - tmp;
      res += (poly[i][x] * poly[i][x + 1]) * s;
    }
  return res * 0.5;
}
int main() {
  scanf("%d", &n);
  double res = 0;
  for (int i = 0; i < n; ++i) {
    poly[i].M = 4;
    poly[i].init();
    res += fabs((poly[i][1] - poly[i][0]) * (poly[i][2] - poly[i][1]));
  }
  printf("%.2f\n", res / solve());
  return 0;
}
