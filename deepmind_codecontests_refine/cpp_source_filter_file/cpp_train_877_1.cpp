#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<int, vector<pair<int, int> > > mp;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    mp[w].push_back({u, v});
  }
  vector<int> dp(n + 1, 0);
  for (auto& p : mp) {
    map<int, int> tmp;
    for (auto& e : p.second) {
      if (tmp.count(e.second))
        tmp[e.second] = min(tmp[e.second], dp[e.first] + 1);
      else
        tmp[e.second] = dp[e.first] + 1;
    }
    for (auto& e : tmp) dp[e.first] = max(dp[e.first], e.second);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
