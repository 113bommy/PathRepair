#include <bits/stdc++.h>
const int maxn = 100005;
struct Edge {
  int v, next;
} edge[2][maxn];
int tot[2];
int f[maxn];
int q[maxn];
int head[2][maxn];
int mk[2][maxn];
void add_edge(int idx, int u, int v) {
  edge[idx][tot[idx]].v = v;
  edge[idx][tot[idx]].next = head[idx][u];
  head[idx][u] = tot[idx]++;
}
void bfs(int idx, int s) {
  int i, l = 0, r = 0;
  int u, v;
  q[r++] = s;
  mk[idx][s] = true;
  while (l < r) {
    u = q[l++];
    for (i = head[idx][u]; i != -1; i = edge[idx][i].next) {
      v = edge[idx][i].v;
      if (!mk[idx][v] && !(idx == 0 && f[v] == 1)) {
        mk[idx][v] = true;
        if (f[v] == 0) {
          q[r++] = v;
        }
      }
    }
  }
}
int main() {
  int n, m, i;
  int u, v;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
  }
  tot[0] = tot[1] = 0;
  memset(head, -1, sizeof(head));
  for (i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    add_edge(0, u, v);
    add_edge(1, v, u);
  }
  for (i = 1; i <= n; i++)
    if (f[i] == 1) {
      bfs(0, i);
    }
  for (i = 1; i <= n; i++)
    if (f[i] == 2 && !mk[1][i]) {
      bfs(1, i);
    }
  for (i = 1; i <= n; i++) {
    if (mk[0][i] && mk[1][i])
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}
