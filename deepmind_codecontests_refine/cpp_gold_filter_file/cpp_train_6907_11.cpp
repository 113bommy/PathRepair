#include <bits/stdc++.h>
using namespace ::std;
const int INF = int(1e9);
const long long INF64 = (long long)(1e18);
long long n, m;
vector<vector<pair<long long, long long> > > g;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  g = vector<vector<pair<long long, long long> > >(n + 1);
  for (long long i = 0; i < m; i++) {
    long long a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(make_pair(b, w));
    g[b].push_back(make_pair(a, w));
  }
  long long s = 1;
  long long f = n;
  vector<long long> dist(n + 1, INF64);
  vector<long long> prev(n + 1);
  prev[s] = -1;
  dist[s] = 0;
  set<pair<long long, long long> > unused;
  unused.insert(make_pair(0, s));
  while (!unused.empty()) {
    long long next = unused.begin()->second;
    unused.erase(unused.begin());
    for (auto edge : g[next]) {
      long long to = edge.first;
      long long wt = edge.second;
      if (dist[next] + wt < dist[to]) {
        prev[to] = next;
        unused.erase(make_pair(dist[to], to));
        dist[to] = dist[next] + wt;
        unused.insert(make_pair(dist[to], to));
      }
    }
  }
  if (dist[f] == INF64) return cout << -1, 0;
  long long curr = f;
  vector<long long> res;
  while (curr != -1) {
    res.push_back(curr);
    curr = prev[curr];
  }
  reverse(res.begin(), res.end());
  for (long long i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
  return 0;
}
