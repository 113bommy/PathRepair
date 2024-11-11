#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
struct Edge {
  int u, v, l;
};
vector<std::pair<long long, long long> > List[100100];
vector<std::pair<long long, long long> > List1[100100];
void Unique(vector<std::pair<long long, long long> >& v) {
  if (v.size() == 0) return;
  vector<std::pair<long long, long long> > tmp = v;
  sort(tmp.begin(), tmp.end());
  v.clear();
  v.push_back(tmp[0]);
  for (int i = 1; i < tmp.size(); ++i) {
    if (tmp[i].first > v.back().first ||
        (tmp[i].first == v.back().first && tmp[i] <= v.back())) {
      v.push_back(tmp[i]);
    }
  }
  return;
}
long long distL[100100];
long long distR[100100];
long long pathL[100100];
long long pathR[100100];
void Dijkstra(int s, long long dist[], int n, long long paths[]) {
  for (int i = 1; i <= n; ++i) {
    dist[i] = MOD * 100000LL;
  }
  vector<bool> vis(n + 1, 0);
  dist[s] = 0;
  paths[s] = 1;
  priority_queue<std::pair<long long, long long>,
                 vector<std::pair<long long, long long> >,
                 greater<std::pair<long long, long long> > >
      pq;
  pq.push({0, s});
  while (!pq.empty()) {
    std::pair<long long, long long> p = pq.top();
    pq.pop();
    if (vis[p.second]) continue;
    vis[p.second] = 1;
    for (std::pair<long long, long long> c : List[p.second]) {
      if (dist[c.first] > dist[p.second] + c.second) {
        dist[c.first] = dist[p.second] + c.second;
        paths[c.first] = paths[p.second];
        pq.push({dist[c.first], c.first});
      } else if (dist[c.first] == dist[p.second] + c.second)
        paths[c.first] += paths[p.second], paths[c.first] %= MOD;
    }
  }
  vis.clear();
  return;
}
int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<Edge> edges;
  for (int i = 0; i < (m); ++i) {
    int u, v, l;
    scanf("%d %d %d", &u, &v, &l);
    edges.push_back({u, v, l});
    List[u].push_back({v, l});
  }
  for (int i = 1; i <= n; ++i) Unique(List[i]);
  Dijkstra(s, distL, n, pathL);
  for (int i = 1; i <= n; ++i) {
    for (std::pair<long long, long long> c : List[i])
      List1[c.first].push_back({i, c.second});
  }
  for (int i = 1; i <= n; ++i) List[i] = List1[i];
  Dijkstra(t, distR, n, pathR);
  for (int i = 1; i <= n; ++i) List[i].clear();
  for (int i = 0; i < m; ++i) {
    int u = edges[i].u, v = edges[i].v, l = edges[i].l;
    long long d = distL[t] - distL[u] - distR[v] - 1;
    if (d == l - 1 && pathL[u] * pathR[v] % MOD == pathL[t])
      puts("YES");
    else {
      if (d < 1)
        puts("NO");
      else
        printf("CAN %lld\n", l - d);
    }
  }
  return 0;
}
