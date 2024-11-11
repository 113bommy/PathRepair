#include <bits/stdc++.h>
using namespace std;
using ld = long double;
vector<int> v[101];
map<pair<int, int>, int> a;
int ans;
int vis[101];
void dfs(int node, int total) {
  vis[node] = 1;
  if (v[node].size() == 1) ans = max(ans, total);
  for (int child : v[node]) {
    if (!vis[child]) dfs(child, total + a[{node, child}]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i;
  cin >> n;
  for (i = 0; i < n - 1; ++i) {
    int u, v1, c;
    cin >> u >> v1 >> c;
    v[u].push_back(v1);
    v[v1].push_back(u);
    a[{u, v1}] = c;
    a[{v1, u}] = c;
  }
  dfs(0, 0);
  cout << ans << "\n";
  return 0;
}
