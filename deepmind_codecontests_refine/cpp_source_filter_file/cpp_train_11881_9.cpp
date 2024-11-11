#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxn = 500 + 2;
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
};
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator*(Point a, double r) { return Point(a.x * r, a.y * r); }
Point operator/(Point a, double r) { return Point(a.x / r, a.y / r); }
int sig(double rt) { return (rt > eps) - (rt < -eps); };
double det(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
struct Rect {
  Point d[5];
  void read() {
    for (int i = 0; i < 4; i++) scanf("%lf%lf", &d[i].x, &d[i].y);
    d[4] = d[0];
  }
  Point operator[](const int &n) { return d[n]; }
} r[maxn];
int n;
pair<double, short> res[maxn];
double getLoc(Point a, Point b, Point p) {
  if (sig(b.x - a.x)) return (p.x - a.x) / (b.x - a.x);
  return (p.y - a.y) / (b.y - a.y);
}
double work() {
  double rt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++) {
      int size = 0;
      res[size++] = pair<double, short>(0, 0);
      res[size++] = pair<double, short>(1, 0);
      for (int t = 0; t < n; t++) {
        if (t == i) continue;
        for (int g = 0; g < 4; g++) {
          int da = sig(det(r[i][j + 1] - r[i][j], r[t][g] - r[i][j]));
          int db = sig(det(r[i][j + 1] - r[i][j], r[t][g + 1] - r[i][j]));
          if (!da && !db) {
            if (sig(dot(r[i][j + 1] - r[i][j], r[t][g + 1] - r[t][g])) < 0 ||
                i < t) {
              res[size++] =
                  pair<double, short>(getLoc(r[i][j], r[i][j + 1], r[t][g]), 1);
              res[size++] = pair<double, short>(
                  getLoc(r[i][j], r[i][j + 1], r[t][g + 1]), -1);
            }
          } else {
            double s1 = det(r[i][j] - r[t][g], r[t][g + 1] - r[t][g]);
            double s2 = det(r[t][g + 1] - r[t][g], r[i][j + 1] - r[t][g]);
            if (da >= 0 && db < 0)
              res[size++] = pair<double, short>(s1 / (s1 + s2), 1);
            else if (da < 0 && db >= 0)
              res[size++] = pair<double, short>(s1 / (s1 + s2), -1);
          }
        }
      }
      sort(res, res + size);
      int cnt = 0;
      size--;
      double tmp = rt;
      for (int t = 0; t < size; t++) {
        cnt += res[t].second;
        if (cnt == 0 && sig(res[t].first - res[t + 1].first)) {
          double a = res[t].first;
          if (a < 0) a = 0;
          if (a > 1) break;
          double b = res[t + 1].first;
          if (b < 0) continue;
          if (b > 1) b = 1;
          rt += det((r[i][j + 1] - r[i][j]) * a + r[i][j],
                    (r[i][j + 1] - r[i][j]) * b + r[i][j]);
        }
      }
    }
  return rt / 2;
}
int main() {
  double cur = 0, rt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cur = 0;
    r[i].read();
    for (int j = 0; j < 4; j++) cur += det(r[i].d[j], r[i].d[j + 1]);
    if (cur < 0) {
      swap(r[i].d[0], r[i].d[3]);
      swap(r[i].d[1], r[i].d[2]);
      r[i].d[4] = r[i].d[0];
      cur = -cur;
    }
    rt += cur / 2;
  }
  printf("%.10lf\n", rt / work());
  return 0;
}
