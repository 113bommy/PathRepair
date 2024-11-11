#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3003, MAXQ = 400005;
vector<pair<int, int> > Qu[MAXN][MAXN];
int ans[MAXQ], vis[MAXN], cnt[MAXN], cc = 0;
vector<int> G[MAXN], V;
void dfs(int v, int s) {
  V.push_back(v);
  vis[v] = 1;
  if (cc == 0) {
    for (int i = 0; i < (int)Qu[s][v].size(); i++) {
      int d = Qu[s][v][i].first;
      int id = Qu[s][v][i].second;
      if (d <= (int)V.size()) ans[id] = V[d - 1];
    }
  }
  for (auto u : G[v]) {
    if (vis[u] == 0)
      dfs(u, s);
    else if (vis[u] == 1) {
      cnt[u]--;
      cc++;
    }
  }
  cc += cnt[v];
  vis[v] = 2;
  V.pop_back();
}
int n, m, q;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0, v, u; i < m; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
  for (int i = 0; i < q; i++) {
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    Qu[s][t].push_back(make_pair(k, i));
  }
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dfs(i, i);
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
