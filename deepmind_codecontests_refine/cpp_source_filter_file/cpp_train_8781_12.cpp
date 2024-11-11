#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Edge {
  int from, to, val;
  int next, cost;
  Edge() {}
  Edge(int a, int b, int c, int d, int e) {
    from = a;
    to = b;
    val = c;
    cost = d;
    next = e;
  }
} edge[200001];
int tot, head[N], re_flow;
void init() {
  memset(head, -1, sizeof(head));
  tot = 0;
}
void addEdge(int u, int v, int cap, int cost) {
  edge[tot] = Edge(u, v, cap, cost, head[u]);
  head[u] = tot++;
  edge[tot] = Edge(v, u, 0, -cost, head[v]);
  head[v] = tot++;
}
struct MinCostFlow {
  int visit[200001], pre[200001], dist[200001], que[200001], pos[200001];
  int SPFA(int s, int t, int n) {
    int i, to, k;
    for (i = 0; i <= n; i++) {
      pre[i] = -1, visit[i] = 0;
    }
    int front, rear;
    front = rear = 0;
    for (i = 0; i <= n; i++) dist[i] = 0xffffff;
    que[rear++] = s, pre[s] = s, dist[s] = 0, visit[s] = 1;
    while (front != rear) {
      int from = que[front++];
      visit[from] = 0;
      for (k = head[from]; k != -1; k = edge[k].next) {
        to = edge[k].to;
        if (edge[k].val > 0 && dist[from] + edge[k].cost < dist[to]) {
          dist[to] = dist[from] + edge[k].cost;
          pre[to] = from;
          pos[to] = k;
          if (!visit[to]) {
            visit[to] = 1;
            que[rear++] = to;
          }
        }
      }
    }
    if (pre[t] != -1 && dist[t] < 0xffffff) return 1;
    return 0;
  }
  int solve(int s, int t, int n) {
    memset(visit, 0, sizeof(visit));
    memset(pos, 0, sizeof(pos));
    memset(pre, 0, sizeof(pre));
    int flow = 0, cost = 0;
    while (SPFA(s, t, n)) {
      int from, min = 0xffffff;
      for (from = t; from != s; from = pre[from])
        min = min < edge[pos[from]].val ? min : edge[pos[from]].val;
      flow += min;
      cost += dist[t] * min;
      for (from = t; from != s; from = pre[from]) {
        edge[pos[from]].val -= min;
        edge[pos[from] ^ 1].val += min;
      }
    }
    if (flow != re_flow) return -1;
    return cost;
  }
} flow;
int input() {
  int n, st, ed, len, limit[N], cnt[30] = {0};
  char str_t[N], str[N][N];
  scanf("%s %d", str_t, &n);
  st = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", str[i], &limit[i]);
    addEdge(st, i, limit[i], 0);
    len = (int)strlen(str[i]);
    for (int j = 0; j < len; j++) {
      addEdge(i, n + str[i][j] - 'a' + 1, 1, i);
    }
  }
  re_flow = len = (int)strlen(str_t);
  for (int i = 0; i < len; i++) {
    cnt[str_t[i] - 'a']++;
  }
  ed = n + 31;
  for (int i = 0; i < 30; i++) {
    if (cnt[i]) addEdge(n + i + 1, ed, cnt[i], 0);
  }
  return ed;
}
int main() {
  init();
  int st = 0;
  int ed = input();
  printf("%d\n", flow.solve(st, ed, ed - st + 1));
  return 0;
}
