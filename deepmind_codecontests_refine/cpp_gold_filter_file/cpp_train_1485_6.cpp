#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ans;
vector<pair<int, int> > g[200009];
int val[200009];
int vis[200009];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> val[i];
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
    --val[x];
    --val[y];
  }
  queue<int> ok;
  int fine = 0;
  for (int i = 1; i <= n; ++i)
    if (val[i] >= 0) {
      ok.push(i);
      ++fine;
    }
  while (ok.size()) {
    int v = ok.front();
    ok.pop();
    for (auto u : g[v]) {
      if (vis[u.second]) continue;
      ans.push_back(u.second);
      vis[u.second] = 1;
      val[u.first]++;
      if (val[u.first] == 0) {
        ok.push(u.first);
        ++fine;
      }
    }
  }
  if (fine != n) {
    cout << "DEAD\n";
    return 0;
  }
  cout << "ALIVE\n";
  reverse(ans.begin(), ans.end());
  for (auto u : ans) cout << u + 1 << ' ';
}
