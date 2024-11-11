#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  Point operator*(double b) const { return Point(x * b, y * b); }
  Point operator/(double b) const {
    if (b == 0) return Point(0, 0);
    return Point(x / b, y / b);
  }
  bool operator<(const Point &b) const {
    if (x == b.x) return y < b.y;
    return x < b.y;
  }
  double len2() { return x * x + y * y; }
  double len() { return sqrt(len2()); }
  void read() { cin >> x >> y; }
  void print() { cout << fixed << setprecision(9) << x << " " << y << endl; }
};
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double det(Point a, Point b) { return a.x * b.y - a.y * b.x; }
const double eps = 1e-8;
int dcmp(double x) {
  if (x > eps) return 1;
  if (x < -eps) return -1;
  return 0;
}
bool intersection(Point a, Point b, Point c, Point d, Point &e) {
  if (dcmp(det(b - a, d - c)) == 0) return false;
  double s1 = det(d - a, c - a), s2 = det(c - b, d - b);
  e = b - a;
  e = e * (s1 / (s1 + s2));
  e = e + a;
  return true;
}
const int maxn = 1011;
Point p[maxn];
Point get(Point a, Point b, Point c) {
  Point d = (b + c) / 2, e = (a + c) / 2;
  Point dd, ee;
  dd = d - b;
  ee = e - c;
  dd = Point(-dd.y, dd.x);
  ee = Point(-ee.y, ee.x);
  Point o;
  bool ok = intersection(d, d + dd, e, e + ee, o);
  return o;
}
int m;
int n;
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) p[i].read();
}
bool ruijiao(Point a, Point b, Point c) {
  return dcmp(dot(b - a, c - a)) > 0 && dcmp(dot(a - b, c - b)) > 0 &&
         dcmp(dot(a - c, b - c)) > 0;
}
bool online(Point a, Point b, Point c) { return dot(b - a, c - a) <= 0; }
void work() {
  double ans = -1;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++) {
        if (!ruijiao(p[i], p[j], p[k])) continue;
        Point tmp;
        tmp = get(p[i], p[j], p[k]);
        double T = (tmp - p[i]).len();
        bool ok = true;
        for (int l = 1; l <= n; l++)
          if (l != i && l != j && l != k) {
            if (dcmp((p[l] - tmp).len() - T) < 0) {
              ok = false;
              break;
            }
          }
        if (!ok) continue;
        ans = max(ans, T);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; j <= n; j++)
        for (int l = 1; l <= n; l++)
          if (i != j && i != k && i != l && j != k && j != l && k != l) {
            if (dcmp(dot(p[l] - p[i], p[j] - p[i])) == 0 &&
                dcmp(dot(p[k] - p[j], p[i] - p[j])) == 0 &&
                dcmp(dot(p[l] - p[k], p[j] - p[k])) == 0) {
              Point tmp;
              intersection(p[i], p[k], p[j], p[l], tmp);
              bool ok = true;
              double T = (p[i] - tmp).len();
              for (int q = 1; q <= n; q++)
                if (q != i && q != j && q != k && q != l) {
                  if (dcmp((p[q] - tmp).len() - T) < 0) {
                    ok = false;
                    break;
                  }
                }
              ans = max(ans, T);
            }
          }
  if (ans < 0)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(8) << ans << endl;
}
int main() {
  init();
  work();
  return 0;
}
