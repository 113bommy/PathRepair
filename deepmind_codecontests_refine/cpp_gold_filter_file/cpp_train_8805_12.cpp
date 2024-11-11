#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 80 + 5;
const int MAX_V = 200 + 5;
const int MAX_E = 10000 + 5;
const int INF32 = 1e9;
const long long INF64 = 1e18;
int N, K;
int qa[MAX_N], qc[MAX_N];
int S, T, E, Flow;
int elast[MAX_V], pre[MAX_V];
bool inq[MAX_V];
long long Cost, dis[MAX_V];
struct Edge {
  int y, cap, next;
  long long cost;
} e[MAX_E];
inline void add_edge(int x, int y, int cap, long long cost) {
  e[E].y = y;
  e[E].cap = cap;
  e[E].cost = cost;
  e[E].next = elast[x];
  elast[x] = E++;
  e[E].y = x;
  e[E].cap = 0;
  e[E].cost = -cost;
  e[E].next = elast[y];
  elast[y] = E++;
}
bool spfa() {
  for (int i = 1; i <= T; i++) {
    dis[i] = INF64;
  }
  dis[S] = 0;
  queue<int> q;
  q.push(S);
  inq[S] = true;
  while (q.size()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int j = elast[u]; j; j = e[j].next) {
      int v = e[j].y;
      if (e[j].cap > 0 && dis[v] > dis[u] + e[j].cost) {
        dis[v] = dis[u] + e[j].cost;
        pre[v] = j;
        if (!inq[v]) {
          inq[v] = true;
          q.push(v);
        }
      }
    }
  }
  if (dis[T] > 0) {
    return false;
  }
  int f = K - Flow;
  for (int u = T; u != S; u = e[pre[u] ^ 1].y) {
    f = min(f, e[pre[u]].cap);
  }
  Flow += f;
  Cost += f * dis[T];
  for (int u = T; u != S; u = e[pre[u] ^ 1].y) {
    e[pre[u] ^ 1].cap += f;
    e[pre[u]].cap -= f;
  }
  return Flow < K;
}
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &qa[i]);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", &qc[i]);
  }
  S = N + N + 1;
  T = S + 1;
  E = 2;
  for (int i = 1; i <= N; i++) {
    add_edge(S, i, 1, qc[qa[i]]);
    add_edge(i, i + N, 1, -INF32);
    add_edge(i + N, T, 1, 0);
  }
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      add_edge(i + N, j, 1, qa[i] == qa[j] ? 0 : qc[qa[j]]);
    }
  }
  Flow = Cost = 0;
  while (spfa())
    ;
  printf("%lld\n", Cost + 1ll * INF32 * N);
  return 0;
}
