#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
const int MAXM = 1005;
namespace MCMF {
int n, tot;
int mf, mc, sum;
vector<int> G[MAXN];
int cap[MAXM * 2], cost[MAXM * 2], edge[MAXM * 2];
void add(int u, int v, int Cap, int Cost) {
  G[u].push_back(++tot);
  edge[tot] = v;
  cap[tot] = Cap;
  cost[tot] = Cost;
}
void add_edge(int u, int v, int Cap, int Cost) {
  add(u, v, Cap, Cost);
  add(v, u, 0, -Cost);
}
int dis[MAXN];
bool augment(int s, int t) {
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      q;
  fill(dis, dis + n + 1, 0x3f3f3f3f);
  q.push({dis[t] = 0, t});
  while (!q.empty()) {
    pair<int, int> x = q.top();
    q.pop();
    if (dis[x.second] != x.first) continue;
    int &u = x.second, dt, v;
    for (int it : G[u])
      if (cap[it ^ 1] && (dt = dis[u] - cost[it]) < dis[v = edge[it]])
        q.push({dis[v] = dt, v});
  }
  sum += dis[s];
  for (int i = 0; i <= n; ++i)
    for (int it : G[i]) cost[it] += dis[edge[it]] - dis[i];
  return dis[s] != 0x3f3f3f3f;
}
bool vis[MAXN];
int dfs(int u, int t, int limit) {
  if (!limit) return 0;
  if (u == t) {
    mc += limit * sum;
    return limit;
  }
  int fee = 0, v;
  vis[u] = true;
  for (auto it : G[u]) {
    if (cost[it] || !cap[it] || vis[v = edge[it]]) continue;
    int water = dfs(v, t, min(limit - fee, cap[it]));
    cap[it] -= water;
    cap[it ^ 1] += water;
    fee += water;
    if (fee == limit) break;
  }
  if (fee == limit) vis[u] = false;
  return fee;
}
void init(int x) {
  n = x, tot = 1;
  for (int i = 0; i <= x; ++i) G[i].clear();
}
void solve(int s, int t) {
  int res;
  mf = mc = sum = 0;
  do {
    do {
      fill(vis, vis + n + 1, 0);
    } while (mf += (res = dfs(s, t, 0x3f3f3f3f)), res > 0);
  } while (augment(s, t));
}
}  // namespace MCMF
int deg[MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  MCMF::init(n + 2);
  int ans = 0;
  int s = 1, t = n;
  for (int i = 0; i < m; i++) {
    int u, v, c, f;
    scanf("%d%d%d%d", &u, &v, &c, &f);
    if (f <= c)
      MCMF::add_edge(u, v, c - f, 1);
    else {
      ans += f - c;
      MCMF::add_edge(v, u, f - c, 0);
    }
    MCMF::add_edge(u, v, 0x3f3f3f3f, 2);
    MCMF::add_edge(v, u, f, 1);
    MCMF::add_edge(u, v, 0, 0);
    deg[u] -= f, deg[v] += f;
  }
  MCMF::add_edge(t, s, 0x3f3f3f3f, 0);
  int S = n + 1, T = n + 2;
  for (int i = 1; i <= n; i++)
    if (deg[i] < 0)
      MCMF::add_edge(i, T, -deg[i], 0);
    else
      MCMF::add_edge(S, i, deg[i], 0);
  MCMF::solve(S, T);
  printf("%d\n", ans + MCMF::mc);
}
