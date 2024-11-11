#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
bool operator==(const point& p1, const point& p2) {
  return p1.x == p2.x && p1.y == p2.y;
}
bool operator!=(const point& p1, const point& p2) { return !(p1 == p2); }
bool operator<(const point& p1, const point& p2) {
  return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}
bool operator>(const point& p1, const point& p2) {
  return p1.x == p2.x ? p1.y > p2.y : p1.x > p2.x;
}
int n, k;
point p[200010];
set<pair<int, int> > ss;
bool solve() {
  if (scanf("%d%d", &n, &k) == EOF) return false;
  ss.clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i].x, &p[i].y);
    ss.insert(make_pair(p[i].x, p[i].y));
  }
  sort(p, p + n);
  if (n == 1) {
    if (k == 0) {
      puts("1");
      printf("%.10lf %.10lf\n", (double)p[0].x, (double)p[0].y);
    } else {
      puts("-1");
    }
    return true;
  }
  if (k >= n) {
    puts("-1");
    return true;
  }
  set<point> ans;
  for (int i = 0; i <= k; ++i) {
    for (int j = n - 1; j >= n - k - 1; --j) {
      if (i + (n - 1 - j) > k) break;
      int x = (p[i].x + p[j].x), y = (p[i].y + p[j].y);
      int cnt = 0;
      for (int l = 0, r = n - 1; l <= r;) {
        point tmp(x - p[l].x, y - p[l].y);
        if (tmp == p[r]) {
          ++l;
          --r;
        } else if (tmp < p[r]) {
          --r;
          ++cnt;
        } else {
          ++l;
          ++cnt;
        }
      }
      if (cnt <= k) ans.insert(point(x, y));
    }
  }
  printf("%d\n", ans.size());
  for (set<point>::iterator i = ans.begin(); i != ans.end(); ++i)
    printf("%.10lf %.10lf\n", i->x / 2.0, i->y / 2.0);
  return true;
}
int main() {
  while (solve())
    ;
  return 0;
}
