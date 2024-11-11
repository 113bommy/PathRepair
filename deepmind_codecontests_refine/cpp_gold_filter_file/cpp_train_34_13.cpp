#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
vector<int> V;
double ans;
const int MAXN = 3333;
int T;
int par[MAXN], vis[MAXN], dis[MAXN];
vector<int> adj[MAXN];
void dfs(int u, int p) {
  vis[u] = ++T, par[u] = p;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;
    if (!vis[v]) {
      dfs(v, u);
    } else {
      if (vis[v] < vis[u]) {
        V.push_back(v);
        for (int w = u; w != v; V.push_back(w), w = par[w])
          ;
      }
    }
  }
}
void dfs1(int u, int p, int d) {
  vis[u] = T, dis[u] = d;
  if (d > 1) ans += 1.0 / d;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;
    dfs1(v, u, d + 1);
  }
}
vector<int> W;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v), u++, v++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 0; i < V.size(); i++) {
    int j = (i + 1) % V.size();
    adj[V[i]].erase(find((adj[V[i]]).begin(), (adj[V[i]]).end(), V[j]));
    adj[V[j]].erase(find((adj[V[j]]).begin(), (adj[V[j]]).end(), V[i]));
  }
  ans = n + 3 - ((int)(V.size()));
  for (int i = 1; i <= n; i++) {
    bool flg = 1;
    for (int j = 0; flg && j < V.size(); j++)
      if (i == V[j]) flg = 0;
    if (flg) dfs1(i, 0, 1);
  }
  memset(vis, 0, sizeof vis), T = 0;
  for (int i = 0; i < V.size(); i++) dfs1(V[i], 0, 1), T++;
  for (int i = 1; i <= n; i++) {
    if (dis[i] == 1) continue;
    for (int j = i + 1; j <= n; j++) {
      if (dis[j] == 1) continue;
      if (vis[i] == vis[j] || vis[i] == (vis[j] + 1) % V.size() ||
          vis[j] == (vis[i] + 1) % V.size())
        continue;
      ans -= 2.0 / (dis[i] + dis[j] - 2 + V.size());
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dis[i] == 1) continue;
    ans -= 2.0 * (((int)(V.size())) - 3) / (dis[i] - 1 + V.size());
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (vis[i] == vis[j] || vis[i] == (vis[j] + 1) % V.size()) continue;
      ans +=
          2.0 / (dis[i] + dis[j] +
                 (vis[j] - vis[i] + ((int)(V.size())) - 1) % ((int)(V.size())));
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
