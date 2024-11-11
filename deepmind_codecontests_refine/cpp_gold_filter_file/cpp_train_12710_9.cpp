#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 16000010;
int xm, ym, zm, n, m, k, cnt;
int ml, mr, dl, dr, sl, sr;
int rt[N << 2], lc[M], rc[M], lv[M], rv[M];
void modify_2d(int &u, int l, int r, int y, int z) {
  if (!u) u = ++cnt, rv[u] = zm + 1;
  if (z <= sr) lv[u] = max(lv[u], z);
  if (z >= sl) rv[u] = min(rv[u], z);
  if (l == r) return;
  int mid = (l + r) / 2;
  if (y <= mid)
    modify_2d(lc[u], l, mid, y, z);
  else
    modify_2d(rc[u], mid + 1, r, y, z);
}
void modify_1d(int u, int l, int r, int x, int y, int z) {
  modify_2d(rt[u], 1, ym, y, z);
  if (l == r) return;
  int mid = (l + r) / 2;
  if (x <= mid)
    modify_1d(u << 1, l, mid, x, y, z);
  else
    modify_1d(u << 1 | 1, mid + 1, r, x, y, z);
}
int query_2d(int u, int l, int r, int yl, int yr, int zl, int zr) {
  if (!u) return 1;
  if (yl <= l && yr >= r) return zl > lv[u] && zr < rv[u];
  bool res = 1;
  int mid = (l + r) / 2;
  if (yl <= mid) res &= query_2d(lc[u], l, mid, yl, yr, zl, zr);
  if (yr > mid) res &= query_2d(rc[u], mid + 1, r, yl, yr, zl, zr);
  return res;
}
int query_1d(int u, int l, int r, int xl, int xr, int yl, int yr, int zl,
             int zr) {
  if (xl <= l && xr >= r) return query_2d(rt[u], 1, ym, yl, yr, zl, zr);
  bool res = 1;
  int mid = (l + r) / 2;
  if (xl <= mid) res &= query_1d(u << 1, l, mid, xl, xr, yl, yr, zl, zr);
  if (xr > mid) res &= query_1d(u << 1 | 1, mid + 1, r, xl, xr, yl, yr, zl, zr);
  return res;
}
bool in(int x, int y, int z) {
  return x >= ml && x <= mr && y >= dl && y <= dr && z >= sl && z <= sr;
}
int main() {
  scanf("%d%d%d%d%d%d", &xm, &ym, &zm, &n, &m, &k);
  ml = xm, mr = 1;
  dl = ym, dr = 1;
  sl = zm, sr = 1;
  int x, y, z;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    ml = min(ml, x), mr = max(mr, x);
    dl = min(dl, y), dr = max(dr, y);
    sl = min(sl, z), sr = max(sr, z);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (in(x, y, z)) {
      printf("INCORRECT\n");
      return 0;
    }
    modify_1d(1, 1, xm, x, y, z);
  }
  printf("CORRECT\n");
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (in(x, y, z))
      printf("OPEN\n");
    else if (query_1d(1, 1, xm, min(ml, x), max(mr, x), min(dl, y), max(dr, y),
                      min(sl, z), max(sr, z)))
      printf("UNKNOWN\n");
    else
      printf("CLOSED\n");
  }
}
