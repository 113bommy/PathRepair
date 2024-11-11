#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long inf = 2e9;
long long dist[N], p[N], n, m;
vector<pair<long long, long long> > adj[N];
void dijkstra(long long s) {
  for (long long i = 1; i <= n; i++) {
    dist[i] = inf;
  }
  dist[s] = 0;
  p[s] = -1;
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      q;
  q.push({0, s});
  while (!q.empty()) {
    long long v = q.top().second;
    long long d = q.top().first;
    q.pop();
    if (d != dist[v]) {
      continue;
    }
    for (auto t : adj[v]) {
      long long to = t.first;
      long long len = t.second;
      if (dist[v] + len < dist[to]) {
        dist[to] = dist[v] + len;
        p[to] = v;
        q.push({dist[to], to});
      }
    }
  }
}
void path(vector<long long> &v, long long d) {
  if (p[d] != -1) {
    path(v, p[d]);
  }
  v.push_back(d);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dijkstra(1);
  if (dist[n] == inf) {
    cout << "-1" << endl;
    return 0;
  } else {
    vector<long long> ans;
    path(ans, n);
    for (auto t : ans) {
      cout << t << " ";
    }
    cout << endl;
  }
  return 0;
}
