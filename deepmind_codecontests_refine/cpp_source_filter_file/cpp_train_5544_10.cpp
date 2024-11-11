#include <bits/stdc++.h>
using namespace std;
const int maxn = 1E5 + 1;
int n, m, k, p[maxn], vis[maxn];
vector<long long> a[maxn], lua[2];
bool cyclic;
void dfs(int u, int pa) {
  vis[u] = vis[pa] + 1;
  p[u] = pa;
  for (int v : a[u])
    if (v != pa) {
      cyclic |= vis[v] != 0;
      if (!vis[v]) dfs(v, u);
    }
  lua[vis[u] & 1].push_back(u);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 1);
  if (!cyclic) {
    for (int i = 0; i < 2; i++)
      if (lua[i].size() >= (k + 1) >> 1) {
        cout << "1\n";
        for (int j = 0; j < (k + 1) >> 1; j++) cout << lua[i][j] << " ";
        return 0;
      }
  }
  for (int u = 2; u <= n; u++)
    for (int v : a[u])
      if (v != p[u] && vis[u] > vis[v] && vis[u] - vis[v] + 1 <= k) {
        cout << "2\n";
        vector<long long> res;
        res.clear();
        while (u != v) {
          res.push_back(u);
          u = p[u];
        }
        res.push_back(v);
        cout << res.size() << "\n";
        for (int cc : res) cout << cc << " ";
        return 0;
      }
  cout << "1\n";
  for (int u = 2; u <= n; u++)
    for (int v : a[u])
      if (v != p[u] && vis[u] > vis[v]) {
        bool lock = 0;
        int cnt = (k + 1) >> 1;
        while (cnt--) {
          if (!lock) cout << u << " ";
          lock ^= 1;
          u = p[u];
        }
        return 0;
      }
  return 0;
}
