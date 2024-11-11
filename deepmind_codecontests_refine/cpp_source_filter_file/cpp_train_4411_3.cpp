#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, long long>>> adj;
vector<unordered_set<long long>> tra;
long long n;
long long m;
long long dijkstra() {
  long long source = 1;
  long long destination = n;
  long long var[n + 1];
  long long fix[n + 1];
  for (long long i = 1; i <= n; i++) {
    var[i] = 1e9;
  }
  memset(fix, -1, sizeof(fix));
  set<pair<long long, long long>> s;
  s.insert({0, source});
  fix[source] = 0;
  while (s.size()) {
    pair<long long, long long> cur = *(s.begin());
    s.erase(cur);
    fix[cur.second] = cur.first;
    long long leave = 0;
    while (tra[cur.second].count(cur.first + leave)) {
      leave++;
    }
    for (auto x : adj[cur.second]) {
      long long check = cur.first + x.second;
      if (var[x.first] > cur.first + x.second + leave) {
        s.erase({var[x.first], x.first});
        var[x.first] = cur.first + x.second + leave;
        s.insert({var[x.first], x.first});
      }
    }
  }
  return fix[destination];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> m;
  adj.resize(n + 1);
  tra.resize(n + 1);
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  for (long long i = 1; i <= n; i++) {
    long long siz;
    cin >> siz;
    for (long long j = 0; j < siz; j++) {
      long long x;
      cin >> x;
      tra[i].insert(x);
    }
  }
  cout << dijkstra();
  return 0;
}
