#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000LL;
const long double EPS = 1e-9;
bool done[3009];
int used[3009];
struct Edge {
  int from, to, next;
  long long cap, flow;
  long long cost;
  Edge(int from, int to, int next, long long cap, long long cost) {
    this->from = from;
    this->to = to;
    this->next = next;
    this->cap = cap;
    this->cost = cost;
    this->flow = 0;
  }
};
struct MinCostFlow {
  long long infF = (numeric_limits<long long>::max() / 4);
  long long infC = (numeric_limits<long long>::max() / 4);
  int n;
  int S, T, ne[3009];
  long long d[3009], pi[3009];
  vector<Edge> E;
  void init(int _n) {
    n = _n;
    memset(ne, -1, n * sizeof(int));
    fill(pi, pi + n, 0);
    E.clear();
  }
  void addEdge(int u, int v, long long cap = 1, long long cost = 0) {
    E.push_back(Edge(u, v, ne[u], cap, cost));
    ne[u] = (int)E.size() - 1;
    E.push_back(Edge(v, u, ne[v], 0, -cost));
    ne[v] = (int)E.size() - 1;
  }
  bool djkstra() {
    memset(used, -1, n * sizeof(int));
    memset(done, 0, n * sizeof(bool));
    fill(d, d + n, infC);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > >
        q;
    q.push(make_pair(0, S));
    d[S] = 0;
    while (!q.empty()) {
      int u = q.top().second, v;
      q.pop();
      if (done[u]) continue;
      done[u] = true;
      for (int i = ne[u]; i != -1; i = E[i].next) {
        v = E[i].to;
        long long pot = d[u] + pi[u] - pi[v];
        if (E[i].cap > E[i].flow && pot + E[i].cost < d[v]) {
          d[v] = pot + E[i].cost;
          used[v] = i;
          q.push(make_pair(d[v], v));
        }
      }
    }
    for (int i = 0; i < n; i++) pi[i] = min(pi[i] + d[i], infC);
    return d[T] != infC;
  }
  bool belmanford() {
    memset(used, -1, n * sizeof(int));
    memset(done, 0, n * sizeof(bool));
    fill(d, d + n, infC);
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front(), v;
      q.pop();
      done[u] = 0;
      for (int i = ne[u]; i != -1; i = E[i].next) {
        v = E[i].to;
        long long pot = d[u] + pi[u] - pi[v];
        if (E[i].cap > E[i].flow && pot + E[i].cost < d[v]) {
          d[v] = pot + E[i].cost;
          used[v] = i;
          if (done[v] == 0) {
            q.push(v);
            done[v] = 1;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) pi[i] = min(pi[i] + d[i], infC);
    return d[T] != infC;
  }
  pair<long long, long long> maxFlow(int src, int snk) {
    S = src, T = snk;
    long long flow = 0;
    long long cost = 0;
    while (belmanford()) {
      snk = T;
      long long bflow = infF;
      while (snk != S) {
        bflow = min(bflow, E[used[snk]].cap - E[used[snk]].flow);
        snk = E[used[snk]].from;
      }
      snk = T;
      while (snk != S) {
        E[used[snk]].flow += bflow;
        E[used[snk] ^ 1].flow -= bflow;
        cost += E[used[snk]].cost * bflow;
        snk = E[used[snk]].from;
      }
      flow += bflow;
    }
    return make_pair(flow, cost);
  }
} maxf;
const int N = 55;
int c[N][N];
int n, k;
int ok(int allow) {
  int S = 0, T = n;
  maxf.init(n + 7);
  maxf.addEdge(S, 1, allow, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (c[i][j]) {
        maxf.addEdge(i, j, c[i][j], 0);
        maxf.addEdge(i, j, INF, 1);
      }
    }
  }
  auto fl = maxf.maxFlow(S, T);
  if (fl.first == 0) return false;
  return fl.second <= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cin >> c[i][j];
  }
  int lo = 0, hi = INF;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ok(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << "\n";
  return 0;
}
