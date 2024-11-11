#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, cost;
  edge(int a, int b) : to(a), cost(b) {}
};
int main(int argc, char const* argv[]) {
  int n, m, s, g;
  cin >> n >> m >> s >> g;
  s--;
  g--;
  vector<pair<int, int> > V1[1000];
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    V1[u].push_back(pair<int, int>(v, w));
    V1[v].push_back(pair<int, int>(u, w));
  }
  vector<edge> V[1000];
  for (int i = 0; i < n; i++) {
    int t, c;
    cin >> t >> c;
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > >
        que;
    que.push(pair<long long, int>(0, i));
    bool visit[1000];
    memset(visit, false, sizeof visit);
    while (!que.empty()) {
      pair<long long, int> p = que.top();
      que.pop();
      int v = p.second;
      if (visit[v]) continue;
      if (p.first > t) break;
      visit[v] = true;
      if (v != i) V[i].push_back(edge(v, c));
      for (int j = 0; j < V1[v].size(); j++) {
        que.push(
            pair<long long, int>(p.first + V1[v][j].second, V1[v][j].first));
      }
    }
  }
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      que;
  que.push(pair<long long, int>(0, s));
  long long d[1000];
  fill(d, d + 1000, LLONG_MAX);
  d[s] = 0;
  while (!que.empty()) {
    pair<long long, int> p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] > p.first) continue;
    for (int i = 0; i < V[v].size(); i++) {
      edge e = V[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(pair<long long, int>(d[e.to], e.to));
      }
    }
  }
  if (d[g] == 1 << 28) d[g] = -1;
  cout << d[g] << endl;
  return 0;
}
