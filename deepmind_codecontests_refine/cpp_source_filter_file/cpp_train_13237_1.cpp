#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int par[N];
set<int> adj[N];
map<int, int> cur[N];
int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }
void join(int u, int v) {
  if ((u = root(u)) == (v = root(v))) return;
  if (par[u] > par[v]) swap(u, v);
  par[u] += par[v];
  par[v] = u;
  adj[u].insert(adj[v].begin(), adj[v].begin());
  adj[v].clear();
}
void add(int u, int v, int c) {
  if (cur[u].count(c))
    join(cur[u][c], v);
  else
    cur[u][c] = v;
  if (cur[v].count(c))
    join(cur[v][c], u);
  else
    cur[v][c] = u;
  adj[root(u)].insert(v);
  adj[root(v)].insert(u);
}
bool ask(int u, int v) {
  int fu = root(u), fv = root(v);
  return (fu == fv || adj[fu].count(v));
}
int main() {
  if (fopen("exam.inp", "r"))
    freopen("exam.inp", "r", stdin), freopen("exam.out", "w", stdout);
  memset(par, -1, sizeof(par));
  int n, m, q, x, y, z;
  char type;
  scanf("%d%d%d%d\n", &n, &m, &x, &q);
  while (m--) {
    scanf("%d%d%d\n", &x, &y, &z);
    add(x, y, z);
  }
  while (q--) {
    type = getchar();
    if (type == '?') {
      scanf("%d%d\n", &x, &y);
      puts(ask(x, y) ? "Yes" : "No");
    } else {
      scanf("%d%d%d\n", &x, &y, &z);
      add(x, y, z);
    }
  }
}
