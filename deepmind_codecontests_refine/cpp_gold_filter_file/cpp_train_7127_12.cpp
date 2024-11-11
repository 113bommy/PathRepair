#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000015;
const int MOD = 1000000007;
struct MinCostMaxFlow {
  int N;
  vector<vector<int> > G;
  vector<vector<int> > cap, flow;
  vector<vector<int> > cost;
  vector<int> dist;
  vector<int> found;
  vector<int> dad;
  MinCostMaxFlow(int N)
      : N(N),
        G(N),
        cap(N, vector<int>(N)),
        flow(N, vector<int>(N)),
        cost(N, vector<int>(N)),
        found(N),
        dist(N),
        dad(N) {}
  void add_edge(int from, int to, int capacity, int c) {
    G[from].push_back(to);
    G[to].push_back(from);
    cap[from][to] = capacity;
    cap[to][from] = 0;
    cost[from][to] = c;
    cost[to][from] = -1 * c;
  }
  bool relax_edge(int u, int v) {
    if (dist[u] + cost[u][v] < dist[v]) {
      dad[v] = u;
      dist[v] = dist[u] + cost[u][v];
      return true;
    }
    return false;
  }
  bool bellmanford(int s, int t) {
    int u, v;
    fill(dad.begin(), dad.end(), -1);
    fill(dist.begin(), dist.end(), (double)1e9);
    fill(found.begin(), found.end(), 0);
    queue<int> Q;
    dad[s] = s;
    dist[s] = 0.0;
    Q.push(s);
    found[s] = true;
    while (!Q.empty()) {
      u = Q.front();
      found[u] = false;
      Q.pop();
      if (u == t) continue;
      for (int i = 0; i <= ((int)(G[u].size())) - 1; i++) {
        v = G[u][i];
        if (cap[u][v] <= flow[u][v]) continue;
        if (relax_edge(u, v) and !found[v]) Q.push(v), found[v] = true;
      }
    }
    return (dad[t] != -1);
  }
  pair<int, int> GetMaxFlow(int s, int t) {
    int totflow = 0;
    int totcost = 0.0;
    while (bellmanford(s, t)) {
      for (int x = t; x != s; x = dad[x]) {
        flow[dad[x]][x]++;
        flow[x][dad[x]]--;
      }
      totflow++;
      totcost += dist[t];
    }
    return make_pair(totflow, totcost);
  }
};
int toInt(char x) {
  if (x >= 'a' and x <= 'z') return (int)(x - 'a' + 1);
  return (int)(x - 'A' + 27);
}
char toChar(int x) {
  if (x <= 26) {
    return 'a' + x - 1;
  }
  return 'A' + x - 27;
}
int D[200][200];
int main() {
  int n, k;
  scanf("%d", &n), scanf("%d", &k);
  string P, Q;
  cin >> P >> Q;
  memset(D, 0, sizeof D);
  for (int i = 0; i <= n - 1; i++) {
    D[toInt(P[i])][toInt(Q[i])]++;
  }
  int src = 0;
  int sink = 2 * k + 1;
  MinCostMaxFlow F(sink + 1);
  for (int i = 1; i <= k; i++) F.add_edge(src, i, 1, 0);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++) F.add_edge(i, k + j, 1, -1 * D[i][j]);
  for (int i = 1; i <= k; i++) F.add_edge(k + i, sink, 1, 0);
  pair<int, int> ans = F.GetMaxFlow(src, sink);
  printf("%d\n", -1 * ans.second);
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= ((int)(F.G[i].size())) - 1; j++) {
      int v = F.G[i][j];
      if (F.flow[i][v] == 1) {
        v -= k;
        printf("%c", toChar(v));
      }
    }
  }
  puts("");
  return 0;
}
