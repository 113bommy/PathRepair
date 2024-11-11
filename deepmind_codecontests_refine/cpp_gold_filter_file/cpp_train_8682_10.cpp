#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int const N = 5e4 + 16;
int const M = 1e9 + 7;
int const M2 = 999999983;
int n, r1, r2, p[N];
forward_list<int> g[N];
void dfs(int u) {
  for (int v : g[u])
    if (not p[v]) p[v] = u, dfs(v);
}
int main() {
  scanf("%d%d%d", &n, &r1, &r2);
  for (int v = 1; v < r1; ++v) {
    int u;
    scanf("%d", &u);
    g[u].push_front(v);
    g[v].push_front(u);
  }
  for (int v = r1 + 1; v <= n; ++v) {
    int u;
    scanf("%d", &u);
    g[u].push_front(v);
    g[v].push_front(u);
  }
  p[r2] = r2;
  dfs(r2);
  stringstream str;
  for (int i = 1; i < r2; ++i) printf("%d ", p[i]);
  for (int i = r2 + 1; i <= n; ++i) printf("%d ", p[i]);
}
