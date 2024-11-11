#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
vector<int> graph[N];
map<pair<int, int>, int> mp;
bool vis[N];
int n, k;
pair<int, int> dfs(int u) {
  if (vis[u]) {
    return make_pair(0, 0);
  }
  vis[u] = true;
  pair<int, int> ans(1, 0);
  for (auto v : graph[u]) {
    pair<int, int> p(min(u, v), max(u, v));
    if (mp[p]) {
      mp[p]--;
      ans.second++;
    }
    pair<int, int> nei = dfs(v);
    ans.first += nei.first;
    ans.second += nei.second;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = (1); i <= (k); i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    mp[make_pair(u, v)]++;
  }
  int ans = 0;
  for (auto p : mp) {
    ans += p.second - 1;
    mp[p.first] = 1;
    graph[p.first.first].push_back(p.first.second);
    graph[p.first.second].push_back(p.first.first);
  }
  for (int u = (1); u <= (n); u++) {
    if (!vis[u]) {
      pair<int, int> cur = dfs(u);
      ans += max(0, cur.second - cur.first);
    }
  }
  cout << ans << "\n";
  return 0;
}
