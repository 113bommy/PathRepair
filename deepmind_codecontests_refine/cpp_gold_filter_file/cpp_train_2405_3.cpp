#include <bits/stdc++.h>
using namespace std;
long long a1, a2, b1, b2, c1, c2;
struct Point {
  long long x, y;
  Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};
int exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - a / b * y;
  return d;
}
int dcmp(int x) {
  if (x == 0) return 0;
  return x < 0 ? -1 : 1;
}
Point operator+(const Point& a, const Point& b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point ans[5];
int main() {
  scanf("%lld %lld %lld %lld %lld %lld", &a1, &a2, &b1, &b2, &c1, &c2);
  ans[1] = Point(b1 - a1, b2 - a2);
  ans[2] = Point(b1 - a2, b2 + a1);
  ans[3] = Point(b1 + a1, b2 + a2);
  ans[4] = Point(b1 + a2, b2 - a1);
  if (c1 == 0 && c2 == 0) {
    for (int i = 1; i <= 4; i++)
      if (ans[i].x == 0 && ans[i].y == 0) {
        printf("YES\n");
        return 0;
      }
    printf("NO\n");
    return 0;
  }
  for (int i = 1; i <= 4; i++) {
    long long t1, t2;
    if ((c1 * ans[i].x + c2 * ans[i].y) % (c1 * c1 + c2 * c2) != 0) continue;
    t1 = (c1 * ans[i].x + c2 * ans[i].y) / (c1 * c1 + c2 * c2);
    if ((c2 * ans[i].x - c1 * ans[i].y) % (c1 * c1 + c2 * c2) != 0) continue;
    t2 = (c2 * ans[i].x - c1 * ans[i].y) / (c1 * c1 + c2 * c2);
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
}
