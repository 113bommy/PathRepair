#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int n, q;
int a[maxn];
vector<int> g[maxn];
int lvl[maxn], par[maxn], up[maxn];
int f[maxn][256 + 1];
int c[256 * 9][2], mx[256 * 9], N = 1;
void add(int x) {
  int cur = 0;
  for (int me, i = 15; i > 7; i--) {
    me = (x >> i) & 1;
    if (c[cur][me] == -1) c[cur][me] = N++;
    cur = c[cur][me];
  }
  mx[cur] = max(mx[cur], x % 256);
}
int get(int x) {
  int cur = 0, res = 0;
  for (int me, i = 15; i > 7; i--) {
    me = (x >> i) & 1;
    if (c[cur][me ^ 1] != -1)
      cur = c[cur][me ^ 1], res ^= (1 << i);
    else
      cur = c[cur][me];
  }
  return res ^ mx[cur];
}
void dfs(int v) {
  for (int u : g[v])
    if (u != par[v]) {
      lvl[u] = lvl[v] + 1;
      par[u] = v;
      dfs(u);
    }
  for (; N--; mx[N] = 0, c[N][0] = c[N][1] = -1)
    ;
  N = 1;
  for (int u = v; ~u and lvl[v] - lvl[u] < 256; up[v] = u, u = par[u])
    add(a[u] ^ (lvl[v] - lvl[u]));
  for (int i = 0; i < 256; i++) f[v][i] = get(i << 8);
}
int main() {
  memset(c, -1, sizeof c);
  memset(par, -1, sizeof par);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int v, u, i = 0; i < n - 1; i++) {
    cin >> v >> u;
    v--, u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0);
  for (int res, v, u, d, i = 0; i < q; i++) {
    cin >> d >> v;
    v--, d--;
    u = v;
    res = 0;
    while (~u and lvl[u] - lvl[d] >= 256) {
      res = max(res, f[u][(lvl[v] - lvl[u]) >> 8]);
      u = par[up[u]];
    }
    while (u != par[d]) {
      res = max(res, a[u] ^ (lvl[v] - lvl[u]));
      u = par[u];
    }
    cout << res << "\n";
  }
  return 0;
}
