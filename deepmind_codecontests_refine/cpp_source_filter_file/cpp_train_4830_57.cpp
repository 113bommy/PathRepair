#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1);
double x, y;
int n;
struct point {
  double x, y;
  double operator*(const point& a) const { return x * a.x - y * a.y; }
  point operator+(const point& a) const { return (point){x + a.x, y + a.y}; }
  point operator*(const double& a) const { return (point){a * x, a * y}; }
  point operator-(const point& a) const { return (point){x - a.x, y - a.y}; }
} pos[105], id[105];
point rot(point a, double x, double y) {
  return (point){a.x * x - a.y * y, a.x * y + a.y * x};
}
int main() {
  scanf("%d", &n);
  if (n <= 4) {
    printf("No solution");
    return 0;
  }
  double l = 200;
  point q;
  for (int i = 1; i < n; ++i) {
    q = (point){cos(2 * Pi / n * (i - 1)), sin(2 * Pi / n * (i - 1))};
    id[i] = id[i - 1] + q * l;
    l += 0.01;
  }
  q = (point){cos(2 * Pi / n * (n - 1)), sin(2 * Pi / n * (n - 1))};
  id[n] = id[n - 1] - q * (id[n - 1].y / q.y);
  for (int i = 1; i <= n; ++i) printf("%.3lf %.3lf\n", id[i].x, id[i].y);
  return 0;
}
