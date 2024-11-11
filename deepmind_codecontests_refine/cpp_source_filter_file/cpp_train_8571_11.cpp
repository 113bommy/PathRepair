#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
struct node {
  int v, next, en;
} e[2 * N];
int cf[N];
int ans[N];
bool vis[N];
int tot, a, b, n, u, v, k;
int head[N], deep[N];
int f[N][32];
void add_edge(int u, int v, int en) {
  e[tot].en = en;
  e[tot].v = v;
  e[tot].next = head[u];
  head[u] = tot++;
}
void dfs(int u, int fa) {
  deep[u] = deep[fa] + 1;
  f[u][0] = fa;
  for (int i = 1; (1 << i) <= deep[u]; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (v != fa) dfs(v, u);
  }
}
int LCA(int a, int b) {
  if (deep[a] > deep[b]) swap(a, b);
  for (int i = 31; i >= 0; i--)
    if (deep[a] <= deep[b] - (1 << i)) b = f[b][i];
  if (a == b) return a;
  for (int i = 31; i >= 0; i--) {
    if (f[a][i] == f[b][i])
      continue;
    else
      a = f[a][i], b = f[b][i];
  }
  return f[a][0];
}
void make_cf(int u) {
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (vis[v]) continue;
    make_cf(v);
    cf[u] += cf[v];
    ans[e[i].en / 2 + 1] += cf[v];
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    add_edge(u, v, i);
    add_edge(v, u, i);
  }
  dfs(1, 0);
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &u, &v);
    cf[u]++;
    cf[v]++;
    cf[LCA(u, v)] -= 2;
  }
  memset(vis, false, sizeof(vis));
  memset(ans, 0, sizeof(ans));
  make_cf(1);
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
}
