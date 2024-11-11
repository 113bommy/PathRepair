#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 3;
const long long inf = 1e18;
vector<pair<long long, long long> > adj[N];
map<long long, long long> arr[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long dist[n + 1];
  bool vis[n + 1];
  for (long long i = 0; i < m; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  for (long long i = 1; i <= n; i++) {
    long long tot;
    cin >> tot;
    for (long long j = 0; j < tot; j++) {
      long long q;
      cin >> q;
      arr[i][q]++;
    }
    dist[i] = inf;
    vis[i] = false;
  }
  set<pair<long long, long long> > st;
  st.insert({0, 1});
  dist[1] = 0;
  while (!st.empty()) {
    pair<long long, long long> top = *st.begin();
    st.erase(st.begin());
    if (vis[top.second]) continue;
    vis[top.second] = true;
    long long cur = top.first;
    long long val = top.second;
    while (arr[val].find(cur) != arr[val].end()) {
      cur++;
    }
    for (pair<long long, long long> p : adj[val]) {
      long long wt = p.second;
      long long w = p.first;
      if (wt + cur < dist[w]) {
        dist[w] = wt + cur;
        st.insert({dist[w], w});
      }
    }
  }
  if (dist[n] != inf) {
    cout << dist[n] << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
