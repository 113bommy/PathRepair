#include <bits/stdc++.h>
using namespace std;
struct aaa {
  int x, y, op;
} a[500010];
int ans, cnt, n, tx, ty, tot, mx, e[1000010], nt[1000010], hd[1000010],
    dep[500010], ru[500010], chu[500010], id[500010], f[2000010][2][2],
    val[1000010], d[500010], jl[500010][2], lz[2000010];
void build(int x, int y, int w) {
  tot++;
  e[tot] = y;
  val[tot] = w;
  nt[tot] = hd[x];
  hd[x] = tot;
}
void get(int x, int fa) {
  int i;
  dep[x] = dep[fa] + 1;
  if (dep[x] > dep[mx]) mx = x;
  for (i = hd[x]; i; i = nt[i]) {
    if (e[i] == fa) continue;
    get(e[i], x);
  }
}
void dfs(int x, int fa) {
  int i;
  ru[x] = ++cnt;
  id[cnt] = x;
  dep[x] = dep[fa] + 1;
  for (i = hd[x]; i; i = nt[i]) {
    if (e[i] == fa) continue;
    d[e[i]] = d[x] ^ val[i];
    dfs(e[i], x);
  }
  chu[x] = cnt;
}
void pushup(int x) {
  int i, j;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      f[x][i][j] = max(f[x * 2][i][j], f[x * 2 + 1][i][j]);
}
void build1(int x, int l, int r) {
  if (l == r) {
    if (d[id[l]] == 0) {
      f[x][0][0] = jl[id[l]][0];
      f[x][1][0] = jl[id[l]][1];
    } else {
      f[x][0][1] = jl[id[l]][0];
      f[x][1][1] = jl[id[l]][1];
    }
    return;
  }
  int mid = (l + r) / 2;
  build1(x * 2, l, mid);
  build1(x * 2 + 1, mid + 1, r);
  pushup(x);
}
void pushdown(int x) {
  if (lz[x]) {
    lz[x * 2] ^= 1;
    lz[x * 2 + 1] ^= 1;
    lz[x] = 0;
    swap(f[x * 2][0][0], f[x * 2][0][1]);
    swap(f[x * 2][1][0], f[x * 2][1][1]);
    swap(f[x * 2 + 1][0][0], f[x * 2 + 1][0][1]);
    swap(f[x * 2 + 1][1][0], f[x * 2 + 1][1][1]);
  }
}
void xiu(int x, int l, int r, int t, int k) {
  if (l == t && r == k) {
    lz[x] ^= 1;
    swap(f[x][0][0], f[x][0][1]);
    swap(f[x][1][0], f[x][1][1]);
    return;
  }
  pushdown(x);
  int mid = (l + r) / 2;
  if (mid >= k)
    xiu(x * 2, l, mid, t, k);
  else if (t > mid)
    xiu(x * 2 + 1, mid + 1, r, t, k);
  else
    xiu(x * 2, l, mid, t, mid), xiu(x * 2 + 1, mid + 1, r, mid + 1, k);
  pushup(x);
}
int get(int x, int l, int r, int t) {
  if (l == r) {
    return d[id[l]] ^ lz[x];
  }
  pushdown(x);
  int mid = (l + r) / 2;
  if (mid >= t)
    return get(x * 2, l, mid, t);
  else
    return get(x * 2 + 1, mid + 1, r, t);
}
int main() {
  int t1, i, op0, op1;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].op);
    build(a[i].x, a[i].y, a[i].op);
    build(a[i].y, a[i].x, a[i].op);
  }
  get(1, 0);
  tx = mx;
  mx = 0;
  get(tx, 0);
  for (i = 1; i <= n; i++) jl[i][0] = dep[i] - 1;
  ty = mx;
  get(ty, 0);
  for (i = 1; i <= n; i++) jl[i][1] = dep[i] - 1;
  dfs(1, 0);
  build1(1, 1, n);
  scanf("%d", &t1);
  while (t1--) {
    scanf("%d", &i);
    if (dep[a[i].x] < dep[a[i].y]) swap(a[i].x, a[i].y);
    xiu(1, 1, n, ru[a[i].x], chu[a[i].x]);
    op0 = get(1, 1, n, ru[tx]);
    op1 = get(1, 1, n, ru[ty]);
    ans = 0;
    if (op0 == 0)
      ans = max(ans, f[1][0][0]);
    else
      ans = max(ans, f[1][0][1]);
    if (op1 == 0)
      ans = max(ans, f[1][1][0]);
    else
      ans = max(ans, f[1][1][1]);
    printf("%d\n", ans);
  }
}
