#include <bits/stdc++.h>
using namespace std;
namespace HMFS {
const int maxn = 1e5;
basic_string<int> g[maxn];
int n, m, dfn[maxn], sum, low[maxn], timcnt, stack[maxn], top, instack[maxn],
    scc[maxn];
void tarjan(int u) {
  dfn[u] = low[u] = ++timcnt;
  stack[++top] = u, instack[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (!dfn[v])
      tarjan(v), low[u] = min(low[u], low[v]);
    else if (instack[v])
      low[u] = min(dfn[v], low[u]);
  }
  if (low[u] == dfn[u]) {
    int t;
    sum++;
    do {
      t = stack[top--];
      scc[t] = sum;
      instack[t] = 0;
    } while (u != t);
  }
}
void work() {
  cin >> n >> m;
  for (int x, y, z, i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    if (z == 0) g[x] += (y + n), g[y + n] += x, g[y] += (x + n), g[x + n] += y;
    if (z == 1) g[x] += y, g[x + n] += (y + n), g[y] += x, g[y + n] += (x + n);
  }
  for (int i = 1; i <= 2 * n; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; i++) {
    if (scc[i] == scc[i + n]) cout << "Impossible", exit(0);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (scc[i] < scc[i + n]) cnt++;
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++)
    if (scc[i] < scc[i + n]) cout << i << ' ';
}
}  // namespace HMFS
int main() { return HMFS::work(), 0; }
