#include <bits/stdc++.h>
using namespace std;
int dcmp(double x) {
  if (fabs(x) < 1e-10)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  bool operator<(const Point &a) const {
    return dcmp(x - a.x) < 0 || (dcmp(x - a.x) == 0 && dcmp(y - a.y) < 0);
  }
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  void read() { scanf("%lf%lf", &x, &y); }
};
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, double b) { return Point(a.x * b, a.y * b); }
Point operator/(Point a, double b) { return Point(a.x / b, a.y / b); }
bool operator==(Point a, Point b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double Length(Point a) { return sqrt(Dot(a, a)); }
double Angle(Point a, Point b) {
  return acos(min(1.0, max(-1.0, Dot(a, b) / Length(a) / Length(b))));
}
double Cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
Point Normal(Point a) { return a / Length(a); }
Point Rotate(Point a, double rad) {
  return Point(a.x * cos(rad) - a.y * sin(rad),
               a.x * sin(rad) + a.y * cos(rad));
}
double DistanceToSegment(Point p, Point a, Point b) {
  if (a == b) return Length(p - a);
  Point v1 = b - a, v2 = p - a, v3 = p - b;
  if (dcmp(Dot(v1, v2)) < 0)
    return Length(v2);
  else if (dcmp(Dot(v1, v3)) > 0)
    return Length(v3);
  else
    return fabs(Cross(v1, v2)) / Length(v1);
}
Point a[100010], b[100010];
int main() {
  int n;
  scanf("%d", &n);
  double d1, d2;
  scanf("%lf%lf", &d1, &d2);
  for (int i = 0; i < n; i++) a[i].read(), b[i].read();
  bool fg = 1;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    Point va = a[i + 1] - a[i], vb = b[i + 1] - b[i], v = va - vb;
    double d = DistanceToSegment(b[i], a[i], a[i] + v);
    double l1 = Length(b[i] - a[i]), l2 = Length(b[i] - (a[i] + v));
    if (dcmp(d - l1) < 0 && dcmp(d - l2) < 0) {
      if (dcmp(d - d1) <= 0) {
        if (dcmp(l1 - d2) > 0) fg = 1;
        if (fg) ans++, fg = 0;
        if (dcmp(l2 - d2) > 0) fg = 1;
      } else if (dcmp(l1 - d2) > 0 || dcmp(l2 - d2) > 0)
        fg = 1;
    } else if (dcmp(d - l1) == 0) {
      if (fg && dcmp(l1 - d1) <= 0) ans++, fg = 0;
      if (dcmp(l2 - d2) > 0) fg = 1;
    } else {
      if (dcmp(l1 - d2) > 0) fg = 1;
      if (dcmp(l2 - d1) < 0) ans++, fg = 0;
    }
  }
  if (fg && dcmp(Length(a[n - 1] - b[n - 1]) - d1) == 0) ans++;
  cout << ans << endl;
}
