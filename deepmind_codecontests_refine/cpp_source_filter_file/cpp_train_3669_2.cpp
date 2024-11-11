#include <bits/stdc++.h>
using namespace std;
const long long int inf = 5 * (1e+8);
const long long int mod = 1e+9 + 7;
long long int n, m, a, b, c;
vector<long long int> adj[200005];
void init() {
  for (long long int i = 0; i < 200005; i++) {
    adj[i].clear();
  }
}
void bfs(long long int src, vector<long long int> &dist) {
  vector<bool> vis(dist.size() + 1, 0);
  dist[src] = 0;
  queue<long long int> q;
  q.push(src);
  while (!q.empty()) {
    long long int curr = q.front();
    q.pop();
    vis[curr] = 1;
    for (auto i : adj[curr]) {
      if (!vis[i]) {
        dist[i] = min(dist[i], dist[curr] + 1);
        q.push(i);
      }
    }
  }
}
int32_t main() {
  long long int T;
  cin >> T;
  while (T--) {
    init();
    cin >> n >> m >> a >> b >> c;
    vector<long long int> prices(m);
    for (long long int i = 0; i < m; i++) cin >> prices[i];
    for (long long int i = 0; i < m; i++) {
      long long int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    sort(prices.begin(), prices.end());
    vector<long long int> pre(m + 1, 0);
    for (long long int i = 1; i < m + 1; i++)
      pre[i] = pre[i - 1] + prices[i - 1];
    vector<long long int> da(n + 1, inf), db(n + 1, inf), dc(n + 1, inf);
    da[0] = 0;
    db[0] = 0;
    dc[0] = 0;
    bfs(a, da);
    bfs(b, db);
    bfs(c, dc);
    long long int ans = inf;
    for (long long int i = 1; i <= n; i++) {
      if (da[i] + db[i] + dc[i] <= m)
        ans = min(ans, pre[db[i]] + pre[db[i] + da[i] + dc[i]]);
    }
    cout << ans << '\n';
  }
  return 0;
}
