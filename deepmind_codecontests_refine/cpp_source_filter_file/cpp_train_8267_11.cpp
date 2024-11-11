#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const long long lINF = (1LL << 62) - 1;
const double dINF = 1e40;
const int MAXN = 101000;
vector<int> e[MAXN], adj[MAXN];
bool vis[MAXN];
int deep[MAXN];
vector<tuple<int, int, int> > res;
bool dfs(int u, int fath) {
  vis[u] = true;
  if (fath == -1)
    deep[u] = 0;
  else
    deep[u] = deep[fath] + 1;
  for (auto &v : e[u]) {
    if (!vis[v]) {
      if (dfs(v, u)) adj[u].push_back(v);
    } else {
      if (deep[v] < deep[u] - 1) adj[u].push_back(v);
    }
  }
  bool r = true;
  if (adj[u].size() & 1) adj[u].push_back(fath), r = false;
  for (int i = 0; i < adj[u].size(); i += 2) {
    res.push_back(make_tuple(adj[u][i], u, adj[u][i + 1]));
  }
  return r;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      if (!dfs(i, -1)) {
        flag = false;
      }
    }
  if (flag) {
    for (auto &v : res) {
      printf("%d %d %d\n", get<0>(v), get<1>(v), get<2>(v));
    }
  } else {
    puts("No Solution");
  }
  return 0;
}
