#include <bits/stdc++.h>
int n, m;
long long d[200001];
std::vector<std::vector<std::pair<int, long long> > > G(200001);
std::priority_queue<std::pair<long long, int> > Q;
int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    scanf("%d%d%I64d", &u, &v, &w);
    G[u].push_back(std::make_pair(v, w));
    G[v].push_back(std::make_pair(u, w));
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &d[i]);
    Q.push(std::make_pair(-d[i], i));
  }
  while (!Q.empty()) {
    std::pair<long long, int> p;
    p = Q.top();
    Q.pop();
    if (d[p.second] != p.first) continue;
    for (int i = 0; i < G[p.second].size(); i++) {
      if (G[p.second][i].second * 2 + (-p.first) < d[G[p.second][i].first]) {
        d[G[p.second][i].first] = G[p.second][i].second * 2 + (-p.first);
        Q.push(std::make_pair(-d[G[p.second][i].first], G[p.second][i].first));
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", d[i]);
  return 0;
}
