#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<int> g[N];
vector<int> s[N];
int vis[N], color[N];
void dfs(int o, int u) {
  int cnt = 1;
  for (int &i : s[u])
    if (color[i]) vis[color[i]] = u;
  for (int &i : s[u])
    if (!color[i]) {
      while (u == vis[cnt]) cnt++;
      vis[cnt] = u;
      color[i] = cnt;
    }
  for (int &v : g[u])
    if (v != o) dfs(u, v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t, u, v, a;
  int ans = 1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    ans = max(ans, t);
    while (t--) {
      cin >> a;
      s[i].push_back(a);
    }
  }
  for (int i = 1; i <= n; i++)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  dfs(0, 1);
  cout << ans << endl;
  for (int i = 1; i <= m; i++) cout << max(1, color[i]) << ' ';
  cout << endl;
  return 0;
}
