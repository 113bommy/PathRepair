#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  int w = 1;
  while ((c = getchar()) > '9' || c < '0')
    if (c == '-') w = -1;
  int ans = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    ans = (ans << 1) + (ans << 3) + c - '0';
  return ans * w;
}
int n, m, blk, ynt, mod;
int a[30005], f[30005], ys[30005], bel[30005], num[30005], pre[30005 << 2],
    now[30005 << 2], siz[30005 << 2];
int res[30005];
struct node {
  int l, r, id;
} q[30005];
bool cmp(node tx, node ty) {
  if (bel[tx.l] == bel[ty.l]) return tx.r < ty.r;
  return tx.l < ty.l;
}
void pushup(int v) {
  int x = siz[v * 2];
  siz[v] = siz[v * 2] + siz[v * 2 + 1];
  pre[v] = (pre[v * 2] + 1ll * pre[v * 2 + 1] * (x ? f[x - 1] : 1) +
            1ll * now[v * 2 + 1] * f[x]) %
           mod;
  now[v] = (now[v * 2] + 1ll * pre[v * 2 + 1] * f[x] +
            1ll * now[v * 2 + 1] * f[x + 1]) %
           mod;
}
void upd(int v, int l, int r, int pos, int op) {
  if (l == r) {
    now[v] = (now[v] + ys[pos] * op) % mod;
    siz[v] += op;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    upd(v * 2, l, mid, pos, op);
  else
    upd(v * 2 + 1, mid + 1, r, pos, op);
  pushup(v);
}
void add(int x) {
  if (++num[a[x]] == 1) upd(1, 1, ynt, a[x], 1);
}
void del(int x) {
  if (--num[a[x]] == 0) upd(1, 1, ynt, a[x], -1);
}
int main() {
  n = read(), mod = read(), blk = sqrt(n);
  for (int i = 1; i <= n; i++)
    a[i] = read(), ys[i] = a[i], bel[i] = (i - 1) / blk + 1;
  sort(ys + 1, ys + n + 1);
  ynt = unique(ys + 1, ys + n + 1) - ys - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(ys + 1, ys + ynt + 1, a[i]) - ys;
  m = read();
  f[1] = f[2] = 1;
  for (int i = 3; i <= ynt; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  for (int i = 1; i <= m; i++) q[i].l = read(), q[i].r = read(), q[i].id = i;
  sort(q + 1, q + m + 1, cmp);
  int l = 1, r = 0, tl, tr;
  for (int i = 1; i <= m; i++) {
    tl = q[i].l, tr = q[i].r;
    while (r < tr) add(++r);
    while (l > tl) add(--l);
    while (r > tr) del(r--);
    while (l < tl) del(l++);
    res[q[i].id] = now[1];
  }
  for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
  return 0;
}
