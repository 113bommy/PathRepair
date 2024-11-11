#include <bits/stdc++.h>
using namespace std;
const int N = 1111;
struct Point {
  long long x, y;
  bool red;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  bool operator<(const Point &o) const {
    return x < o.x || x == o.x && y < o.y;
  }
};
long long det(const Point &p1, const Point &p2) {
  return p1.x * p2.y - p2.x * p1.y;
}
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
int n, m;
Point a[N];
bool cmp(const Point &p1, const Point &p2) { return det(p1, p2) > 0; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n + m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i].x = x;
    a[i].y = y;
    a[i].red = i < n;
  }
  int ans = 0;
  sort(a, a + n + m);
  for (int i = 0; i < n + m; ++i)
    if (a[i].red) {
      vector<Point> v;
      for (int j = i + 1; j < n + m; ++j) {
        Point t = a[j];
        t.x -= a[i].x;
        t.y -= a[i].y;
        v.push_back(t);
      }
      sort(v.begin(), v.end(), cmp);
      for (int j = 0; j < (int)v.size(); ++j)
        if (v[j].red) {
          bool blue = false;
          Point pnt;
          for (int k = j + 1; k < (int)v.size(); ++k)
            if (v[k].red) {
              if (!blue || det(v[k] - pnt, pnt - v[j]) < 0) ans++;
            } else {
              if (!blue || det(pnt - v[j], v[k] - pnt) > 0) {
                blue = true;
                pnt = v[k];
              }
            }
        }
    }
  printf("%d\n", ans);
}
