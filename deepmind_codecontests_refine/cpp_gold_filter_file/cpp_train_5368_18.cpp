#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, u, v, l;
  long long min_dist = LLONG_MAX;
  cin >> n >> m >> k;
  vector<pair<long long, long long> > adj[n + 10];
  set<long long> s;
  vector<long long> vec;
  for (long long i = 1; i <= m; i++) {
    cin >> u >> v >> l;
    adj[u].push_back({v, l});
    adj[v].push_back({u, l});
  }
  if (k == 0) {
    cout << "-1";
    return 0;
  } else {
    for (long long i = 1; i <= k; i++) {
      long long g;
      cin >> g;
      s.insert(g);
      vec.push_back(g);
    }
    for (long long i = 0; i < k; i++) {
      long long b = vec[i];
      for (long long j = 0; j < adj[b].size(); j++) {
        if (s.find(adj[b][j].first) == s.end()) {
          min_dist = min(min_dist, adj[b][j].second);
        }
      }
    }
    if (min_dist == LLONG_MAX) {
      cout << "-1";
    } else {
      cout << min_dist;
    }
  }
  return 0;
}
