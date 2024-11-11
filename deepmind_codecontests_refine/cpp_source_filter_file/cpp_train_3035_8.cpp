#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
vector<int> dfs(int u, vector<int>& visit,
                const vector<vector<pair<int, int> > >& sons) {
  if (visit[u]) return {};
  visit[u] = true;
  vector<int> ret;
  for (auto p : sons[u]) {
    vector<int> tmp = dfs(p.first, visit, sons);
    ret.insert(ret.end(), tmp.begin(), tmp.end());
  }
  ret.push_back(u);
  return ret;
}
vector<int> getComps(int n, const vector<vector<pair<int, int> > >& sons,
                     int& tot) {
  vector<int> ret(n, -1);
  vector<int> visit(n, 0);
  tot = 0;
  int small = n;
  for (int i = 0; i < n; ++i) {
    if (visit[i]) continue;
    vector<int> tmp = dfs(i, visit, sons);
    if (tmp.size() < 4) {
      for (int x : tmp) ret[x] = small;
      small += 1;
    } else {
      for (int x : tmp) ret[x] = tot;
      tot += 1;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<vector<pair<int, int> > > lights(n, vector<pair<int, int> >());
  vector<vector<pair<int, int> > > heavys(n, vector<pair<int, int> >());
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u -= 1;
    v -= 1;
    if (w == a) {
      lights[u].emplace_back(v, w);
      lights[v].emplace_back(u, w);
    } else {
      heavys[u].emplace_back(v, w);
      heavys[v].emplace_back(u, w);
    }
  }
  int tot;
  vector<int> comps = getComps(n, lights, tot);
  vector<vector<int> > dp(1 << tot, vector<int>(n, INF));
  dp[comps[0] < tot ? (1 << comps[0]) : 0][0] = 0;
  for (int s = 0; s < (1 << tot); ++s) {
    deque<int> de;
    for (int u = 0; u < n; ++u)
      if (dp[s][u] != INF) de.push_back(u);
    while (!de.empty()) {
      int u = de.front();
      de.pop_front();
      for (auto p : lights[u]) {
        int v = p.first, w = p.second;
        if (dp[s][v] - w > dp[s][u]) {
          dp[s][v] = dp[s][u] + w;
          de.push_back(v);
        }
      }
      for (auto p : heavys[u]) {
        int v = p.first, w = p.second;
        if (comps[u] == comps[v]) continue;
        int new_s = s;
        if (comps[v] < tot && (s & (1 << comps[v]))) continue;
        if (comps[v] < tot) new_s = s | (1 << comps[v]);
        if (dp[new_s][v] - w > dp[s][u] + w) {
          dp[new_s][v] = dp[s][u] + w;
          if (new_s == s) de.push_back(v);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int ans = INF;
    for (int s = 0; s < (1 << tot); ++s) ans = min(ans, dp[s][i]);
    cout << ans << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
