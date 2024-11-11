#include <bits/stdc++.h>
using namespace std;
int n;
struct edge {
  int to, next;
  int w;
} e[2005];
int cnt;
int head[1005];
void ins(int u, int v, int w) {
  cnt++;
  e[cnt].to = v;
  e[cnt].next = head[u];
  e[cnt].w = w;
  head[u] = cnt;
}
int deg[1005];
int fs[1005], ss[1005];
int es[1005];
int root;
void build(int u, int fa, int acc) {
  bool sign = 0;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    if (!sign) {
      e[i].w -= acc;
      if (u == root)
        build(v, u, acc);
      else
        build(v, u, acc + e[i].w);
      sign = 1;
      es[u] = es[v];
      fs[u] = v;
    } else {
      build(v, u, e[i].w);
      ss[u] = v;
    }
  }
  if (deg[u] == 1 && u != root) es[u] = u;
}
int m;
int s1[100005];
int s2[100005];
int s3[100005];
void opt(int a, int b, int c, int w) {
  m++;
  s1[m] = a, s2[m] = b, s3[m] = w / 2;
  m++;
  s1[m] = a, s2[m] = c, s3[m] = w / 2;
  m++;
  s1[m] = b, s2[m] = c, s3[m] = -w / 2;
}
void dfs(int u, int fa) {
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    if (u != root) {
      if (v == fs[u])
        opt(es[v], root, es[ss[u]], e[i].w);
      else
        opt(es[v], root, es[u], e[i].w);
    }
    dfs(v, u);
  }
  if (u == root) {
    int v = e[head[u]].to;
    opt(root, es[fs[v]], es[ss[v]], e[head[u]].w);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    ins(u, v, w);
    ins(v, u, w);
    deg[u]++;
    deg[v]++;
  }
  if (n == 2) {
    printf("YES\n1\n%d %d %d", 1, 2, e[1].w);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 2) {
      printf("NO");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) {
      root = i;
      build(root, 0, 0);
      dfs(root, 0);
      break;
    }
  }
  printf("%d\n", m);
  for (int i = 1; i <= m; i++) printf("%d %d %d\n", s1[i], s2[i], s3[i]);
  return 0;
}
