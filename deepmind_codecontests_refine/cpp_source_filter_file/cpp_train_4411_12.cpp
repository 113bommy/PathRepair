#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> g[111111];
long long d[111111];
set<long long> t[111111];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    d[i] = 1e9;
  }
  for (int i = 1; i <= m; i++) {
    long long a, b, cost;
    cin >> a >> b >> cost;
    g[a].push_back({b, cost});
    g[b].push_back({a, cost});
  }
  for (int i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    for (int j = 1; j <= a; j++) {
      long long b;
      cin >> b;
      t[i].insert(b);
    }
  }
  d[1] = 0;
  set<pair<long long, long long>> q;
  q.insert({0, 1});
  while (!q.empty()) {
    long long h = 0;
    int v = q.begin()->second;
    q.erase(q.begin());
    while (t[v].find(d[v]) != t[v].end()) {
      h++;
      d[v]++;
    }
    for (int i = 0; i < g[v].size(); i++) {
      long long to = g[v][i].first, cost = g[v][i].second;
      if (d[to] > d[v] + cost) {
        q.erase({d[to], to});
        d[to] = d[v] + cost;
        q.insert({d[to], to});
      }
    }
    d[v] = d[v] - h;
  }
  if (d[n] == 1e9) {
    cout << -1;
    return 0;
  }
  cout << d[n];
}
