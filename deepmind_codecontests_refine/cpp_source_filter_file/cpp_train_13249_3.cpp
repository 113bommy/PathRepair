#include <bits/stdc++.h>
using namespace std;
int n, m, q, r = 1, tmp, op[500005], x[500005], a[500005], w[500005],
             tim[300005], be[300005], ed[300005], fp[500005];
int tot, head[500005];
int fo[500005], nxt[500005];
int t[500005 * 4];
int finds(int x) { return w[x] == x ? x : w[x] = finds(w[x]); }
void link(int u, int to) {
  u = finds(u), to = finds(to);
  if (u == to) return;
  ++n;
  w[n] = n;
  w[to] = n;
  w[u] = n;
  fo[++tot] = to;
  nxt[tot] = head[n];
  head[n] = tot;
  fo[++tot] = u;
  nxt[tot] = head[n];
  head[n] = tot;
}
void dfs(int u) {
  fp[be[u] = ++tmp] = u;
  for (int i = head[u]; i; i = nxt[i]) dfs(fo[i]);
  ed[u] = tmp;
}
int cma(int x, int y) { return a[x] > a[y] ? x : y; }
void build(int l, int r, int i) {
  t[i] = fp[l];
  if (l == r) return;
  build(l, (l + r) / 2, i * 2 + 1);
  build((l + r) / 2 + 1, r, i * 2 + 2);
  t[i] = cma(t[i * 2 + 1], t[i * 2 + 2]);
}
void upd(int pos, int l, int r, int i) {
  if (l > r) return;
  t[i] = fp[l];
  if (l == r) return;
  if (pos <= (l + r) / 2)
    upd(pos, l, (l + r) / 2, i * 2 + 1);
  else
    upd(pos, (l + r) / 2 + 1, r, i * 2 + 2);
  t[i] = cma(t[i * 2 + 1], t[i * 2 + 2]);
}
int quy(int L, int R, int l, int r, int i) {
  if (L > R) return 0;
  if (L <= l && R >= r) return t[i];
  int res = 0;
  if (L <= (l + r) / 2) res = cma(res, quy(L, R, l, (l + r) / 2, i * 2 + 1));
  if (R > (l + r) / 2) res = cma(res, quy(L, R, (l + r) / 2 + 1, r, i * 2 + 2));
  return res;
}
int main() {
  cin >> n >> m >> q;
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), w[i] = i;
  w[n + 1] = n + 1;
  for (int i = (1); i <= (m); i++) scanf("%d%d", &be[i], &ed[i]);
  for (int i = (1); i <= (q); i++) {
    scanf("%d%d", &op[i], &x[i]);
    if (op[i] == 2) tim[x[i]] = 1;
  }
  for (int i = (1); i <= (m); i++)
    if (!tim[i]) link(be[i], ed[i]);
  for (int i = (q); i >= (1); i--) {
    if (op[i] == 2) link(be[x[i]], ed[x[i]]);
    if (op[i] == 1) x[i] = finds(x[i]);
  }
  for (int i = (1); i <= (n); i++)
    if (w[i] == i) dfs(i);
  build(1, n, 0);
  for (int i = (1); i <= (q); i++) {
    if (op[i] == 2) continue;
    x[i] = quy(be[x[i]], ed[x[i]], 1, n, 0);
    printf("%d\n", a[x[i]]);
    a[x[i]] = 0;
    upd(be[x[i]], 1, n, 0);
  }
}
