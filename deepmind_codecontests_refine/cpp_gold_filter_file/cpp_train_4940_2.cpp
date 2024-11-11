#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int n, m;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
struct surf {
  int xl, xr, yl, yr, h, id;
} s[maxn];
inline int cmps(surf x, surf y) { return x.h < y.h; }
struct point {
  int x, y, id;
} p[maxn];
inline int cmpx(point x, point y) { return x.x < y.x; }
inline int cmpy(point x, point y) { return x.y < y.y; }
struct node {
  int xl, xr, yl, yr, id;
} tr[maxn << 2], w;
inline void build(int h, int l, int r, int k) {
  if (l == r) {
    tr[h].xl = tr[h].xr = p[l].x;
    tr[h].yl = tr[h].yr = p[l].y;
    tr[h].id = p[l].id;
    return;
  }
  int mid = (l + r) >> 1;
  nth_element(p + l, p + mid, p + r + 1, k ? cmpx : cmpy);
  build(h << 1, l, mid, k ^ 1);
  build(h << 1 | 1, mid + 1, r, k ^ 1);
  int ls = h << 1, rs = h << 1 | 1;
  tr[h].id = min(tr[ls].id, tr[rs].id);
  tr[h].xl = min(tr[ls].xl, tr[rs].xl);
  tr[h].yl = min(tr[ls].yl, tr[rs].yl);
  tr[h].xr = max(tr[ls].xr, tr[rs].xr);
  tr[h].yr = max(tr[ls].yr, tr[rs].yr);
}
inline void bl(int h, int l, int r) {
  printf("%d %d %d %d %d %d\n", h, tr[h].id, tr[h].xl, tr[h].xr, tr[h].yl,
         tr[h].yr);
  if (l == r) return;
  int mid = (l + r) >> 1;
  bl(h << 1, l, mid);
  bl(h << 1 | 1, mid + 1, r);
}
int pos[maxn], ans[maxn];
inline void query(int h) {
  if (tr[h].id > w.id || tr[h].xl > w.xr || tr[h].xr < w.xl ||
      tr[h].yl > w.yr || tr[h].yr < w.yl)
    return;
  if (tr[h].xl >= w.xl && tr[h].xr <= w.xr && tr[h].yl >= w.yl &&
      tr[h].yr <= w.yr)
    return void(w.id = tr[h].id);
  if (tr[h << 1].id < tr[h << 1 | 1].id)
    query(h << 1), query(h << 1 | 1);
  else
    query(h << 1 | 1), query(h << 1);
}
inline void update(int h, int l, int r, int x) {
  if (l == r) return void(tr[h].id = m + 1);
  int mid = (l + r) >> 1;
  if (mid >= x)
    update(h << 1, l, mid, x);
  else
    update(h << 1 | 1, mid + 1, r, x);
  tr[h].id = min(tr[h << 1].id, tr[h << 1 | 1].id);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    s[i].xl = read(), s[i].xr = read();
    s[i].yl = read(), s[i].yr = read();
    s[i].h = read(), s[i].id = i;
  }
  sort(s + 1, s + 1 + n, cmps);
  m = read();
  for (int i = 1; i <= m; i++) {
    p[i].x = read(), p[i].y = read();
    p[i].id = i;
  }
  build(1, 1, m, 0);
  for (int i = 1; i <= m; i++) pos[p[i].id] = i;
  for (int i = 1; i <= n; i++) {
    w = (node){s[i].xl, s[i].xr, s[i].yl, s[i].yr, m + 1};
    query(1);
    if (w.id == m + 1) continue;
    ans[w.id] = s[i].id;
    update(1, 1, m, pos[w.id]);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
