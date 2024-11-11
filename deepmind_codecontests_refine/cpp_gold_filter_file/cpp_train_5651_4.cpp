#include <bits/stdc++.h>
using namespace std;
int n, L;
int x[200100], d[200100], t[200100], p[200100];
vector<pair<long long, long long> > g[200100];
long long dist[200100], pa[200100], inf = 1e15;
void dijkstra(int x) {
  for (int i = 0; i < 200100; i++) {
    dist[i] = inf;
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push({0, x});
  dist[x] = 0;
  while (!pq.empty()) {
    pair<int, int> v = pq.top();
    pq.pop();
    for (int i = 0; i < g[v.second].size(); i++) {
      pair<int, int> u = g[v.second][i];
      if (dist[v.second] + u.second < dist[u.first]) {
        pa[u.first] = v.second;
        pq.push({dist[u.first] = dist[v.second] + u.second, u.first});
      }
    }
  }
}
map<int, int> m;
map<pair<int, int>, int> m1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> L;
  set<int> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> d[i] >> t[i] >> p[i];
    if (x[i] - p[i] < 0) continue;
    s.insert(x[i] - p[i]);
    s.insert(x[i] + d[i]);
    if (m1.count({x[i] - p[i], x[i] + d[i]})) {
      int j = m1[{x[i] - p[i], x[i] + d[i]}] - 1;
      if (p[i] + t[i] < p[j] + t[j]) m1[{x[i] - p[i], x[i] + d[i]}] = i + 1;
    } else
      m1[{x[i] - p[i], x[i] + d[i]}] = i + 1;
  }
  s.insert(0);
  s.insert(L);
  for (auto i : s) v.push_back(i);
  for (int i = 0; i < v.size(); i++) {
    m[v[i]] = i;
  }
  for (int i = 1; i < v.size(); i++) {
    g[i].push_back({i - 1, v[i] - v[i - 1]});
    g[i - 1].push_back({i, v[i] - v[i - 1]});
  }
  for (int i = 0; i < n; i++) {
    if (x[i] - p[i] < 0) continue;
    g[m[x[i] - p[i]]].push_back({m[x[i] + d[i]], t[i] + p[i]});
  }
  dijkstra(0);
  cout << dist[v.size() - 1] << endl;
  int x = v.size() - 1;
  vector<int> b;
  while (x) {
    if (abs(v[x] - v[pa[x]]) != dist[x] - dist[pa[x]])
      b.push_back(m1[{v[pa[x]], v[x]}]);
    x = pa[x];
  }
  cout << b.size() << endl;
  reverse(b.begin(), b.end());
  for (auto i : b) {
    cout << i << " ";
  }
}
