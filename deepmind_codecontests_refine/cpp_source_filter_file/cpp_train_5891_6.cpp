#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 9;
struct Point {
  double x, y;
  Point operator-(const Point& b) const { return (Point){x - b.x, y - b.y}; }
} p[N];
double dis2(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double dis(Point a, Point b) { return sqrt(dis2(a, b)); }
double cross(Point a, Point b) { return a.x * b.y - b.x * a.y; }
double solve(Point a, Point c, Point b) {
  return cross(c - a, b - a) / dis(a, b);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
  double ans = 10000000000;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, solve(p[i], p[(i + 1) % n], p[(i + 2) % n]));
  }
  printf("%.10f", ans / 2);
  return 0;
}
