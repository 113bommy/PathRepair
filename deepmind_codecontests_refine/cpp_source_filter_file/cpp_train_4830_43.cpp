#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int n;
double len, delta;
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) {
    x = a;
    y = b;
  }
  friend Point operator*(Point a, double k) { return Point(a.x * k, a.y * k); }
  friend Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
  }
  friend Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
  }
} ans[305];
int main() {
  scanf("%d", &n);
  if (n <= 4) {
    printf("No solution\n");
    return 0;
  }
  len = 300;
  delta = 0.01;
  for (long long i = 1; i <= n - 1; ++i) {
    Point p = Point(cos(2.0 * pi / n * (i - 1)), sin(2.0 * pi / n * (i - 1)));
    ans[i] = ans[i - 1] + p * len;
    len += delta;
  }
  Point p = Point(cos(2.0 * pi / n * (n - 1)), sin(2.0 * pi / n * (n - 1)));
  ans[n] = ans[n - 1] - p * (ans[n - 1].x / p.y);
  for (long long i = 1; i <= n; ++i)
    printf("%.3lf %.3lf\n", ans[i].x, ans[i].y);
  return 0;
}
