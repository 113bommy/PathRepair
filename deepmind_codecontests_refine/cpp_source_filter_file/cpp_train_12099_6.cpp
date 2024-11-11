#include <bits/stdc++.h>
using namespace std;
int const maxn = 3e5 + 3;
auto const fast = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0));
queue<int> que;
vector<int> nxt[maxn][2];
int n, x, y, z, p, q, fa[maxn], deg[maxn], dep[maxn], vis[maxn], anc[maxn][22];
void init(int u) {
  fa[u] = u;
  for (int i = 1; i <= 20; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (int v : nxt[u][0])
    if (v != anc[u][0]) dep[v] = dep[u] + 1, anc[v][0] = u, init(v);
  return;
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 20; i >= 0; i--)
    if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--)
    if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int merge(int x, int y) { return fa[find(x)] = find(y); }
int main() {
  cin >> n;
  for (int i = 1; i < n; i++)
    cin >> x >> y, nxt[x][0].emplace_back(y), nxt[y][0].emplace_back(x);
  for (int i = 1; i < n; i++)
    cin >> x >> y, nxt[x][1].emplace_back(y), nxt[y][1].emplace_back(x),
        ++deg[x], ++deg[y];
  for (int i = 1; i <= n; i++) fa[i] = i;
  init(dep[1] = 1), cout << n - 1 << endl;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) que.emplace(i);
  while (que.size() > 1) {
    x = que.front(), que.pop(), vis[x] = 1;
    for (int z : nxt[x][1])
      if (!vis[z]) {
        if (--deg[y = z] == 1) que.emplace(z);
        break;
      }
    z = lca(x, y), p = find(x);
    if (dep[p] > dep[z])
      merge(p, q = anc[p][0]),
          cout << p << ' ' << q << ' ' << x << ' ' << y << endl;
    else {
      q = y;
      for (int i = 20; i >= 0; i--)
        if (dep[anc[q][i]] > dep[z] && find(anc[q][i]) != x) q = anc[q][i];
      cout << q << ' ' << anc[q][0] << ' ' << x << ' ' << y << endl,
          merge(q, p);
    }
  }
  return 0;
}
