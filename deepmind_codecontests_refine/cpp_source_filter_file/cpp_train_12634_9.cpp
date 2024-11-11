#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v, next;
} edge[200009];
int head[100009], tot, n, m;
inline void addedge(int u, int v) {
  edge[tot].v = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void dfs(int u, int fa) {
  int v;
  for (int e = head[u]; e != -1; e = edge[e].next) {
    v = edge[e].v;
    if ((e ^ 1) == fa) continue;
    if (fa != -1) {
      printf("%d %d\n", fa + 1, e / 2 + 1);
    }
    dfs(v, e);
  }
}
int main() {
  scanf("%d", &n);
  int x, y;
  printf("%d\n", n - 1);
  memset(head, -1, sizeof(head));
  tot = 0;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
    printf("2 %d %d\n", x, y);
  }
  dfs(1, -1);
  int root = head[1];
  for (int e = head[1]; e != -1; e = edge[e].next) {
    if (e == root) continue;
    printf("%d %d\n", e / 2 + 1, root / 2 + 1);
  }
  return 0;
}
