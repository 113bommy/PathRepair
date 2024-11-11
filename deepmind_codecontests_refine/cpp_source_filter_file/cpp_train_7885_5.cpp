#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int U[N], V[N], n, m, c;
vector<int> G[N];
bool vis[N];
void dfs(int u) {
  vis[u] = true;
  for (int v : G[u])
    if (!vis[v]) {
      dfs(v);
    }
}
bool instack[N];
int dfn[N], low[N], head[N], e_id, dfn_id, cnt, co[N], in[N];
stack<int> s;
void Tarjan(int u) {
  dfn[u] = low[u] = ++dfn_id;
  instack[u] = true;
  s.push(u);
  for (int v : G[u]) {
    if (!dfn[v]) {
      Tarjan(v);
      low[u] = min(low[v], low[u]);
    } else if (instack[v])
      low[u] = min(dfn[v], low[u]);
  }
  if (low[u] == dfn[u]) {
    int tmp;
    ++cnt;
    do {
      tmp = s.top();
      instack[tmp] = false;
      co[tmp] = cnt;
      s.pop();
    } while (tmp != u);
  }
}
int main() {
  cin >> n >> m >> c;
  for (int i = 0; i < m; ++i) {
    cin >> U[i] >> V[i];
    G[U[i]].push_back(V[i]);
  }
  dfs(c);
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    if (!vis[U[i]] && !vis[V[i]]) {
      G[U[i]].push_back(V[i]);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!co[i] && !vis[i]) Tarjan(i);
  for (int i = 0; i < m; ++i)
    if (!vis[U[i]] && !vis[V[i]]) {
      int u = co[U[i]], v = co[U[i]];
      if (u != v) {
        ++in[v];
      }
    }
  int sum = 0;
  for (int i = 1; i <= cnt; ++i)
    if (in[i] == 0) ++sum;
  cout << sum << endl;
  return 0;
}
