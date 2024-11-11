#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, a[N], fa[N], cnt, head[N], f[N][22], in[N], out[N], clk, dep[N], ans;
pair<int, int> t[N << 2], res;
struct edge {
  int to, nxt;
} e[N];
void adde(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}
void dfs(int u) {
  in[u] = ++clk;
  dep[u] = dep[fa[u]] + 1;
  f[u][0] = fa[u];
  for (int i = (1); i <= (18); i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int i = head[u], v; i; i = e[i].nxt)
    if (v = e[i].to, v != fa[u]) dfs(v);
  out[u] = clk;
}
bool isanc(int x, int y) { return in[x] <= in[y] && out[y] <= out[x]; }
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int tmp = dep[x] - dep[y];
  for (int i = 18; ~i; i--)
    if (tmp >> i & 1) x = f[x][i];
  if (x == y) return x;
  for (int i = 18; ~i; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
pair<int, int> upd(pair<int, int> x, int y) {
  if (!x.first || !y) return pair<int, int>(0, 0);
  if (isanc(x.second, x.first)) swap(x.first, x.second);
  if (isanc(x.first, x.second)) {
    if (!isanc(x.first, y) || lca(x.second, y) == x.first)
      return pair<int, int>(y, x.second);
    if (isanc(x.second, y)) return pair<int, int>(x.first, y);
    if (isanc(y, x.second) && isanc(x.first, y)) return x;
    return pair<int, int>(0, 0);
  }
  if (isanc(x.first, y)) return pair<int, int>(y, x.second);
  if (isanc(x.second, y)) return pair<int, int>(y, x.first);
  int Lca = lca(x.first, x.second);
  if ((isanc(y, x.first) || isanc(y, x.second)) && y != Lca && !isanc(y, Lca))
    return x;
  return pair<int, int>(0, 0);
}
pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  if (x.first == -1) return y;
  x = upd(x, y.first);
  if (y.second != y.first) x = upd(x, y.second);
  return x;
}
void mdy(int now, int l, int r, int x, int v) {
  if (l == r) {
    t[now] = pair<int, int>(v, v);
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    mdy((now << 1), l, mid, x, v);
  else
    mdy((now << 1 | 1), mid + 1, r, x, v);
  t[now] = merge(t[(now << 1)], t[(now << 1 | 1)]);
}
bool qry(int now, int l, int r) {
  pair<int, int> tmp = merge(res, t[now]);
  if (tmp.first) {
    res = tmp;
    ans = r;
    return 1;
  }
  if (l == r) return 0;
  int mid = l + r >> 1;
  if (qry((now << 1), l, mid)) qry((now << 1 | 1), mid + 1, r);
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), a[i]++;
  for (int i = (2); i <= (n); i++) scanf("%d", &fa[i]), adde(fa[i], i);
  dfs(1);
  for (int i = (1); i <= (n); i++) mdy(1, 1, n, a[i], i);
  scanf("%d", &m);
  while (m--) {
    int opt, x, y;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &x, &y), swap(a[x], a[y]);
      mdy(1, 1, n, a[x], x), mdy(1, 1, n, a[y], y);
    } else {
      res = pair<int, int>(-1, 0);
      ans = 0;
      qry(1, 1, n);
      printf("%d\n", ans);
    }
  }
  return 0;
}
