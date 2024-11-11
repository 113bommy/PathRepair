#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, vis[55], cc = 0;
vector<int> adj[55];
void Dfs(int n) {
  vis[n] = 1;
  for (auto i : adj[n])
    if (!vis[i]) Dfs(i);
}
void connComp() {
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) Dfs(i), ++cc;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
  connComp();
  cout << (long long)pow(2, n - cc);
}
