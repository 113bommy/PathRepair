#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
struct Point {
  long long x, y;
  bool operator<(const Point& b) const {
    if (x == b.x) return y < b.y;
    return x < b.x;
  }
} pmx[N], pmn[N], ch[N];
long long cross(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
int Andrew(Point p[], int n, Point ch[]) {
  sort(p, p + n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    while (m > 1 && cross(ch[m - 2], p[i], ch[m - 1]) >= 0) --m;
    ch[m++] = p[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; --i) {
    while (m > k && cross(ch[m - 2], p[i], ch[m - 1]) >= 0) --m;
    ch[m++] = p[i];
  }
  if (n > 1) --m;
  return m;
}
bool is_in(Point p, Point ch[], int n) {
  int a = 1, b = n - 1, c;
  if (cross(ch[0], ch[a], ch[b]) > 0) swap(a, b);
  if (cross(ch[0], ch[a], p) >= 0 || cross(ch[0], ch[b], p) <= 0) return 0;
  while (abs(a - b) > 1) {
    c = (a + b) / 2;
    if (cross(ch[0], ch[c], p) > 0)
      b = c;
    else
      a = c;
  }
  return cross(ch[a], ch[b], p) < 0;
}
int main() {
  int nmx, nmn;
  scanf("%d %d", &nmx, &nmn);
  int x, y;
  scanf("%d %d", &x, &y);
  for (int i = 0; i < nmx; ++i) scanf("%lld %lld", &pmx[i].x, &pmx[i].y);
  int yid = 0, xid = 0;
  for (int i = 0; i < nmn; ++i) {
    scanf("%lld %lld", &pmn[i].x, &pmn[i].y);
    if (pmn[i].y > pmn[yid].y) yid = i;
    if (pmn[i].x > pmn[yid].x) xid = i;
  }
  pmn[nmn++] = (Point){0, 0};
  pmn[nmn++] = (Point){0, pmn[yid].y};
  pmn[nmn++] = (Point){pmn[xid].x, 0};
  int m = Andrew(pmn, nmn, ch);
  for (int i = 0; i < nmx; ++i) {
    if (!is_in(pmx[i], ch, m)) {
      puts("Max");
      return 0;
    }
  }
  puts("Min");
  return 0;
}
