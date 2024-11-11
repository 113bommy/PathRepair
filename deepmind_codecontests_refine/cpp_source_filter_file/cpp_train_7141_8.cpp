#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void minimize(X &x, const Y &y) {
  if (x > y) x = y;
}
template <class X, class Y>
void maximize(X &x, const Y &y) {
  if (x < y) x = y;
}
template <class T>
T Abs(const T &x) {
  return (x < 0 ? -x : x);
}
class MaxFlowMinCost {
 private:
  static const int INF = (int)1e9 + 7;
  struct Edge {
    int from, to, capa, flow, cost;
    Edge() { from = to = capa = flow = cost = 0; }
    Edge(int u, int v, int ca, int co) {
      from = u;
      to = v;
      capa = ca;
      flow = 0;
      cost = co;
    }
    int residental(void) const { return (capa - flow); }
  };
  int n;
  vector<vector<int> > adj;
  vector<Edge> edge;
  vector<int> dist, trace;
  bool FordBellman(int s, int t) {
    for (int i = (1), _b = (n); i <= _b; i = i + 1) dist[i] = INF;
    for (int i = (1), _b = (n); i <= _b; i = i + 1) trace[i] = -1;
    vector<bool> inQueue(n + 7, false);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    inQueue[s] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inQueue[u] = false;
      for (__typeof((adj[u]).begin()) it = (adj[u]).begin();
           it != (adj[u]).end(); it++)
        if (edge[*it].residental() > 0) {
          int v = edge[*it].to;
          if (dist[v] > dist[u] + edge[*it].cost) {
            dist[v] = dist[u] + edge[*it].cost;
            trace[v] = *it;
            if (!inQueue[v]) {
              q.push(v);
              inQueue[v] = true;
            }
          }
        }
    }
    return (dist[t] < INF);
  }

 public:
  MaxFlowMinCost() { n = 0; }
  MaxFlowMinCost(int n) {
    this->n = n;
    adj.assign(n + 7, vector<int>());
    dist.assign(n + 7, 0);
    trace.assign(n + 7, 0);
  }
  void addEdge(int u, int v, int ca, int co) {
    adj[u].push_back(edge.size());
    edge.push_back(Edge(u, v, ca, co));
    adj[v].push_back(edge.size());
    edge.push_back(Edge(v, u, 0, -co));
  }
  pair<int, int> getFlow(int s, int t) {
    int totFlow = 0;
    int totCost = 0;
    while (FordBellman(s, t)) {
      int delta = INF;
      for (int u = t; u != s; u = edge[trace[u]].from)
        delta = min(delta, edge[trace[u]].residental());
      for (int u = t; u != s; u = edge[trace[u]].from) {
        edge[trace[u]].flow += delta;
        edge[trace[u] ^ 1].flow -= delta;
      }
      totFlow += delta;
      totCost += delta * dist[t];
    }
    return (make_pair(totFlow, totCost));
  }
};
const int MOD = 7;
int value[100100], ___next[100100][MOD], n;
vector<int> pos[100100];
void process(void) {
  if (scanf("%d", &n) != 1) exit(EXIT_SUCCESS);
  for (int i = (1), _b = (n); i <= _b; i = i + 1) scanf("%d", &value[i]);
  for (int j = (n), _b = (n + 1); j <= _b; j = j + 1)
    for (int i = 0, _n = (MOD); i < _n; i = i + 1) ___next[j][i] = n + 1;
  for (int i = (n - 1), _a = (1); i >= _a; i = i - 1) {
    for (int j = 0, _n = (MOD); j < _n; j = j + 1)
      ___next[i][j] = ___next[i + 1][j];
    ___next[i][value[i + 1] % MOD] = i + 1;
  }
  for (int i = 0, _n = (100100); i < _n; i = i + 1) pos[i].clear();
  for (int i = (1), _b = (n); i <= _b; i = i + 1) pos[value[i]].push_back(i);
  MaxFlowMinCost mfmc(2 * n + 3);
  int src = 2 * n + 1;
  int snk = 2 * n + 2;
  int fake = 2 * n + 3;
  for (int i = (1), _b = (n); i <= _b; i = i + 1) {
    mfmc.addEdge(fake, (2 * (i)-1), 1, 0);
    mfmc.addEdge((2 * (i)-1), (2 * (i)), 1, -1);
    mfmc.addEdge((2 * (i)), snk, 1, 0);
    int nextSame = i, nextUp = i, nextDown = i;
    for (int pmp = 0, _n = (4); pmp < _n; pmp = pmp + 1) {
      nextSame = ___next[nextSame][value[i] % MOD];
      if (nextSame <= n) mfmc.addEdge((2 * (i)), (2 * (nextSame)-1), 1, 0);
      int tmp = upper_bound((pos[value[i] + 1]).begin(),
                            (pos[value[i] + 1]).end(), nextUp) -
                pos[value[i] + 1].begin();
      nextUp = tmp < pos[value[i] + 1].size() ? pos[value[i] + 1][tmp] : n + 1;
      if (nextUp <= n) mfmc.addEdge((2 * (i)), (2 * (nextUp)-1), 1, 0);
      tmp = upper_bound((pos[value[i] - 1]).begin(), (pos[value[i] - 1]).end(),
                        nextDown) -
            pos[value[i] + 1].begin();
      nextDown =
          tmp < pos[value[i] - 1].size() ? pos[value[i] - 1][tmp] : n + 1;
      if (nextDown <= n) mfmc.addEdge((2 * (i)), (2 * (nextDown)-1), 1, 0);
    }
  }
  mfmc.addEdge(src, fake, 4, 0);
  printf("%d\n", -mfmc.getFlow(src, snk).second);
}
int main(void) {
  while (true) process();
  return 0;
}
