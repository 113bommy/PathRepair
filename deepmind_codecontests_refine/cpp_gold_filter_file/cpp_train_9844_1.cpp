#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 3010;
const int MAXM = 3010 * 8;
int N;
int A[MAXN];
struct edge {
  int v, next, cost, cp;
};
struct MCMF {
  edge e[MAXM];
  int sou, sin;
  int first[MAXN], ecnt;
  int dis[MAXN];
  int prev[MAXN], pree[MAXN], inq[MAXN];
  void init(int a, int b) {
    sou = a;
    sin = b;
    memset(first, -1, sizeof(first));
    ecnt = 0;
  }
  void add_edge(int u, int v, int cap, int fee) {
    e[ecnt].next = first[u];
    e[ecnt].v = v;
    e[ecnt].cp = cap;
    e[ecnt].cost = fee;
    first[u] = ecnt++;
    e[ecnt].next = first[v];
    e[ecnt].v = u;
    e[ecnt].cp = 0;
    e[ecnt].cost = -fee;
    first[v] = ecnt++;
  }
  bool Spfa() {
    fill(dis, dis + MAXN, INF);
    dis[sou] = 0;
    memset(prev, -1, sizeof(prev)), memset(inq, 0, sizeof(inq));
    queue<int> Q;
    Q.push(sou);
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      inq[x] = 0;
      for (int i = first[x]; ~i; i = e[i].next) {
        if (e[i].cp <= 0) continue;
        int v = e[i].v;
        if (dis[x] + e[i].cost < dis[v]) {
          dis[v] = dis[x] + e[i].cost;
          prev[v] = x;
          pree[v] = i;
          if (inq[v] == 0) {
            inq[v] = 1;
            Q.push(v);
          }
        }
      }
    }
    return prev[sin] != -1;
  }
  long long Solve() {
    long long min_cost = 0;
    while (Spfa()) {
      int minf = INF;
      for (int i = sin; i != sou; i = prev[i]) {
        int id = pree[i];
        minf = min(minf, e[id].cp);
      }
      for (int i = sin; i != sou; i = prev[i]) {
        int id = pree[i];
        e[id].cp -= minf;
        e[id ^ 1].cp += minf;
      }
      min_cost += 1ll * dis[sin] * minf;
    }
    return min_cost;
  }
} MF;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  MF.init(0, N + 2);
  MF.add_edge(0, 1, INF, 0);
  MF.add_edge(0, N + 1, INF, 0);
  MF.add_edge(1, 2, INF, 1);
  MF.add_edge(N + 1, N, INF, 1);
  for (int i = 2; i <= N; ++i) {
    int v = A[i] - A[i - 1];
    if (v > 0) {
      MF.add_edge(0, i, v, 0);
      MF.add_edge(i, N + 2, 1, 0);
    } else {
      MF.add_edge(i, N + 2, -v + 1, 0);
    }
    if (i > 2) {
      MF.add_edge(i, i - 1, INF, 1);
    }
    if (i < N) {
      MF.add_edge(i, i + 1, INF, 1);
    }
  }
  long long ans = MF.Solve();
  printf("%I64d\n", ans);
  return 0;
}
