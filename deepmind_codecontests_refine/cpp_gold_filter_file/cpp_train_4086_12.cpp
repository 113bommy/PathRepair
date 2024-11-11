#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 2e5 + 5;
int head[maxn], nume;
struct edge {
  int v, w, c, next;
} e[maxm];
inline void init_edge() {
  memset(head, -1, sizeof head);
  nume = 0;
}
inline void add_edge(int u, int v, int w = 0, int c = 0) {
  e[nume].v = v;
  e[nume].w = w;
  e[nume].c = c;
  e[nume].next = head[u];
  head[u] = nume++;
}
int vis[maxn], d[maxn], a[maxn << 3], b[maxn << 3], tot;
void add(int u, int t) {
  if (a[tot] == u && b[tot] == t) return;
  tot++;
  a[tot] = u, b[tot] = t;
}
void dfs(int u, int T) {
  vis[u] = 1;
  add(u, T);
  if (T < d[u]) {
    for (int i = head[u], t = T; ~i; i = e[i].next) {
      int v = e[i].v;
      if (vis[v] == 0) {
        dfs(v, t + 1);
        t = t + 1;
        add(u, t);
        if (t == d[u]) {
          t = 0;
          add(u, t);
        }
      }
    }
  } else {
    add(u, T - d[u]);
    for (int i = head[u], t = T - d[u]; ~i; i = e[i].next) {
      int v = e[i].v;
      if (vis[v] == 0) {
        dfs(v, t + 1);
        t = t + 1;
        add(u, t);
      }
    }
  }
  if (T != 0) add(u, T - 1);
}
int n, u, v;
int main() {
  init_edge();
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n1 0");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
    d[u]++, d[v]++;
  }
  dfs(1, 0);
  tot--;
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) printf("%d %d\n", a[i], b[i]);
}
