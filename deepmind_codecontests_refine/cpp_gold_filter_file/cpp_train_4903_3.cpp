#include <bits/stdc++.h>
using namespace std;
vector<int> adj[400025];
bool use[400025];
void dfs(int root) {
  use[root] = 1;
  for (auto x : adj[root])
    if (!use[x]) dfs(x);
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y + 200000);
    adj[y + 200000].push_back(x);
  }
  int cnt = 0;
  memset(use, 0, sizeof use);
  for (int i = 1; i <= n; i++)
    if (!use[i]) dfs(i), cnt++;
  for (int i = 1; i <= m; i++)
    if (!use[i + 200000]) dfs(i + 200000), cnt++;
  cout << cnt - 1 << endl;
  return 0;
}
