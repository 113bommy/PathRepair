#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
struct point {
  int x, y;
} a[N], aa[N];
bool cmpx(point u, point v) { return u.x < v.x || (u.x == v.x && u.y < v.y); }
bool cmpy(point u, point v) { return u.y < v.y || (u.y == v.y && u.x < v.x); }
int n, cnt, b[N], ned[N], p[10], s[5];
map<int, int> rk;
int num, rt[N * 20], lc[N * 20], rc[N * 20], sum[N * 20];
void build(int &c, int l, int r) {
  c = ++num;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lc[c], l, mid), build(rc[c], mid + 1, r);
}
void update(int &c, int l, int r, int x, int o) {
  if (!c) c = ++num;
  sum[c] = sum[o] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    rc[c] = rc[o], update(lc[c], l, mid, x, lc[o]);
  else
    lc[c] = lc[o], update(rc[c], mid + 1, r, x, rc[o]);
}
int query(int A, int B, int l, int r, int x) {
  if (l == r) return sum[B] - sum[A];
  int mid = (l + r) >> 1;
  if (x <= mid)
    return query(lc[A], lc[B], l, mid, x);
  else
    return query(rc[A], rc[B], mid + 1, r, x) + sum[lc[B]] - sum[lc[A]];
}
void ppw() {
  for (int i = 1; i <= n; ++i) a[i].x = rk[a[i].x], a[i].y = rk[a[i].y];
  for (int i = 1; i <= n; ++i) aa[i].x = a[i].x, aa[i].y = a[i].y;
  sort(a + 1, a + 1 + n, cmpx), sort(aa + 1, aa + 1 + n, cmpy),
      build(rt[0], 1, cnt);
  for (int i = 1; i <= n; ++i) update(rt[i], 1, cnt, a[i].y, rt[i - 1]);
}
bool sov() {
  s[1] = ned[p[1]] + ned[p[4]] + ned[p[7]];
  s[2] = ned[p[2]] + ned[p[5]] + ned[p[8]] + s[1];
  s[3] = ned[p[1]] + ned[p[2]] + ned[p[3]];
  s[4] = ned[p[4]] + ned[p[5]] + ned[p[6]] + s[3];
  if (a[s[1]].x == a[s[1] + 1].x) return 0;
  if (a[s[2]].x == a[s[2] + 1].x) return 0;
  if (a[s[3]].y == a[s[3] + 1].y) return 0;
  if (a[s[4]].y == a[s[4] + 1].y) return 0;
  if (ned[p[1]] != query(rt[0], rt[s[1]], 1, cnt, aa[s[3]].y)) return 0;
  if (ned[p[2]] != query(rt[s[1]], rt[s[2]], 1, cnt, aa[s[3]].y)) return 0;
  if (ned[p[1]] + ned[p[4]] != query(rt[0], rt[s[1]], 1, cnt, aa[s[4]].y))
    return 0;
  if (ned[p[2]] + ned[p[5]] != query(rt[s[1]], rt[s[2]], 1, cnt, aa[s[4]].y))
    return 0;
  printf("%.8lf %.8lf\n", 1.0 * (b[a[s[1]].x] + b[a[s[1] + 1].x]) / 2.0,
         1.0 * (b[a[s[2]].x] + b[a[s[2] + 1].x]) / 2.0);
  printf("%.8lf %.8lf\n", 1.0 * (b[aa[s[3]].y] + b[aa[s[3] + 1].y]) / 2.0,
         1.0 * (b[aa[s[4]].y] + b[aa[s[4] + 1].y]) / 2.0);
  return 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
    b[++cnt] = a[i].x, b[++cnt] = a[i].y;
  }
  sort(b + 1, b + 1 + cnt);
  cnt = unique(b + 1, b + 1 + cnt) - (b + 1);
  for (int i = 1; i <= cnt; ++i) rk[b[i]] = i;
  ppw();
  for (int i = 1; i <= 9; ++i) scanf("%d", &ned[i]), p[i] = i;
  do {
    if (sov()) return 0;
  } while (next_permutation(p + 1, p + 1 + 9));
  puts("-1");
  return 0;
}
