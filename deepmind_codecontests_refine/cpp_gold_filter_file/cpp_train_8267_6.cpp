#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
const long double pi = acos(-1.0);
const int N = (int)2e6;
vector<int> adj[N];
int color[N], n, m, u, v, ecnt[N];
void dfs(int v) {
  color[v] = 1, ecnt[v] = 0;
  for (int i = 0; i < ((int)(adj[v]).size()); ++i) {
    int u = adj[v][i];
    if (color[u] != 1) ecnt[v]++;
    if (color[u] == 0) {
      dfs(u);
      ecnt[v] += ecnt[u];
    }
  }
  color[v] = 2;
}
void solve(int v, bool odd, int p = -1) {
  color[v] = 1;
  vector<int> e;
  for (int i = 0; i < ((int)(adj[v]).size()); ++i) {
    int u = adj[v][i];
    if (color[u] == 0) {
      if (ecnt[u] % 2 == 1) {
        solve(u, true, v);
      } else {
        solve(u, false, v);
        e.push_back(u);
      }
    } else if (color[u] == 2)
      e.push_back(u);
  }
  if (odd) {
    assert(!e.empty());
    printf("%d %d %d\n", p + 1, v + 1, e[((int)(e).size()) - 1] + 1);
    e.pop_back();
  }
  assert(((int)(e).size()) % 2 == 0);
  for (int i = 0; i < ((int)(e).size()); i += 2)
    printf("%d %d %d\n", e[i] + 1, v + 1, e[i + 1] + 1);
  color[v] = 2;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v), --u, --v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  if (m % 2 == 1) {
    printf("No solution\n");
    return 0;
  }
  dfs(0);
  memset(color, 0, sizeof(color));
  solve(0, false);
  return 0;
}
