#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const long long INF = 1e18 + 10;
struct Edge {
  int v, to, w;
  bool erased;
};
vector<Edge> es;
vector<int> g[MAXN];
int n, m, L, s, t;
bool read() {
  if (scanf("%d%d%d%d%d", &n, &m, &L, &s, &t) < 5) {
    return false;
  }
  for (int i = 0; i < (int)n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < (int)m; ++i) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    g[a].push_back(((int)(es).size()));
    es.push_back(Edge{a, b, w, w == 0});
    g[b].push_back(((int)(es).size()));
    es.push_back(Edge{b, a, w, w == 0});
  }
  return true;
}
vector<long long> calc_dist(int s) {
  vector<long long> dist(n, INF);
  dist[s] = 0;
  set<pair<long long, int>> S;
  S.insert(make_pair(dist[s], s));
  while (!S.empty()) {
    int v = S.begin()->second;
    S.erase(S.begin());
    for (int id : g[v]) {
      const auto& e = es[id];
      if (dist[e.to] > dist[v] + e.w) {
        S.erase(make_pair(dist[e.to], e.to));
        dist[e.to] = dist[v] + e.w;
        S.insert(make_pair(dist[e.to], e.to));
      }
    }
  }
  return dist;
}
bool solve() {
  for (auto& e : es)
    if (e.erased) e.w = 1;
  auto d_t = calc_dist(t);
  if (d_t[s] > L) {
    return false;
  }
  set<pair<long long, int>> S;
  vector<long long> dist(n, INF);
  dist[s] = 0;
  S.insert(make_pair(dist[s], 0));
  while (!S.empty()) {
    int v = S.begin()->second;
    S.erase(S.begin());
    for (int id : g[v]) {
      auto& e = es[id];
      if (e.erased) {
        int aux = max(0LL, L - (dist[v] + e.w + d_t[e.to]));
        e.w += aux;
        es[id ^ 1].w += aux;
      }
      if (dist[e.to] > dist[v] + e.w) {
        S.erase(make_pair(dist[e.to], e.to));
        dist[e.to] = dist[v] + e.w;
        S.insert(make_pair(dist[e.to], e.to));
      }
    }
  }
  d_t = calc_dist(t);
  if (d_t[s] != L) {
    return false;
  }
  puts("YES");
  for (int i = 0; i < ((int)(es).size()); i += 2) {
    const auto& e = es[i];
    printf("%d %d %d\n", e.v, e.to, e.w);
  }
  return true;
}
int main() {
  while (read()) {
    if (!solve()) {
      puts("NO");
    }
  }
  return 0;
}
