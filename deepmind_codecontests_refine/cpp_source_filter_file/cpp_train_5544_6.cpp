#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 200005;
int n, m, k, d[N];
vector<int> adj[N], s;
bool vis[N];
void dfs(int u, int p = -1) {
  s.push_back(u);
  d[u] = (int)s.size();
  for (int v : adj[u])
    if (v != p) {
      if (!d[v])
        dfs(v, u);
      else if (d[u] - d[v] + 1 > 1 && d[u] - d[v] + 1 <= k) {
        cout << 2 << '\n' << d[u] - d[v] + 1 << '\n';
        for (int i = d[v] - 1; i < d[u]; i++) cout << s[i] + 1 << ' ';
        cout << '\n';
        exit(0);
      }
    }
  if (!vis[u])
    for (int v : adj[u]) vis[v] = true;
  s.pop_back();
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  cout << 1 << '\n';
  int need = (k - 1) / 2 + 1;
  for (int i = 0; i < n && need; i++)
    if (!vis[i]) cout << i << ' ', need--;
  cout << '\n';
}
