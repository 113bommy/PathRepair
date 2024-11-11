#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const long long INFFLUJO = 1e14;
const long long INFCOSTO = 1e14;
struct edge {
  int u, v;
  long long cap, flow;
  long long cost;
  long long rem() { return cap - flow; }
};
int nodes;
vector<int> G[MAXN];
vector<edge> e;
void addEdge(int u, int v, long long cap, long long cost) {
  G[u].push_back(((int)e.size()));
  e.push_back((edge){u, v, cap, 0, cost});
  G[v].push_back(((int)e.size()));
  e.push_back((edge){v, u, 0, 0, -cost});
}
long long dist[MAXN], mnCost;
int pre[MAXN];
long long cap[MAXN], mxFlow;
bool in_queue[MAXN];
void flow(int s, int t, int k) {
  memset(in_queue, 0, sizeof(in_queue));
  mxFlow = mnCost = 0;
  while (true) {
    fill(dist, dist + nodes, INFCOSTO);
    dist[s] = 0;
    memset(pre, -1, sizeof(pre));
    pre[s] = 0;
    memset(cap, 0, sizeof(cap));
    cap[s] = INFFLUJO;
    queue<int> q;
    q.push(s);
    in_queue[s] = 1;
    while (((int)q.size())) {
      int u = q.front();
      q.pop();
      in_queue[u] = 0;
      for (auto it : G[u]) {
        edge &E = e[it];
        if (E.rem() && dist[E.v] > dist[u] + E.cost && dist[u] + E.cost <= k) {
          dist[E.v] = dist[u] + E.cost;
          pre[E.v] = it;
          cap[E.v] = min(cap[u], E.rem());
          if (!in_queue[E.v]) q.push(E.v), in_queue[E.v] = 1;
        }
      }
    }
    if (pre[t] == -1) break;
    int cp;
    if (cap[t] * dist[t] <= k) {
      cp = cap[t];
    } else {
      cp = k / dist[t];
      mxFlow += cp;
      break;
    }
    k -= cp * dist[t];
    mxFlow += cp;
    mnCost += cp * dist[t];
    for (int v = t; v != s; v = e[pre[v]].u) {
      e[pre[v]].flow += cp;
      e[pre[v] ^ 1].flow -= cp;
    }
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long c;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(n); j++) {
      scanf("%lld", &c);
      if (c != 0) {
        addEdge(i, j, c, 0);
        addEdge(i, j, 100000, 1);
      }
    }
  nodes = n;
  flow(0, n - 1, k);
  printf("%lld\n", mxFlow);
}
