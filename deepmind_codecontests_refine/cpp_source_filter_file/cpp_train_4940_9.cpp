#include <bits/stdc++.h>
constexpr int N(1e5 + 5);
struct _rect {
  int xl, xr, yl, yr, z, id;
  void read(void) { scanf("%d%d%d%d%d", &xl, &xr, &yl, &yr, &z); }
  bool operator<(const _rect &o) const { return z < o.z; }
} rect[N];
struct dot {
  int x, y, id;
} p[N];
bool cmpX(const dot &a, const dot &b) { return a.x < b.x; }
bool cmpY(const dot &a, const dot &b) { return a.y < b.y; }
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x > y ? x : y; }
int xl[N << 2], xr[N << 2], yl[N << 2], yr[N << 2], mn[N << 2], m;
void build(int i, int l, int r, bool tp) {
  if (l == r) {
    xl[i] = xr[i] = p[l].x;
    yl[i] = yr[i] = p[l].y;
    mn[i] = p[l].id;
    return;
  }
  int mid((l + r) >> 1);
  std::nth_element(p + l, p + mid, p + r + 1, tp ? cmpX : cmpY);
  build(i << 1, l, mid, tp ^ 1);
  build(i << 1 | 1, mid + 1, r, tp ^ 1);
  xl[i] = min(xl[i << 1], xl[i << 1 | 1]);
  xr[i] = max(xr[i << 1], xr[i << 1 | 1]);
  yl[i] = min(yl[i << 1], yl[i << 1 | 1]);
  yr[i] = max(yr[i << 1], yr[i << 1 | 1]);
  mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
}
int qxl, qxr, qyl, qyr, qV;
void query(int i) {
  if (mn[i] > qV || xr[i] < qxl || xl[i] > qxr || yr[i] < qyl || yl[i] > qyr)
    return;
  if (qxl <= xl[i] && xr[i] <= qxr && qyl <= yl[i] && yr[i] <= qyr) {
    qV = std::min(qV, mn[i]);
    return;
  }
  if (mn[i << 1] < mn[i << 1 | 1])
    query(i << 1), query(i << 1 | 1);
  else
    query(i << 1 | 1), query(i << 1);
}
void modify(int idx) {
  int i(1), l(1), r(m), mid;
  while (l != r) {
    mid = (l + r) >> 1;
    if (idx <= mid)
      i <<= 1, r = mid;
    else
      (i <<= 1) |= 1, l = mid + 1;
  }
  mn[i] = m + 1;
  while ((i >>= 1)) mn[i] = std::min(mn[i << 1], mn[i << 1 | 1]);
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i(1); i <= n; ++i) rect[i].read(), rect[i].id = i;
  std::sort(rect + 1, rect + n + 1);
  scanf("%d", &m);
  for (int i(1); i <= m; ++i) scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;
  build(1, 1, m, 0);
  static int pos[N], ans[N];
  for (int i(1); i <= m; ++i) pos[p[i].id] = i;
  for (int i(1); i <= n; ++i) {
    qxl = rect[i].xl, qxr = rect[i].xr, qyl = rect[i].yl, qyr = rect[i].yr,
    qV = n + 1;
    query(1);
    if (qV > m) continue;
    ans[qV] = rect[i].id;
    modify(pos[qV]);
  }
  for (int i(1); i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
