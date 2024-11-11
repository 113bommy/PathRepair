#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:10240000000,10240000000")
struct edge {
  int v, w, next;
} e[5005];
int ecnt, pre[5005], vis[5005];
void init() {
  memset(pre, -1, sizeof(pre));
  memset(vis, 0, sizeof(vis));
  ecnt = 0;
}
void add(int u, int v, int w) {
  e[ecnt].v = v;
  e[ecnt].w = w;
  e[ecnt].next = pre[u];
  pre[u] = ecnt++;
}
int tot, st;
void dfs(int u, int fa) {
  vis[u] = 1;
  for (int i = pre[u]; ~i; i = e[i].next) {
    int v = e[i].v;
    if (!vis[v] || v == fa && fa != v) dfs(v, u), tot += e[i].w;
  }
}
int main() {
  tot = 0;
  int n;
  init();
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
    add(y, x, 0);
    sum += z;
  }
  st = 1;
  dfs(1, -1);
  printf("%d\n", min(sum - tot, tot));
}
