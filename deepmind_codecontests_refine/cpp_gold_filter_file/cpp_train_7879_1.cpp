#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
vector<int> g[N];
int vis[N], dfn[N], low[N], gcnt, ln, fa[N], p[N];
stack<int> s;
void tarjan(int x) {
  dfn[x] = low[x] = ++gcnt;
  vis[x] = 1;
  s.push(x);
  for (int i = 0; i < g[x].size(); i++) {
    int to = g[x][i];
    if (!dfn[to]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  int cur;
  if (dfn[x] == low[x]) {
    ++ln;
    do {
      cur = s.top();
      s.pop();
      fa[cur] = ln;
      vis[cur] = 0;
    } while (cur != x);
  }
}
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);
  p[fa[k]] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < g[i].size(); j++) {
      int to = g[i][j];
      if (fa[to] != fa[i]) p[fa[to]]++;
    }
  for (int i = 1; i <= ln; i++)
    if (!p[i]) ans++;
  printf("%d\n", ans);
}
