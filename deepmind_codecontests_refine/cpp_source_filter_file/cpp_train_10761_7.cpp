#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  bool operator<(const point &b) const { return x < b.x; }
};
struct interval {
  int h, l, r;
  bool operator<(const interval &b) const { return h < b.h; }
} p[100000 + 5];
int len[100000 + 5], n, t, dp[100000 + 5];
set<point> s;
int check(int a, int b, int l, int r) {
  if (max(p[a].l, p[b].l) != l) return 0;
  if (min(p[a].r, p[b].r) != r) return 0;
  len[b] = 0;
  return r - l;
}
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &p[i].h, &p[i].l, &p[i].r);
  sort(p + 1, p + 1 + n);
  s.insert(point(1e9, 0));
  p[0].l = -1e9, p[0].r = 1e9, dp[0] = 1e9;
  for (int i = 1; i <= n; i++) {
    len[i] = p[i].r - p[i].l;
    set<point>::iterator it = s.lower_bound(point(p[i].l, 0)), tmp;
    if (it->x != p[i].l)
      s.insert(point(p[i].l, it->y));
    else
      it++;
    int nowx = p[i].l;
    while (nowx < p[i].r) {
      if (it->x > p[i].r) s.insert(point(p[i].r, it->y)), it--;
      dp[i] = max(dp[i], min(dp[it->y], check(i, it->y, nowx, it->x)));
      nowx = it->x, tmp = it++, s.erase(tmp);
    }
    s.insert(point(p[i].r, i));
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (len[i]) ans = max(ans, dp[i]);
  printf("%d\n", ans);
  return 0;
}
