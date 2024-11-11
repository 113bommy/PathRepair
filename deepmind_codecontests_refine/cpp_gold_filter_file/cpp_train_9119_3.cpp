#include <bits/stdc++.h>
const int N = 1003;
struct E {
  int v, next;
} e[N * N];
int n, head[N], k = 1;
char s[N * 100];
int num[N][N], id[N][N];
bool vis[N];
void ADD(int u, int v) {
  e[k] = (E){v, head[u]};
  head[u] = k++;
}
void dfs(int u, int fa = 0) {
  vis[u] = 1;
  for (int v = 1; v <= n; v++)
    if (u != v && fa != v && num[u][id[u][v]] + num[v][id[v][u]] == n) {
      if (vis[v]) {
        puts("-1");
        exit(0);
      }
      ADD(u, v);
      ADD(v, u);
      dfs(v, u);
    }
}
void DFS(int u, int fa = 0) {
  for (int i = head[u], v = e[i].v; i; i = e[i].next, v = e[i].v)
    if (v != fa) printf("%d %d\n", u, v);
  for (int i = head[u], v = e[i].v; i; i = e[i].next, v = e[i].v)
    if (v != fa) DFS(v, u);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int m = strlen(s + 1), x = 0, p = 0, t = 1;
    for (int j = 1; j <= m; j++)
      if (isdigit(s[j]))
        x = x * 10 + s[j] - '0';
      else
        s[j] == ',' || s[j] == '-' ? num[i][t]++, id[i][x] = t : 1,
                                                  t += (s[j] == '-'), x = 0;
    num[i][t]++, id[i][x] = t;
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      puts("-1");
      return 0;
    }
  for (int u = 1; u <= n; u++) {
    int sum = 1;
    for (int i = head[u], v = e[i].v; i; i = e[i].next, v = e[i].v)
      sum += num[u][id[u][v]];
    if (sum != n) {
      puts("-1");
      return 0;
    }
  }
  for (int u = 1; u <= n; u++)
    for (int i = head[u], v = e[i].v; i; i = e[i].next, v = e[i].v)
      for (int j = head[u], v = e[j].v; j; j = e[j].next, v = e[j].v)
        if (i != j && id[u][e[i].v] == id[u][e[j].v]) {
          puts("-1");
          return 0;
        }
  printf("%d\n", n - 1);
  DFS(1);
  return 0;
}
