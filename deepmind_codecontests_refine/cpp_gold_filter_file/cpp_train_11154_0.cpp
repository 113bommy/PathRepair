#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  Point operator-(const Point &p) const { return {x - p.x, y - p.y}; }
  double operator*(const Point &p) const {
    return (double)x * p.y - (double)y * p.x;
  }
} q[300005], now;
int n, m, top;
long long k, b;
int main() {
  scanf("%d%d", &n, &m);
  q[top = 1] = Point(0, 0);
  int op, x, y;
  while (m--) {
    scanf("%d%d", &op, &x);
    switch (op) {
      case 1:
        k = b = 0, q[top = 1] = Point(0, 0), n += x;
        break;
      case 2:
        now = Point(n, -(n * k + b)), n += x;
        while (top > 1 && (q[top] - q[top - 1]) * (now - q[top - 1]) < eps)
          top--;
        q[++top] = now;
        break;
      case 3:
        scanf("%d", &y), b += x, k += y;
        break;
    }
    now = Point(-1, k);
    while (top > 1 && (q[top - 1] - q[top]) * now < eps) top--;
    printf("%I64d %I64d\n", q[top].x + 1, q[top].x * k + b + q[top].y);
  }
}
