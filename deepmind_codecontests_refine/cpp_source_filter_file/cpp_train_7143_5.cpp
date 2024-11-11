#include <bits/stdc++.h>
using namespace std;
const int maxn = 3030;
const int Log = 11;
int g[maxn];
int go[maxn][Log + 1];
int to[maxn], nxt[maxn], head[maxn];
struct Query {
  int s, t, k, id;
  void read(int _id) {
    cin >> s >> t >> k;
    id = _id;
  }
  bool operator<(const Query &Q) const { return t < Q.t; }
};
Query Q[400040];
int ans[400040];
int rt;
void dfs(int u) {
  for (int e = head[u], v; e != -1; e = nxt[e]) {
    v = to[e];
    if (v != rt and (!g[v] or g[v] > u)) g[v] = u, dfs(v);
  }
}
int u, v, n, m, q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) head[i] = -1;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    nxt[i] = head[v];
    to[i] = u;
    head[v] = i;
  }
  for (int i = 0; i < q; i++) Q[i].read(i);
  sort(Q, Q + q);
  for (int i = 0; i < q; i++) {
    if (rt != Q[i].t) {
      for (int j = 1; j <= n; j++) g[j] = 0;
      rt = Q[i].t;
      dfs(rt);
      for (int j = 1; j <= n; j++) go[j][0] = g[j];
      for (int j = 1; j <= Log; j++)
        for (int k = 1; k <= n; k++) go[k][j] = go[go[k][j - 1]][j - 1];
    }
    u = Q[i].s;
    if (!g[u] or go[u][Log])
      ans[Q[i].id] = -1;
    else {
      v = Q[i].k - 1;
      for (int t = 0; v; t++, v >>= 1)
        if (v & 1) u = go[u][t];
      if (!u)
        ans[Q[i].id] = -1;
      else
        ans[Q[i].id] = u;
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << endl;
  return 0;
}
