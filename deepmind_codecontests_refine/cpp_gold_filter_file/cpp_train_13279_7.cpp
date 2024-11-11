#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v;
  long long cap, flow;
  Edge() {}
  Edge(int u, int v, long long cap) : u(u), v(v), cap(cap), flow(0) {}
};
struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}
  void AddEdge(int u, int v, long long cap) {
    if (u != v) {
      E.emplace_back(u, v, cap);
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(v, u, 0);
      g[v].emplace_back(E.size() - 1);
    }
  }
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  long long DFS(int u, int T, long long flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        long long amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (long long pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  long long MaxFlow(int S, int T) {
    long long total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (long long flow = DFS(S, T)) total += flow;
    }
    return total;
  }
};
const int maxn = 60, maxm = 510;
int main() {
  unordered_map<string, int> id(
      {{"S", 0}, {"M", 1}, {"L", 2}, {"XL", 3}, {"XXL", 4}, {"XXXL", 5}});
  char shirts[][100] = {"S", "M", "L", "XL", "XXL", "XXXL"};
  int cnt[6] = {0}, pn;
  for (int i = 0; i < 6; i++) cin >> cnt[i];
  scanf("%d\n", &pn);
  int s = pn + 6, t = pn + 7;
  Dinic di(6 + pn + 2);
  for (int i = 0; i < 6; i++) di.AddEdge(s, i, cnt[i]);
  for (int i = 1; i <= pn; i++) {
    char ln[100], *tok;
    scanf("%s", ln);
    tok = strtok(ln, ",");
    int u = id[string(tok)];
    di.AddEdge(u, i + 5, 1);
    tok = strtok(NULL, ",");
    if (tok == NULL) continue;
    u = id[string(tok)];
    di.AddEdge(u, i + 5, 1);
  }
  for (int i = 1; i <= pn; i++) di.AddEdge(i + 5, t, 1);
  long long mf = di.MaxFlow(s, t);
  if (mf < pn) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  int tsh[pn + 1];
  for (int u = 0; u < 6; u++) {
    for (auto v : di.g[u]) {
      Edge &e = di.E[v];
      if (e.v > 5 && e.v <= 5 + pn && e.cap && e.flow) tsh[e.v - 5] = e.u;
    }
  }
  for (int i = 1; i <= pn; i++) cout << shirts[tsh[i]] << '\n';
  return 0;
}
