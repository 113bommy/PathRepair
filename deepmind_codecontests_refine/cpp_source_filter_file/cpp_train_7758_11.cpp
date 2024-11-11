#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long add(long long x, long long y, long long CMOD = MOD) {
  return (x + y + CMOD + CMOD) % CMOD;
}
long long mult(long long x, long long y, long long CMOD = MOD) {
  return add(x, 0) * add(y, 0) % CMOD;
}
long long fast_expo(long long x, long long y, long long CMOD = MOD) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long ans = fast_expo(x, y / 2, CMOD);
  ans = mult(ans, ans, CMOD);
  if (y & 1) ans = mult(ans, x, CMOD);
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gen(long long x, long long y) {
  if (x == y) return x;
  return x + rng() % (y - x + 1);
}
const int TAM = 1e5 + 100;
const long long INF = 1000000000000000LL;
class MaximumFlow {
  int s, f;

 public:
  struct edge {
    int u, v;
    long long capacity, flow;
    edge() { u = v = capacity = flow = 0; }
    edge(int u_, int v_, long long capacity_, long long flow_)
        : u(u_), v(v_), capacity(capacity_), flow(flow_) {}
  };
  vector<edge> edges;
  vector<vector<int> > graph;
  vector<int> ptr, level;
  queue<int> q;
  int n;
  MaximumFlow() {}
  MaximumFlow(int number) {
    n = number;
    graph.resize(n);
    ptr.assign(n, 0);
    level.resize(n);
  }
  void addEdge(int u, int v, long long capacity) {
    int sz = (int)(edges.size());
    edges.push_back(edge(u, v, capacity, 0));
    edges.push_back(edge(v, u, 0, 0));
    graph[u].push_back(sz);
    graph[v].push_back(sz + 1);
  }
  void updateLevels() {
    level.assign(n, -1);
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
      int topq = q.front();
      q.pop();
      for (int index = 0; index < graph[topq].size(); ++index) {
        int i = graph[topq][index];
        int to = edges[i].v;
        if (edges[i].capacity - edges[i].flow == 0) {
          continue;
        }
        if (level[to] == -1) {
          level[to] = level[topq] + 1;
          q.push(to);
        }
      }
    }
  }
  long long pushFlow(int v, long long flow) {
    if (v == f || flow == 0) {
      return flow;
    }
    for (; ptr[v] < graph[v].size(); ++ptr[v]) {
      int index = graph[v][ptr[v]];
      int to = edges[index].v;
      if (level[v] + 1 == level[to]) {
        long long pushed =
            pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
        if (pushed > 0) {
          edges[index].flow += pushed;
          edges[index ^ 1].flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  long long dinicFlow(int start, int finish) {
    s = start, f = finish;
    long long result = 0;
    while (true) {
      updateLevels();
      if (level[f] == -1) {
        break;
      }
      while (true) {
        long long pushed = pushFlow(start, INF);
        if (pushed == 0) {
          break;
        }
        result += pushed;
      }
      ptr.assign(n, 0);
    }
    return result;
  }
};
int n, m, k;
pair<int, pair<int, int> > E[505];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &E[i].first, &E[i].second.first, &E[i].second.second);
    E[i].first--;
    E[i].second.first--;
  }
  MaximumFlow F;
  long double l = 0;
  long double h = 1e6;
  long double me;
  int iter = 50;
  while (iter--) {
    me = (l + h) / 2;
    F = MaximumFlow(n);
    for (int i = 0; i < m; i++)
      F.addEdge(E[i].first, E[i].second.first, E[i].second.second / me);
    long long mf = F.dinicFlow(0, n - 1);
    if (mf >= k)
      l = me;
    else
      h = me;
  }
  cout << fixed << setprecision(8) << l * k << endl;
  return 0;
}
