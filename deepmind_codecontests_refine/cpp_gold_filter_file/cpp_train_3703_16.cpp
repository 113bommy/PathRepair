#include <bits/stdc++.h>
int n, a[200005], b[200005], vis[200005], mark[200005], head[200005], cnt;
struct edge {
  int v, next;
} e[200005 << 1];
void add(int u, int v) {
  e[++cnt] = (edge){v, head[u]};
  head[u] = cnt;
}
void dfs(int u) {
  vis[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (!vis[v]) mark[v] = mark[u] ^ 1, dfs(v);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &a[i], &b[i]), add(a[i], b[i]), add(b[i], a[i]);
  for (int i = 1; i <= n; i++) add(2 * i, 2 * i - 1), add(2 * i - 1, 2 * i);
  for (int i = 1; i <= n << 1; i++)
    if (!vis[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", mark[a[i]] + 1, mark[b[i]] + 1);
}
