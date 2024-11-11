#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int inf = 1e9 + 7;
const double EPS = 1e-15;
inline bool ZERO(double x) { return (fabs(x) < EPS); }
inline bool NEQ(double x, double y) { return (fabs(x - y) >= EPS); }
int n;
struct Point {
  double x, y;
  double angle, dis;
  Point() {}
  Point(double x0, double y0) : x(x0), y(y0) {}
} center;
bool operator!=(Point p1, Point p2) {
  return (NEQ(p1.x, p2.x) || NEQ(p1.y, p2.y));
}
typedef vector<Point> Polygon;
Polygon poly, poly1;
Point CenterOfPolygon(const Polygon &poly) {
  Point p, p0, p1, p2, p3;
  double m, m0;
  p1 = poly[0];
  p2 = poly[1];
  p.x = p.y = m = 0;
  for (int i = 2; i < poly.size(); i++) {
    p3 = poly[i];
    p0.x = (p1.x + p2.x + p3.x) / 3.0;
    p0.y = (p1.y + p2.y + p3.y) / 3.0;
    m0 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x -
         p3.y * p1.x;
    if (ZERO(m + m0)) {
      m0 += EPS;
    }
    p.x = (m * p.x + m0 * p0.x) / (m + m0);
    p.y = (m * p.y + m0 * p0.y) / (m + m0);
    m = m + m0;
    p2 = p3;
  }
  return p;
}
bool PointCmp(const Point &a, const Point &b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int judge() {
  for (int i = 0; i < n; i++) {
    if (poly[i] != poly1[i]) return 0;
  }
  return 1;
}
int main() {
  Point point;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &point.x, &point.y);
    poly.push_back(point);
  }
  center = CenterOfPolygon(poly);
  for (int i = 0; i < n; i++) {
    point = poly[i];
    poly1.push_back({2 * center.x - point.x, 2 * center.y - point.y});
  }
  sort(poly.begin(), poly.end(), PointCmp);
  sort(poly1.begin(), poly1.end(), PointCmp);
  if (poly[0] != poly1[0]) {
    double x = poly[0].x - poly1[0].x;
    double y = poly[0].y - poly1[0].y;
    for (int i = 0; i < n; i++) {
      poly1[i].x += x;
      poly1[i].y += y;
    }
  }
  if (judge())
    printf("YES");
  else
    printf("NO");
  return 0;
}
