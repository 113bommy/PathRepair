#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, INF = 1e9;
int n, m, dp[2][N], st, en, cnt[N];
vector<int> adj[N];
set<pair<int, int>> s;
void upd(int u, int val) {
  if (val < dp[0][u]) {
    s.erase({dp[0][u], u});
    s.insert({dp[0][u] = val, u});
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[--v].push_back(--u);
    cnt[u]++;
  }
  cin >> st >> en;
  fill(dp[0], dp[0] + n, INF);
  upd(--en, 0);
  while (s.size()) {
    auto [d, u] = *s.begin();
    s.erase(s.begin());
    for (int v : adj[u]) {
      cnt[v]--;
      upd(v, d + 1);
      dp[0][1] = max(dp[1][v], d + 1);
      if (!cnt[v]) upd(v, dp[0][v] - (dp[0][v] == dp[1][v] + 1));
    }
  }
  cout << (dp[0][--st] > n ? -1 : dp[0][st]) << endl;
}
