#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int inf = 1e9;
class Point {
 public:
  int x;
  int y;
  bool operator<(const Point &) const;
};
class Range {
 public:
  int x;
  int b;
  int t;
};
bool Point::operator<(const Point &rhs) const { return x < rhs.x; }
int n;
Point p[maxn];
int rcnt;
Range r[maxn];
int lminy[maxn + 1];
int lmaxy[maxn + 1];
int rminy[maxn + 1];
int rmaxy[maxn + 1];
int main(void) {
  int i;
  int x, y;
  int low, mid, high;
  int first, last;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &x, &y);
    p[i].x = x + y;
    p[i].y = -x + y;
  }
  sort(p, p + n);
  rcnt = 1;
  r[0].x = p[0].x;
  r[0].b = p[0].y;
  r[0].t = p[0].y;
  for (i = 1; i < n; ++i) {
    if (p[i].x > r[rcnt - 1].x) {
      r[rcnt].x = p[i].x;
      r[rcnt].b = p[i].y;
      r[rcnt].t = p[i].y;
      ++rcnt;
    } else {
      r[rcnt - 1].b = min(r[rcnt - 1].b, p[i].y);
      r[rcnt - 1].t = max(r[rcnt - 1].t, p[i].y);
    }
  }
  lminy[0] = inf;
  lmaxy[0] = -inf;
  for (i = 0; i < rcnt; ++i) {
    lminy[i + 1] = min(lminy[i], r[i].b);
    lmaxy[i + 1] = max(lmaxy[i], r[i].t);
  }
  rminy[0] = inf;
  rmaxy[0] = -inf;
  for (i = 0; i < rcnt; ++i) {
    rminy[i + 1] = min(rminy[i], r[rcnt - i - 1].b);
    rmaxy[i + 1] = max(rmaxy[i], r[rcnt - i - 1].t);
  }
  low = -1;
  high = inf * 2;
  for (; low < high - 1;) {
    mid = low + (high - low) / 2;
    last = 0;
    for (first = 0; first < rcnt; ++first) {
      for (; last < rcnt && r[last].x <= r[first].x + mid; ++last)
        ;
      if (max(lmaxy[first], rmaxy[rcnt - last]) -
              min(lminy[first], rminy[rcnt - last]) <=
          mid)
        break;
    }
    if (first < rcnt)
      high = mid;
    else
      low = mid;
  }
  printf("%d", high / 2);
  if (high % 2 == 1) printf(".5");
  printf("\n");
  return 0;
}
