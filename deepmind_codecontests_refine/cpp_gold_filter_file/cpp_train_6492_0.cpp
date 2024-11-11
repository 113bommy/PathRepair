#include <bits/stdc++.h>
using namespace std;
vector<int> node[111111], ans;
int cnt[111111], a[111111];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    node[u].push_back(v);
    node[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (cnt[u] != a[u]) continue;
    cnt[u]++;
    ans.push_back(u);
    for (int j = 0; j < node[u].size(); j++) {
      cnt[node[u][j]]++;
      if (cnt[node[u][j]] == a[node[u][j]]) q.push(node[u][j]);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
