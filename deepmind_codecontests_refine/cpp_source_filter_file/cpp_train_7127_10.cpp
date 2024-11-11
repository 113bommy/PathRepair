#include <bits/stdc++.h>
const int N = 52, M = 106, INF = 2000000000;
inline int f(char c) {
  if ('a' <= c && c <= 'z') return c - 'a' + 1;
  return c - 'A' + 27;
}
inline char rf(int i) {
  if (i <= 26) return 'a' + i - 1;
  return 'A' + i - 1;
}
struct edge {
  int capacity, cost, flow;
  edge() {}
  edge(int capacity, int cost, int flow)
      : capacity(capacity), cost(cost), flow(flow) {}
};
edge g[M][M];
int cnt[N + 1][N + 1];
std::vector<int> d(M);
std::vector<std::pair<int, int>> G;
void add_edge(int a, int b, int cap, int cost) {
  g[a][b] = edge(cap, cost, 0);
  g[b][a] = edge(0, -cost, 0);
  G.emplace_back(std::make_pair(a, b));
  G.emplace_back(std::make_pair(b, a));
}
class comp {
 public:
  bool operator()(int a, int b) {
    if (d[a] != d[b])
      return d[a] > d[b];
    else
      return a > b;
  }
};
int main() {
  std::ios_base::sync_with_stdio(0);
  int n, k;
  std::string s, t;
  std::cin >> n >> k;
  std::cin >> s >> t;
  for (int i = 0; i < n; ++i) ++cnt[f(s[i])][f(t[i])];
  for (int i = 1; i <= k; ++i) {
    add_edge(0, i, 1, 0);
    add_edge(i + N, 105, 1, 0);
    for (int j = 1; j <= k; ++j) add_edge(i, j + N, 1, cnt[i][j]);
  }
  int flow = 0, cost = 0;
  while (flow < k) {
    std::vector<int> p(M, -1);
    d.assign(M, -INF);
    d[0] = 0;
    bool kek = true;
    while (kek) {
      kek = false;
      for (int i = 0, a, b, curcap; i < G.size(); ++i) {
        a = G[i].first;
        b = G[i].second;
        curcap = g[a][b].capacity - g[a][b].flow;
        if (curcap > 0 && d[a] != -INF && d[b] < d[a] + g[a][b].cost) {
          d[b] = d[a] + g[a][b].cost;
          p[b] = a;
          kek = true;
        }
      }
    }
    cost += d[M - 1];
    ++flow;
    int cur = M - 1;
    while (p[cur] != -1) {
      g[p[cur]][cur].flow++;
      g[cur][p[cur]].flow--;
      cur = p[cur];
    }
  }
  std::cout << cost << '\n';
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (g[i][j + N].flow) std::cout << rf(j);
  std::cout << '\n';
}
