#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;
struct Point {
  int x, y, l, r;
  bool ok;
} a[maxn], b[maxn];
inline bool cmp1(const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
inline bool cmp2(const Point& a, const Point& b) {
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}
bool vis[maxn][maxn];
vector<int> has;
inline bool check(int t, int n, int m) {
  for (int i = 1; i <= n; i++) {
    a[i].l = a[i].y - 2 * t;
    a[i].r = a[i].y + 2 * t;
    a[i].ok = 1;
    if (i && a[i - 1].x == a[i].x && a[i].l <= a[i - 1].r) {
      a[i].l = a[i - 1].l;
      a[i - 1].ok = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    b[i].l = b[i].x - 2 * t;
    b[i].r = b[i].x + 2 * t;
    b[i].ok = 1;
    if (i && b[i - 1].y == b[i].y && b[i].l <= b[i - 1].r) {
      b[i].l = b[i - 1].l;
      b[i - 1].ok = 0;
    }
  }
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i++) {
    if (!a[i].ok) continue;
    has.clear();
    for (int j = 1; j <= m; j++) {
      if (!b[j].ok) continue;
      if (a[i].l <= b[j].y && b[j].y <= a[i].r && b[j].l <= a[i].x &&
          a[i].x <= b[j].r)
        has.push_back(j);
    }
    int sz = has.size();
    for (int j = 0; j < sz - 1; j++) {
      for (int k = j + 1; k < sz; k++) {
        if (vis[has[j]][has[k]]) return 1;
        vis[has[j]][has[k]] = vis[has[k]][has[j]] = 1;
      }
    }
  }
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i].x = x + y;
    a[i].y = y - x;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    b[i].x = x + y;
    b[i].y = y - x;
  }
  sort(a + 1, a + n + 1, cmp1);
  sort(b + 1, b + m + 1, cmp2);
  int l = 1, r = inf, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid, n, m)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (ans == -1)
    puts("Poor Sereja!");
  else
    printf("%d\n", ans);
  return 0;
}
