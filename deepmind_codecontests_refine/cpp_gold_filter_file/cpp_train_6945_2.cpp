#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
map<pair<int, int>, int> mp;
long long int v[200005], ans[200005];
bool vis[200005];
void dfs(int node) {
  vis[node] = true;
  for (auto it : g[node]) {
    if (vis[it]) continue;
    dfs(it);
    v[node] += v[it];
    pair<int, int> p = make_pair(it, node);
    if (mp.find(p) == mp.end()) {
      swap(p.first, p.second);
      ans[mp[p]] = v[it];
    } else
      ans[mp[p]] = -v[it];
  }
}
int main() {
  int n, m, i, p, q;
  cin >> n;
  for (i = 0; i < n; i++) cin >> v[i + 1];
  cin >> m;
  for (i = 0; i < m; i++) ans[i] = 0;
  for (i = 0; i < m; i++) {
    cin >> p >> q;
    mp.insert(make_pair(make_pair(p, q), i));
    g[p].push_back(q);
    g[q].push_back(p);
  }
  dfs(1);
  if (v[1] != 0) {
    cout << "Impossible\n";
    return 0;
  }
  cout << "Possible\n";
  for (i = 0; i < m; i++) cout << ans[i] << "\n";
  return 0;
}
