#include <bits/stdc++.h>
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar()) {
    if (c == '-') {
      f = -1;
    }
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
  return x * f;
}
struct Edge {
  int to, next;
} edge[1000005];
bool flag[2][200005];
int head[200005], cnte, tot1, tot2;
inline void insert(int u, int v) {
  edge[++cnte] = (Edge){v, head[u]}, head[u] = cnte;
  edge[++cnte] = (Edge){u, head[v]}, head[v] = cnte;
}
void dfs(int now, int kind) {
  flag[kind][now] = 1;
  for (int i = head[now]; i; i = edge[i].next) {
    if (!flag[kind][edge[i].to]) dfs(edge[i].to, kind);
  }
}
inline void work() {
  for (int t = read(); t; t--) {
    int n = read(), m = read(), a = read(), b = read();
    memset(head, 0, (n + 1) * sizeof(int));
    memset(flag[0], 0, (n + 1) * sizeof(bool));
    memset(flag[1], 0, (n + 1) * sizeof(bool));
    cnte = 0, tot1 = 0, tot2 = 0;
    for (int i = 1; i <= m; i++) {
      int x = read(), y = read();
      insert(x, y);
    }
    flag[0][a] = 1;
    dfs(b, 0);
    flag[1][b] = 1;
    dfs(a, 1);
    for (int i = 1; i <= n; i++) {
      if (!flag[0][i]) tot1++;
      if (!flag[1][i]) tot2++;
    }
    printf("%I64d\n", 1ll * tot1 * tot2);
  }
}
int main() {
  work();
  return 0;
}
