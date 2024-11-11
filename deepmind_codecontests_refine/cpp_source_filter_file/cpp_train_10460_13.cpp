#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, next;
};
edge e[100005 << 1];
int p[100005][20], d[100005];
int head[100005], sz;
int siz[100005];
void addedge(int u, int v) {
  e[sz].to = v;
  e[sz].next = head[u];
  head[u] = sz++;
}
void init() {
  memset(head, -1, sizeof(head));
  sz = 0;
}
void build(int u, int fa) {
  p[u][0] = fa;
  d[u] = d[fa] + 1;
  siz[u] = 1;
  for (int i = 1; i < 20; i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    build(v, u);
    siz[u] += siz[v];
  }
}
int find(int a, int k) {
  for (int i = 0; k; i++, k >>= 1) {
    if (k & 1) a = p[a][i];
  }
  return a;
}
int lca(int a, int b) {
  if (d[a] > d[b]) swap(a, b);
  b = find(b, d[b] - d[a]);
  if (a != b) {
    for (int j = 20 - 1; j >= 0; j--) {
      if (p[a][j] != p[b][j]) {
        a = p[a][j], b = p[b][j];
      }
    }
    a = p[a][0], b = p[b][0];
  }
  return a;
}
int query(int x, int y, int n) {
  if (x == y) return 1;
  if (d[x] < d[y]) swap(x, y);
  int fa = lca(x, y);
  int dd = d[x] + d[y] - d[fa] * 2 + 1;
  if (dd % 2 == 0) return 0;
  dd = dd / 2;
  int ans = 0;
  if (d[x] == d[y]) {
    ans = n - siz[find(x, dd - 1)] - siz[find(y, dd - 1)];
  } else {
    ans = siz[find(x, dd)] - siz[find(x, dd - 1)];
  }
  return ans;
}
int main() {
  int n, m, x, y, u, v;
  scanf("%d", &n);
  init();
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  build(1, 0);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    printf("%d\n", query(x, y, n));
  }
  return 0;
}
