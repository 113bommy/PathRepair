#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = MAXN << 2;
struct Edge {
  int to, next;
  long long w;
} edge[MAXM << 1];
int tot, head[MAXN];
void init() { tot = 0, memset(head, -1, sizeof(head)); }
void addedge(int u, int v, long long w) {
  edge[tot].to = v;
  edge[tot].next = head[u];
  edge[tot].w = w;
  head[u] = tot++;
}
int vis[MAXN], n, m, u, v, circle;
long long d[MAXN], a[MAXM], w, bit[100];
void dfs(int u) {
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (!vis[v])
      d[v] = d[u] ^ edge[i].w, dfs(v);
    else
      a[circle++] = d[u] ^ d[v] ^ edge[i].w;
  }
}
void gauss() {
  int i, j, row = 0;
  for (i = 63; i >= 0; i--) {
    for (j = row; j < circle; j++)
      if (a[j] & bit[i]) break;
    if (j != circle) {
      swap(a[j], a[row]);
      for (j = 0; j < circle; j++) {
        if (j == row) continue;
        if (a[j] & bit[i]) a[j] ^= a[row];
      }
      row++;
    }
  }
  long long ans = d[n];
  for (int i = 63; i >= 0; i--)
    if ((ans ^ a[i]) < ans) ans ^= a[i];
  printf("%i64d\n", ans);
}
int main() {
  bit[0] = 1;
  for (int i = 1; i < 64; i++) bit[i] = bit[i - 1] << 1;
  init();
  circle = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%i64d", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  dfs(1);
  gauss();
  return 0;
}
