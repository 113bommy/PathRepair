#include <bits/stdc++.h>
using namespace std;
const int P = 1e8 + 1;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 105;
const long long INF = 1e9 + 7;
const long long LINF = 1e15 + 7;
struct MinCost {
  const static int N = 2e4 + 7;
  const static int M = 1e5 + 7;
  struct Edge {
    int s, t, cap, cost, nxt;
    Edge() {}
    Edge(int _s, int _t, int _cap, int _cost, int _nxt) {
      s = _s, t = _t, cap = _cap, cost = _cost, nxt = _nxt;
    }
  } e[M * 2];
  long long dis[N];
  queue<int> que;
  int n, et, pre[N], vis[N], head[N];
  void init(int _n) {
    n = _n, et = 0;
    memset(head, -1, sizeof(head[0]) * n);
  }
  void addEdge(int s, int t, int cap, int cost) {
    e[et] = Edge(s, t, cap, cost, head[s]), head[s] = et++;
    e[et] = Edge(t, s, 0, -cost, head[t]), head[t] = et++;
  }
  bool bfs(int S, int T) {
    for (int i = (0); i < (n); i++) pre[i] = -1, dis[i] = LINF, vis[i] = false;
    dis[S] = 0, vis[S] = true, que.push(S);
    while (!que.empty()) {
      int u = que.front();
      for (int i = head[u]; ~i; i = e[i].nxt) {
        int v = e[i].t;
        if (e[i].cap > 0 && dis[v] > dis[u] + e[i].cost) {
          pre[v] = i, dis[v] = dis[u] + e[i].cost;
          if (!vis[v]) vis[v] = true, que.push(v);
        }
      }
      vis[u] = false, que.pop();
    }
    return dis[T] != LINF;
  }
  pair<long long, long long> solve(int S, int T) {
    long long maxflow = 0, mincost = 0;
    while (bfs(S, T)) {
      long long flow = INF;
      for (int i = pre[T]; ~i; i = pre[e[i].s])
        flow = min(flow, (long long)e[i].cap);
      for (int i = pre[T]; ~i; i = pre[e[i].s])
        e[i].cap -= flow, e[i ^ 1].cap += flow;
      maxflow += flow, mincost += flow * dis[T];
    }
    return make_pair(maxflow, mincost);
  }
} G;
int data[N];
char s[N];
int main() {
  int n;
  while (scanf("%d%s", &n, s) != EOF) {
    G.init(110);
    for (int i = (0); i < (n); i++) scanf("%d", &data[i]);
    for (int i = (0); i < (n / 2); i++) {
      if (data[i] > data[n - i - 1]) {
        swap(data[i], data[n - i - 1]);
        swap(s[i], s[n - i - 1]);
      }
      G.addEdge(0, i + 1, 1, 0);
      G.addEdge(i + n / 2 + 1, 105, 1, -data[n - i - 1]);
    }
    for (int i = (0); i < (n / 2); i++)
      for (int j = (n / 2); j < (n); j++) {
        if (s[i] != s[j]) {
          G.addEdge(i + 1, j + 1, 1, i + j == n - 1 ? -data[i] : 0);
        }
      }
    cout << -G.solve(0, 105).second << "\n";
  }
}
