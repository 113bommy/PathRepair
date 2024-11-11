#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, per[10], hs[maxn], T, R[maxn], sz[maxn * 20], lc[maxn * 20],
    rc[maxn * 20], tot, i, j;
int Ys[maxn], X1, X2, Y1, Y2;
int upd(int x, int l, int r, int k) {
  int y = ++tot;
  sz[y] = sz[x] + 1;
  lc[y] = lc[x];
  rc[y] = rc[x];
  if (l == r) return y;
  int mid = (l + r) >> 1;
  if (k <= mid)
    lc[y] = upd(lc[x], l, mid, k);
  else
    rc[y] = upd(rc[x], mid + 1, r, k);
  return y;
}
int cal(int x, int y, int l, int r, int L, int R) {
  if (sz[x] == sz[y]) return 0;
  if (L <= l && r <= R) return sz[y] - sz[x];
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid) ans += cal(lc[x], lc[y], l, mid, L, R);
  if (R > mid) ans += cal(rc[x], rc[y], mid + 1, r, L, R);
  return ans;
}
struct data {
  int x, y;
  bool operator<(const data& a) const { return x < a.x; }
} d[maxn];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", &d[i].x, &d[i].y);
  sort(d + 1, d + n + 1);
  for (i = 1; i <= n; i++) Ys[i] = d[i].y;
  sort(Ys + 1, Ys + n + 1);
  for (i = 1; i <= n; i++)
    R[i] = upd(R[i - 1], 1, n, lower_bound(Ys + 1, Ys + n + 1, d[i].y) - Ys);
  for (i = 0; i < 9; i++) scanf("%d", per + i);
  sort(per, per + 9);
  do {
    X1 = per[0] + per[1] + per[2];
    if (d[X1].x == d[X1 + 1].x) continue;
    X2 = X1 + per[3] + per[4] + per[5];
    if (d[X2].x == d[X2 + 1].x) continue;
    Y1 = per[0] + per[3] + per[6];
    if (Ys[Y1] == Ys[Y1 + 1]) continue;
    Y2 = Y1 + per[1] + per[4] + per[7];
    if (Ys[Y2] == Ys[Y2 + 1]) continue;
    if (cal(R[0], R[X1], 1, n, 1, Y1) != per[0]) continue;
    if (cal(R[0], R[X1], 1, n, Y1 + 1, Y2) != per[1]) continue;
    if (cal(R[X1], R[X2], 1, n, 1, Y1) != per[3]) continue;
    if (cal(R[X1], R[X2], 1, n, Y1 + 1, Y2) != per[4]) continue;
    printf("%f %f\n", d[X1].x + 0.5, d[X2].x + 0.5);
    printf("%f %f\n", Ys[Y1] + 0.5, Ys[Y2] + 0.5);
    return 0;
  } while (next_permutation(per, per + 9));
  puts("-1");
  return 0;
}
