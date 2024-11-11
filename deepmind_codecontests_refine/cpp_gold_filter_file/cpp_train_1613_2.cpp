#include <bits/stdc++.h>
const int N = 3333;
const int M = N * 2;
struct Edge {
  int from, to;
} edges[M];
int head[N], next[M], sz;
void init_graph() {
  memset(head, -1, sizeof head);
  sz = 0;
}
void add_edge(int from, int to) {
  Edge e = (Edge){from, to};
  edges[sz] = e;
  next[sz] = head[from];
  head[from] = sz++;
}
int n, m, u, v, s1, t1, l1, s2, t2, l2;
int d[N][N];
void bfs(int s) {
  for (int i = 1; i <= n; ++i) {
    d[s][i] = N;
  }
  d[s][s] = 0;
  std::queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = next[i])
      if (d[s][edges[i].to] == N) {
        d[s][edges[i].to] = d[s][u] + 1;
        q.push(edges[i].to);
      }
  }
}
void f(int &ans) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int x = d[s1][i] + d[i][j] + d[j][t1];
      int y = d[s2][i] + d[j][t2] + d[i][j];
      if (x <= l1 && y <= l2) ans = std::max(ans, m - x - y + d[i][j]);
    }
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    init_graph();
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    for (int i = 1; i <= n; ++i) bfs(i);
    int ans = m - d[s1][t1] - d[s2][t2];
    f(ans);
    std::swap(s1, t1);
    f(ans);
    if (d[t1][s1] > l1 || d[s2][t2] > l2) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
