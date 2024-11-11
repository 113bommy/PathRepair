#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
struct Point {
  long long x, y;
  bool operator<(const Point &p) const {
    if (x != p.x)
      return x > p.x;
    else
      return y > p.y;
  }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }
} pt[maxn];
int stk[maxn], stnum;
set<pair<long long, long long> > has;
bool check(Point a, Point b, Point c) {
  return c.x * b.y * (b.x - a.x) * (a.y - c.y) <
         b.x * c.y * (a.x - c.x) * (b.y - a.y);
}
bool check2(Point a, Point b, Point c) {
  cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " "
       << c.y << endl;
  cout << c.x * b.y * (b.x - a.x) * (a.y - c.y) << " "
       << b.x * c.y * (a.x - c.x) * (b.y - a.y) << endl;
  cout << c.x * b.y * (b.x - a.x) * (a.y - c.y) -
              b.x * c.y * (a.x - c.x) * (b.y - a.y)
       << endl;
  return c.x * b.y * (b.x - a.x) * (a.y - c.y) <
         b.x * c.y * (a.x - c.x) * (b.y - a.y);
}
void convex(int n) {
  int i, j;
  stnum = 0;
  for (i = 0; i < n; i++) {
    while (stnum > 1 && check(pt[stk[stnum - 1]], pt[stk[stnum - 2]], pt[i]))
      stnum--;
    stk[stnum++] = i;
  }
  while (stnum > 1 && pt[stk[stnum - 1]].y <= pt[stk[stnum - 2]].y) stnum--;
  for (i = 0; i < stnum - 1; i++)
    if (pt[stk[i]].x != pt[stk[i + 1]].x) break;
  for (i = 0; i < stnum; i++) {
    has.insert(make_pair(pt[stk[i]].x, pt[stk[i]].y));
  }
}
long long a[maxn], b[maxn];
int main() {
  int n, tn, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d %I64d", &a[i], &b[i]);
    pt[i].x = a[i];
    pt[i].y = b[i];
  }
  sort(pt, pt + n);
  tn = unique(pt, pt + n) - pt;
  convex(tn);
  for (i = 0; i < n; i++) {
    if (has.find(make_pair(a[i], b[i])) != has.end()) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
  return 0;
}
