#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> G[N];
int ok[N], sz[N], ms[N], vis[N], root, n, m;
void Getroot(int u) {
  sz[u] = ok[u], ms[u] = 0, vis[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    if (vis[G[u][i]]) continue;
    Getroot(G[u][i]);
    sz[u] += sz[G[u][i]];
    if (ms[u] < sz[G[u][i]]) ms[u] = sz[G[u][i]];
  }
  ms[u] = max(2 * m - sz[u], ms[u]);
  if (root == -1 || ms[u] < ms[root]) root = u;
}
long long cal(int u, int deep) {
  long long ret = ok[u] * deep;
  vis[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    if (vis[G[u][i]]) continue;
    ret += cal(G[u][i], deep + 1);
  }
  return ret;
}
int main() {
  int u, v;
  cin >> n >> m;
  memset(ok, 0, sizeof(ok));
  for (int i = 0; i < 2 * m; i++) {
    scanf("%d", &u);
    ok[u] = 1;
  }
  for (int i = 1; i <= n; i++) G[i].clear();
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  root = -1;
  Getroot(1);
  memset(vis, 0, sizeof(vis));
  cout << cal(root, 0) << endl;
}
