#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, nex;
};
struct node {
  int s, w;
  node(int _s, int _w) : s(_s), w(_w) {}
  friend bool operator<(node a, node b) { return a.w > b.w; }
};
int n, cnt;
int a[N], head[N], d[N], res[N];
Edge edge[2 * N];
void init() {
  cnt = 0;
  for (int i = 1; i <= n + 2; i++) head[i] = 0;
}
void add_edge(int u, int v) {
  edge[++cnt].to = v;
  edge[cnt].nex = head[u];
  head[u] = cnt;
}
void dijkstra(int s) {
  priority_queue<node> q;
  for (int i = 1; i <= n + 2; i++) d[i] = INF;
  d[s] = 0;
  q.push(node(s, 0));
  while (!q.empty()) {
    node nd = q.top();
    int u = nd.s, w = nd.w;
    q.pop();
    if (w != d[u]) continue;
    for (int i = head[u]; 0 != i; i = edge[i].nex) {
      int v = edge[i].to;
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        q.push(node(v, d[v]));
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (0 == a[i] % 2)
      add_edge(n + 1, i);
    else
      add_edge(n + 2, i);
    if (i + a[i] <= n) add_edge(i + a[i], i);
    if (i - a[i] >= 1) add_edge(i - a[i], i);
  }
  dijkstra(n + 1);
  for (int i = 1; i <= n; i++) {
    if (0 == a[i] % 2) continue;
    res[i] = (INF == d[i] ? -1 : d[i] - 1);
  }
  dijkstra(n + 2);
  for (int i = 1; i <= n; i++) {
    if (1 == a[i] % 2) continue;
    res[i] = (INF == d[i] ? -1 : d[i] - 1);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d", res[i]);
    printf(i == n ? "\n" : " ");
  }
  return 0;
}
