#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int head[MAXN], E;
struct Edge {
  int v, next;
} edge[MAXN << 2];
bool vis[MAXN];
bool flag;
int in[MAXN];
void add_edge(int u, int v) {
  edge[E].v = v;
  edge[E].next = head[u];
  head[u] = E++;
}
int dfs(int u, int fa) {
  int i, num = 0;
  vis[u] = 1;
  for (i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    num++;
    if (vis[v]) continue;
    return dfs(v, u) + 1;
  }
  if (num % 2 == 0) flag = 1;
  return 1;
}
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  E = 0;
  int x, y;
  while (m--) {
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
    in[x]++;
    in[y]++;
  }
  int num1 = 0, num2 = 0;
  for (i = 1; i <= n; i++) {
    if (!vis[i] && in[i] % 2) {
      flag = 0;
      int num = dfs(i, 0);
      if (flag)
        num1 += num % 2;
      else
        num2 += num % 2;
    }
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      flag = 0;
      int num = dfs(i, 0);
      if (flag)
        num1 += num % 2;
      else
        num2 += num % 2;
    }
  }
  printf("%d\n", num1 + num2 % 2);
  return 0;
}
