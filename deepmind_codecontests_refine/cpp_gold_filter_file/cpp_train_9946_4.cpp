#include <bits/stdc++.h>
using namespace std;
int n, m, dis[300010];
vector<int> g[300010];
long long ans, rec[300010];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    q[300010];
void dfs1(int u, int fa) {
  dis[u] = dis[fa] + 1;
  for (int i = 0; i < g[u].size(); ++i)
    if (g[u][i] != fa) dfs1(g[u][i], u);
}
void merge(int x, int y) {
  if (q[x].size() < q[y].size()) swap(q[x], q[y]), swap(rec[x], rec[y]);
  while (!q[y].empty())
    q[x].push(pair<long long, int>(q[y].top().first + rec[y] - rec[x],
                                   q[y].top().second)),
        q[y].pop();
}
void dfs2(int u, int fa) {
  for (int i = 0; i < g[u].size(); ++i)
    if (g[u][i] != fa) dfs2(g[u][i], u), merge(u, g[u][i]);
  while (!q[u].empty() && dis[u] <= q[u].top().second) q[u].pop();
  if (u != 1) {
    if (q[u].empty()) {
      puts("-1");
      exit(0);
    }
    long long tmp = q[u].top().first + rec[u];
    ans += tmp;
    rec[u] -= tmp;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i < n; ++i)
    scanf("%d%d", &u, &v), g[u].push_back(v), g[v].push_back(u);
  dfs1(1, 0);
  for (int i = 1, u, v, c; i <= m; ++i)
    scanf("%d%d%d", &u, &v, &c), q[u].push(pair<long long, int>(c, dis[v]));
  dfs2(1, 0);
  printf("%I64d\n", ans);
}
