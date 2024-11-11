#include <bits/stdc++.h>
using namespace std;
double l, r, w, k;
int i, n, m, t;
struct point {
  int x, y;
  point(int x0 = 0, int y0 = 0) {
    x = x0;
    y = y0;
  }
  point operator+(point u) { return point(x + u.x, y + u.y); }
  point operator-(point u) { return point(x - u.x, y - u.y); }
  int operator*(point u) { return x * u.x + y * u.y; }
  int operator/(point u) { return x * u.y - y * u.x; }
  int operator<(point u) const { return x == u.x ? y < u.y : x < u.x; }
  int operator>=(point u) { return x >= u.x && y >= u.y; }
  int operator<=(point u) { return x <= u.x && y <= u.y; }
} p, a[10001], b[10001], c[20001];
point max(point u, point v) { return point(max(u.x, v.x), max(u.y, v.y)); }
point min(point u, point v) { return point(min(u.x, v.x), min(u.y, v.y)); }
int check(point x, point y) {
  l = -1e18;
  r = 1e18;
  for (i = 1; i <= n; i++) {
    p = a[i];
    if (!((x - p) / (y - p))) continue;
    w = 1.0 * ((x - p) * (y - p)) / ((x - p) / (y - p));
    if ((p - x) / (y - x) < 0)
      l = max(l, w);
    else
      r = min(r, w);
  }
  for (i = 1; i <= m; i++) {
    p = b[i];
    if (!((x - p) / (y - p))) {
      if (p >= min(x, y) && p <= max(x, y)) return 0;
      continue;
    }
    w = 1.0 * ((x - p) * (y - p)) / ((x - p) / (y - p));
    if ((p - x) / (y - x) > 0)
      l = max(l, w);
    else
      r = min(r, w);
  }
  return l + 0.00000001 < r;
}
int dfs(int l, int r) {
  if (check(c[l], c[r])) return 1;
  if (l + 1 == r) return 0;
  k = 1e18;
  int ans;
  point x = c[l], y = c[r];
  for (i = l + 1; i < r; i++) {
    p = c[i];
    w = 1.0 * ((p - x) * (p - y)) / ((p - x) / (p - y));
    if (w < k) ans = i, k = w;
  }
  return dfs(l, ans) || dfs(ans, r);
}
int check() {
  t = 0;
  for (i = 1; i <= n; i++) {
    while (t > 1 && (c[t] - c[t - 1]) / (a[i] - c[t - 1]) <= 0) t--;
    c[++t] = a[i];
  }
  k = t;
  for (i = n - 1; i; i--) {
    while (t > k && (c[t] - c[t - 1]) / (a[i] - c[t - 1]) <= 0) t--;
    c[++t] = a[i];
  }
  t--;
  return dfs(1, t);
}
signed main() {
  scanf("%d%d", &n, &m);
  if (n == 1 || m == 1) return puts("YES"), 0;
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (i = 1; i <= m; i++) scanf("%d%d", &b[i].x, &b[i].y);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  puts(check() || (swap(a, b), swap(n, m), check()) ? "YES" : "NO");
}
