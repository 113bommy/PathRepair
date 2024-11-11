#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
int kx, ky;
struct Point {
  int x, y;
  char ch;
  Point() {}
  Point(int _x, int _y, char _ch) : x(_x), y(_y), ch(_ch) {}
};
Point p[maxn];
bool cmp1(const Point a, const Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmp2(const Point a, const Point b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
bool cmp3(const Point a, const Point b) {
  if (a.x + a.y == b.x + b.y)
    return a.x < b.x;
  else
    return a.x + a.y < b.x + b.y;
}
bool cmp4(const Point a, const Point b) {
  if (a.x - a.y == b.x - b.y)
    return a.x < b.x;
  else
    return a.x - a.y < b.x - b.y;
}
int main() {
  int n, x, y;
  while (~scanf("%d", &n)) {
    scanf("%d%d", &kx, &ky);
    p[0] = Point(kx, ky, 'K');
    char op[5];
    for (int i = 1; i <= n; i++) {
      scanf("%s%d%d", op, &x, &y);
      p[i] = Point(x, y, op[0]);
    }
    sort(p, p + n + 1, cmp1);
    int t;
    t = lower_bound(p, p + n + 1, Point(kx, ky, 'K'), cmp1) - p;
    if ((t > 0 && p[t - 1].x == kx && p[t - 1].ch != 'B') ||
        (t < n && p[t + 1].x == kx && p[t + 1].ch != 'B')) {
      puts("YES");
      continue;
    }
    sort(p, p + n + 1, cmp2);
    t = lower_bound(p, p + n + 1, Point(kx, ky, 'K'), cmp2) - p;
    if ((t > 0 && p[t - 1].y == ky && p[t - 1].ch != 'B') ||
        (t < n && p[t + 1].y == ky && p[t + 1].ch != 'B')) {
      puts("YES");
      continue;
    }
    sort(p, p + n + 1, cmp3);
    t = lower_bound(p, p + n + 1, Point(kx, ky, 'K'), cmp3) - p;
    if ((t > 0 && p[t - 1].x + p[t - 1].y == kx + ky && p[t - 1].ch != 'R') ||
        (t < n && p[t + 1].x + p[t + 1].y == kx + ky && p[t + 1].ch != 'R')) {
      puts("YES");
      continue;
    }
    sort(p, p + n + 1, cmp4);
    t = lower_bound(p, p + n + 1, Point(kx, ky, 'K'), cmp4) - p;
    if ((t > 0 && p[t - 1].x - p[t - 1].y == kx - ky && p[t - 1].ch != 'R') ||
        (t < n && p[t + 1].x - p[t + 1].y == kx - ky && p[t + 1].ch != 'R')) {
      puts("YES");
      continue;
    }
    puts("NO");
  }
  return 0;
}
