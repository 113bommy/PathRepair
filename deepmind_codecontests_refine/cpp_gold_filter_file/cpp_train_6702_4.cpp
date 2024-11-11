#include <bits/stdc++.h>
using namespace std;
const long long int N = 405;
struct MinCostFlow {
  struct Edge {
    long long int t;
    long long int f;
    long double c;
    Edge *next, *rev;
    Edge(long long int _t, long long int _f, long double _c, Edge* _next)
        : t(_t), f(_f), c(_c), next(_next) {}
  };
  vector<Edge*> E;
  long long int addV() {
    E.push_back((Edge*)0);
    return E.size() - 1;
  }
  Edge* makeEdge(long long int s, long long int t, long long int f,
                 long double c) {
    return E[s] = new Edge(t, f, c, E[s]);
  }
  void addEdge(long long int s, long long int t, long long int f,
               long double c) {
    Edge *e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
    e1->rev = e2, e2->rev = e1;
  }
  pair<long long int, long double> minCostFlow(long long int vs,
                                               long long int vt, bool maxFlow) {
    long long int n = E.size();
    long long int flow = 0;
    long double cost = 0;
    const long double MAX_COST = 1e18;
    const long long int MAX_FLOW = 1e18;
    for (;;) {
      vector<long double> dist(n, MAX_COST);
      vector<long long int> am(n, 0);
      vector<Edge*> prev(n);
      vector<bool> inQ(n, false);
      queue<long long int> que;
      dist[vs] = 0;
      am[vs] = MAX_FLOW;
      que.push(vs);
      inQ[vs] = true;
      while (!que.empty()) {
        long long int u = que.front();
        long double c = dist[u];
        que.pop();
        inQ[u] = false;
        for (Edge* e = E[u]; e; e = e->next)
          if (e->f > 0) {
            long double nc = c + e->c;
            if (nc < dist[e->t]) {
              dist[e->t] = nc;
              prev[e->t] = e;
              am[e->t] = min(am[u], e->f);
              if (!inQ[e->t]) {
                que.push(e->t);
                inQ[e->t] = true;
              }
            }
          }
      }
      if (maxFlow) {
        if (dist[vt] == MAX_COST) break;
      } else {
        if (dist[vt] >= 0) break;
      }
      long long int by = am[vt];
      long long int u = vt;
      flow += by;
      cost += by * dist[vt];
      while (u != vs) {
        Edge* e = prev[u];
        e->f -= by;
        e->rev->f += by;
        u = e->rev->t;
      }
    }
    return make_pair(flow, cost);
  }
};
long double x[N], y[N];
long double dist(long long int a, long long int b) {
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> x[i] >> y[i];
    }
    MinCostFlow G;
    long long int id[2 * n + 2];
    for (i = 0; i < 2 * n + 2; i++) {
      id[i] = G.addV();
    }
    long long int src = id[0], sink = id[2 * n + 1];
    for (i = 1; i <= n; i++) {
      G.addEdge(src, id[i], 2, 0);
    }
    for (i = n + 1; i <= 2 * n; i++) {
      G.addEdge(id[i], sink, 1, 0);
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (y[i] > y[j]) {
          G.addEdge(id[i], id[j + n], 1, dist(i, j));
        }
      }
    }
    cout << setprecision(10) << fixed;
    pair<long long int, long double> res = G.minCostFlow(src, sink, true);
    if (res.first == n - 1) {
      cout << res.second;
    } else {
      cout << -1;
    }
  }
}
