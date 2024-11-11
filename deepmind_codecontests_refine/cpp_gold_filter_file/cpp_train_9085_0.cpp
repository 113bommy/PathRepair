#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 4e18, MOD = 998244353;
int64_t pp(int64_t b, int64_t p) {
  if (p == 0) return 1;
  int64_t v = pp(b * b % MOD, p / 2);
  return v * (p % 2 ? b : 1) % MOD;
}
int64_t n, m;
vector<vector<int64_t>> g, ag;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  g.resize(n), ag.resize(n);
  for (int64_t i = 0; i < m; i++) {
    int64_t a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    ag[b].push_back(a);
  }
  int64_t LOG = 30;
  vector<vector<int64_t>> dist(LOG, vector<int64_t>(n, INF));
  dist[0][0] = 0;
  priority_queue<pair<int64_t, pair<int64_t, int64_t>>> q;
  q.push({0, {0, 0}});
  auto change = [&](int64_t cur, int64_t k, int64_t d) {
    if (k < LOG && dist[k][cur] > d) {
      dist[k][cur] = d;
      q.push({-d, {k, cur}});
    }
  };
  while (q.size()) {
    auto tmp = q.top();
    q.pop();
    int64_t d = -tmp.first, k = tmp.second.first, cur = tmp.second.second;
    if (dist[k][cur] != d) continue;
    if (k % 2) {
      for (int64_t nei : ag[cur]) change(nei, k, d + 1);
    } else {
      for (int64_t nei : g[cur]) change(nei, k, d + 1);
    }
    change(cur, k + 1, d + (1 << k));
  }
  int64_t ans = INF;
  for (int64_t i = 0; i < LOG; i++)
    if (dist[i][n - 1] != INF) {
      ans = min(ans, dist[i][n - 1]);
    }
  if (ans == INF) {
    vector<vector<int64_t>> totdist(n, vector<int64_t>(2, INF));
    priority_queue<pair<int64_t, pair<int64_t, int64_t>>> qq;
    totdist[0][0] = 0;
    qq.push({0, {0, 0}});
    auto change2 = [&](int64_t cur, int64_t k, int64_t d) {
      if (totdist[cur][k % 2] > d) {
        totdist[cur][k % 2] = d;
        qq.push({-d, {cur, k}});
      }
    };
    bool fin = 0;
    while (!fin) {
      vector<pair<pair<int64_t, int64_t>, int64_t>> vec;
      while (qq.size()) {
        auto tmp = qq.top();
        qq.pop();
        int64_t cur = tmp.second.first, k = tmp.second.second, d = -tmp.first;
        if (totdist[cur][k % 2] != d) continue;
        if (cur == n - 1) {
          ans = (d + pp(2, k) + MOD - 1) % MOD;
          fin = 1;
          break;
        }
        vec.push_back({{cur, k}, d});
        if (k % 2) {
          for (int64_t nei : ag[cur]) change2(nei, k, d + 1);
        } else {
          for (int64_t nei : g[cur]) change2(nei, k, d + 1);
        }
      }
      for (auto p : vec) change2(p.first.first, p.first.second + 1, p.second);
    }
  } else
    ans = ans % MOD;
  cout << ans << endl;
  return 0;
}
