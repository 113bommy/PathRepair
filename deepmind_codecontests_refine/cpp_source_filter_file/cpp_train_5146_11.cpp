#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool rd(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void pt(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) pt(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 10;
const int inf = 1e9;
const double eps = 1e-6;
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
} a[N], b[N];
int n, m;
double cx, cy, C;
double good_x, good_y;
double cal(double x, double y) {
  double ans = 0;
  for (int i = 0; i < n; i++)
    ans += (a[i].x - x) * (a[i].x - x) + (a[i].y - y) * (a[i].y - y);
  return ans;
}
double area(Point x, Point y, Point z) {
  return abs(x.x * y.y + y.x * z.y + z.x * x.y - x.x * z.y - y.x * x.y -
             z.x * y.y) /
         2.0;
}
double work(Point x) {
  double ans = 0;
  for (int i = 0; i < m; i++) ans += area(x, b[i], b[(i + 1) % m]);
  return ans;
}
double papa(Point x) {
  return n * x.x * x.x + n * x.y * x.y - 2 * x.x * cx - 2 * x.y * cy;
}
Point cut(Point x, Point y, double k) {
  return Point(x.x + k * (y.x - x.x), x.y + k * (y.y - x.y));
}
double hehe(Point x, Point y) {
  double ans = min(papa(x), papa(y));
  if (y.x != x.x) {
    double k = (y.y - x.y) / (y.x - x.x), b = x.y - k * x.x;
    double _x = (k * cy + cx - n * k * b) / n / (1 + k * k);
    if (_x < min(x.x, y.x) || _x > max(x.x, y.x)) return ans;
    double _y = k * _x + b;
    ans = min(ans, papa(Point(_x, _y)));
  } else {
    if (min(x.y, y.y) <= good_y && good_y <= max(x.y, y.y))
      ans = min(ans, papa(Point(x.x, good_y)));
  }
  return ans;
}
int main() {
  rd(n);
  cx = cy = C = 0;
  for (int i = 0; i < n; i++) {
    rd(a[i].x), rd(a[i].y);
    cx += a[i].x;
    cy += a[i].y;
    C += a[i].x * a[i].x + a[i].y * a[i].y;
  }
  rd(m);
  for (int i = 0; i < m; i++) rd(b[i].x), rd(b[i].y);
  good_x = (double)cx / n;
  good_y = (double)cy / n;
  if (abs(work(b[0]) - work(Point(good_x, good_y))) < eps)
    printf("%.10f\n", cal(good_x, good_y));
  else {
    double ans = 1e19;
    for (int i = 0; i < m; i++) ans = min(ans, hehe(b[i], b[(1 + i) % m]));
    printf("%.10f\n", ans + C);
  }
  return 0;
}
