#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100000, MAXM = 100000;
vector<pair<int, int>> adj[MAXN + 2];
vector<pair<int, int>> interval[MAXN + 2];
int dist[MAXN + 2];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    if (k > 0) {
      int st, lst;
      cin >> st;
      lst = st;
      for (int j = 1; j < k; j++) {
        int t;
        cin >> t;
        if (++lst != t) {
          interval[i].push_back(make_pair(st, lst));
          st = t;
          lst = t;
        }
      }
      interval[i].push_back(make_pair(st, lst + 1));
    }
  }
  fill(dist + 2, dist + n + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.push(
      make_pair(dist[1] = interval[1].size() != 0 && interval[1][0].first == 0
                              ? interval[1][0].second
                              : 0,
                1));
  int ans = INT_MAX;
  int lt = 0;
  while (!q.empty()) {
    int t = q.top().first, u = q.top().second;
    q.pop();
    assert(t >= lt);
    lt = t;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first, nt = adj[u][i].second + t;
      if (v == n) {
        ans = min(ans, nt);
        continue;
      }
      if (interval[v].size() != 0) {
        auto it = lower_bound(interval[v].begin(), interval[v].end(),
                              make_pair(nt, INT_MAX));
        if (it != interval[v].begin()) nt = max(nt, (it - 1)->second);
      }
      if (dist[v] > nt) {
        dist[v] = nt;
        q.push(make_pair(nt, v));
      }
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << endl;
}
