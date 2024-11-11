#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
double PI = 4 * atan(1);
const long long INF = 1e18;
struct Edge {
  int v, flow, C, rev, cost;
};
template <int SZ>
struct mcf {
  pair<long long, long long> pre[SZ];
  long long cost[SZ];
  int SC, SNC;
  vector<Edge> adj[SZ];
  void addEdge(int u, int v, int C, int cost) {
    Edge a{v, 0, C, (int)adj[v].size(), cost};
    Edge b{u, 0, 0, (int)adj[u].size(), -cost};
    adj[u].push_back(a);
    adj[v].push_back(b);
  }
  bool bfs() {
    for (int i = 0; i < SZ; i++) cost[i] = INF;
    cost[0] = 0;
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        todo;
    todo.push({0, SC});
    while (todo.size()) {
      pair<long long, long long> x = todo.top();
      todo.pop();
      if (x.second == SNC) return 1;
      for (auto a : adj[x.second])
        if (x.first + a.cost < cost[a.v] && a.flow < a.C) {
          pre[a.v] = {x.second, a.rev};
          cost[a.v] = x.first + a.cost;
          todo.push({cost[a.v], a.v});
        }
    }
    return 0;
  }
  pair<long long, long long> mincostflow(int first, int sc, int snc) {
    SC = sc, SNC = snc;
    long long flo = 0, ans = 0;
    for (int i = 0; i < first; i++) {
      bfs();
      flo++, ans += cost[SNC];
      for (int x = SNC; x != SC; x = pre[x].first) {
        adj[x][pre[x].second].flow--;
        int t = adj[x][pre[x].second].rev;
        adj[pre[x].first][t].flow++;
      }
    }
    return {flo, ans};
  }
};
mcf<2202> m;
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i < n + 1; i++) {
    int a;
    cin >> a;
    m.addEdge(0, i, 1, a);
  }
  for (int i = 1; i < n + 1; i++) {
    int b;
    cin >> b;
    m.addEdge(i, n + 1, 1, b);
  }
  for (int i = 1; i < n; i++) m.addEdge(i, i + 1, MOD, 0);
  pair<long long, long long> x = m.mincostflow(k, 0, n + 1);
  cout << x.second;
}
