#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
map<pair<int, int>, int> edge;
int tin[N], tout[N], cnt[N], ans[N];
int up[N][25], timer, len;
int n;
vector<int> g[N];
void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= len; i++) up[v][i] = up[up[v][i - 1]][i - 1];
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    dfs(to, v);
  }
  tout[v] = ++timer;
}
bool isan(int v, int u) { return (tin[v] <= tin[u] && tout[v] >= tout[u]); }
int lca(int a, int b) {
  if (isan(a, b)) return a;
  if (isan(b, a)) return b;
  for (int i = len; i >= 1; i--) {
    if (!isan(up[a][i], b)) {
      a = up[a][i];
    }
  }
  return up[a][0];
}
void dfs1(int v, int p) {
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    dfs1(to, v);
  }
  ans[edge[{v, p}]] += cnt[v];
  ans[edge[{p, v}]] += cnt[v];
  cnt[p] += cnt[v];
}
int main() {
  cin >> n;
  len = ceil(log2(n));
  for (int i = 2; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    edge[{a, b}] = i;
  }
  tin[0] = ++timer;
  dfs(1, 0);
  tout[0] = ++timer;
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    int lc = lca(a, b);
    cnt[a]++;
    cnt[b]++;
    cnt[lc] -= 2;
  }
  dfs1(1, 0);
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
