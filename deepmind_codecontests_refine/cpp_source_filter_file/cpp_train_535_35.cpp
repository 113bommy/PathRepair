#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = mod;
const long double eps = 1e-8;
const long long sz = 200;
long long c, d;
struct edge {
  long long to, cap, cnt, rev;
};
vector<edge> G[50 * sz + 2];
pair<long long, long long> par[50 * sz + 2];
long long dist[50 * sz + 2];
void add_edge(long long from, long long to, long long cap = mod) {
  for (long long i = 0; i < sz - 1; i++) {
    long long a = i * 50 + from;
    long long b = i * 50 + to + 50;
    G[a].push_back({b, cap, 0, (long long)G[b].size()});
    G[b].push_back({a, 0, 0, (long long)G[a].size() - 1});
  }
}
void init(long long n) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < sz - 1; j++) {
      long long a = j * 50 + i;
      long long b = a + 50;
      G[a].push_back({b, mod, mod, (long long)G[b].size()});
      G[b].push_back({a, -mod, -mod, (long long)G[a].size() - 1});
    }
  }
}
long long minimum_road(long long s, long long t) {
  fill(par, par + 50 * sz + 2, pair<long long, long long>{-1, -1});
  fill(dist, dist + 50 * sz + 2, INF);
  dist[s] = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      q;
  q.push({0, s});
  while (!q.empty()) {
    pair<long long, long long> p = q.top();
    q.pop();
    long long id = p.second;
    if (id == t) continue;
    if (p.first > dist[id]) continue;
    for (long long j = 0; j < G[id].size(); j++) {
      if (G[id][j].cap > 0) {
        long long to = G[id][j].to;
        long long cnt = G[id][j].cnt;
        long long cost;
        if (cnt >= mod / 2) {
          cost = c;
        } else if (cnt <= -mod / 2) {
          cost = -c;
        } else if (cnt >= 0) {
          cost = c + d * (2 * cnt + 1);
        } else {
          cost = -c + d * (2 * cnt + 1);
        }
        long long nd = p.first + cost;
        if (nd < dist[to]) {
          dist[to] = nd;
          par[to] = {id, j};
          q.push({dist[to], to});
        }
      }
    }
  }
  long long cur = t;
  while (cur != s) {
    long long p = par[cur].first, j = par[cur].second;
    G[p][j].cap--;
    G[p][j].cnt++;
    if (G[p][j].rev >= 0) {
      edge &e = G[cur][G[p][j].rev];
      e.cap++;
      e.cnt--;
    }
    cur = p;
  }
  return dist[t];
}
long long minimum_cost_flow(long long s, long long t, long long k) {
  long long ret = 0;
  for (long long i = 0; i < k; i++) {
    long long z = minimum_road(s, t);
    ret += z;
  }
  return ret;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k >> c >> d;
  vector<long long> a(k);
  for (long long i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    add_edge(a, b);
    add_edge(b, a);
  }
  init(n);
  long long s = 50 * sz;
  long long t = s + 1;
  for (long long i = 0; i < k; i++) {
    G[s].push_back({a[i], 1, mod, (long long)G[a[i]].size()});
    G[a[i]].push_back({s, 0, -mod, (long long)G[s].size() - 1});
  }
  for (long long i = 0; i < sz; i++) {
    G[50 * i].push_back({t, mod, mod, (long long)G[t].size()});
    G[t].push_back({50 * i, 0, mod, (long long)G[50 * i].size() - 1});
  }
  long long ans = minimum_cost_flow(s, t, k);
  ans -= 2 * c * k;
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
