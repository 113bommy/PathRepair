#include <bits/stdc++.h>
using namespace std;
const int maxn = 212345;
int n, m, deg1[maxn], deg2[maxn], fa[maxn];
char ans[maxn];
vector<int> G[maxn], rG[maxn];
queue<int> que;
inline bool solve(vector<int> G[maxn], int *deg) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    if (!deg[i]) que.push(i);
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    ++cnt;
    if (fa[u] < u) ans[u] = 'E';
    for (int i = 0; i < (int)G[u].size(); ++i) {
      int v = G[u][i];
      --deg[v];
      fa[v] = min(fa[v], u);
      if (!deg[v]) que.push(v);
    }
  }
  return cnt == n;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    rG[v].push_back(u);
    ++deg1[v];
    ++deg2[u];
  }
  for (int i = 1; i <= n; ++i) ans[i] = 'A';
  if (!solve(G, deg1)) return 0 * puts("-1");
  solve(rG, deg2);
  int res = 0;
  for (int i = 1; i <= n; ++i) res += ans[i] == 'A';
  printf("%d\n%s\n", res, ans + 1);
  return 0;
}
