#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxn = 1023000;
struct Point {
  long long x, y;
  Point() {}
  Point(long long _x, long long _y) { x = _x, y = _y; }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  double operator*(const Point &b) const {
    return (double)x * b.y - (double)y * b.x;
  }
};
Point st[maxn];
long long k, b;
int top, op;
int main() {
  int n, m, tmp;
  cin >> n >> m;
  st[++top] = Point(0, 0);
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      st[top = 1] = Point(0, 0);
      scanf("%d", &tmp);
      n += tmp, k = b = 0;
    } else if (op == 2) {
      Point tail = Point(n, -(n * k + b));
      scanf("%d", &tmp);
      n += tmp;
      while (top > 1 && (tail - st[top - 1]) * (st[top] - st[top - 1]) >= 0)
        top--;
      st[++top] = tail;
    } else {
      scanf("%d", &tmp);
      b += tmp;
      scanf("%d", &tmp);
      k += tmp;
    }
    while (top > 1 &&
           st[top].y + st[top].x * k - st[top - 1].y - st[top - 1].x * k >= 0)
      top--;
    printf("%lld %lld\n", st[top].x + 1, st[top].y + (st[top].x) * k + b);
  }
  return 0;
}
