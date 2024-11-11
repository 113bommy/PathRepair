#include <bits/stdc++.h>
using namespace std;
const int N = 20003;
int n, m, ans, vis[N], flag[N], fa[N], fc[N], dep[N], cnt, lsh[N], cir;
vector<int> G[N];
vector<pair<int, int> > nxt[N];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
void merge(int x, int y) {
  x = getfa(x), y = getfa(y);
  if (x == y) {
    flag[x] = 1;
    return;
  }
  flag[x] |= flag[y], fa[y] = x;
}
void dfs(int u, int lst) {
  dep[u] = dep[lst] + 1, fa[u] = lst;
  for (auto p : nxt[u])
    if (p.first != lst) {
      int v = p.first, c = p.second;
      c = lower_bound(lsh + 1, lsh + cnt + 1, c) - lsh;
      if (!dep[v])
        ++vis[fc[v] = c], dfs(v, u);
      else if (dep[v] < dep[u]) {
        int now = u;
        ++cir;
        while (now != v)
          --vis[fc[now]], G[fc[now]].push_back(cir), now = fa[now];
        G[c].push_back(cir);
      }
    }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    nxt[x].push_back(make_pair(y, c));
    nxt[y].push_back(make_pair(x, c));
    lsh[++cnt] = c;
  }
  sort(lsh + 1, lsh + cnt + 1), cnt = unique(lsh + 1, lsh + cnt + 1) - lsh - 1;
  dfs(1, 0);
  for (int i = 1; i <= cir; ++i) flag[i] = 0, fa[i] = i;
  for (int i = 1; i <= cnt; ++i)
    if (G[i].size()) {
      for (int j = 0; j + 1 < G[i].size(); ++j) merge(G[i][j], G[i][j + 1]);
      if (vis[i]) merge(G[i][0], G[i][0]);
    }
  int ans = cnt;
  for (int i = 1; i <= cir; ++i)
    if (fa[i] == i) ans -= !flag[i];
  cout << ans << endl;
  return 0;
}
