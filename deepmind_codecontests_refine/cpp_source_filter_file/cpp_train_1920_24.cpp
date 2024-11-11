#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, B = 20;
vector<int> G[N];
int h[N], p[N][B], s[N], t[N], T;
void dfs(int u, int par = -1) {
  p[u][0] = par;
  h[u] = (~par ? h[par] + 1 : 0);
  for (int i = 1; i < B; i++)
    if (p[u][i - 1] != -1)
      p[u][i] = p[p[u][i - 1]][i - 1];
    else
      p[u][i] = -1;
  s[u] = T++;
  for (int v : G[u])
    if (v != par) dfs(v, u);
  t[u] = T;
}
int go(int u, int h) {
  for (int i = 0; i < B; i++)
    if (h >> i & 1) u = p[u][i];
  return u;
}
int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  go(u, h[u] - h[v]);
  if (u == v) return u;
  for (int i = B - 1; i >= 0; i--)
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}
const int S = 4 * N;
int seg[S], ex[S];
void upd(int ql, int qr, int q, int x = 1, int xl = 0, int xr = T) {
  if (xl >= qr || xr <= ql) return;
  if (xl >= ql && xr <= qr) {
    ex[x] += q, seg[x] += q;
    return;
  }
  int mid = (xl + xr) / 2, l = 2 * x, r = l + 1;
  upd(ql, qr, q, l, xl, mid);
  upd(ql, qr, q, r, mid, xr);
  seg[x] = max(seg[l], seg[r]) + ex[x];
}
int get(int ql, int qr, int x = 1, int xl = 0, int xr = T) {
  if (xl >= qr || xr <= ql) return 0;
  if (xl >= ql && xr <= qr) return seg[x];
  int mid = (xl + xr) / 2, l = 2 * x, r = l + 1;
  return max(get(ql, qr, l, xl, mid), get(ql, qr, r, mid, xr)) + ex[x];
}
vector<pair<int, pair<int, int> > > que[N];
int ans[N];
void solve(int u, int par = -1) {
  upd(0, s[u], 1);
  upd(t[u], T, 1);
  upd(s[u], t[u], -1);
  for (pair<int, pair<int, int> > x : que[u])
    if (x.second.second - x.second.first)
      ans[x.first] = max(ans[x.first], get(x.second.first, x.second.second));
  for (int v : G[u])
    if (v != par) solve(v, u);
  upd(0, s[u], -1);
  upd(t[u], T, -1);
  upd(s[u], t[u], 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    if (h[u] < h[v]) swap(u, v);
    int w = go(u, ((h[u] + h[v] - 2 * h[lca(u, v)]) + 1) / 2 - 1);
    que[u].push_back(pair<int, pair<int, int> >(i, pair<int, int>(s[w], t[w])));
    que[v].push_back(pair<int, pair<int, int> >(i, pair<int, int>(0, s[w])));
    que[v].push_back(pair<int, pair<int, int> >(i, pair<int, int>(t[w], n)));
  }
  for (int i = 0; i < n; i++) upd(s[i], s[i] + 1, h[i] + 1);
  solve(0);
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}
