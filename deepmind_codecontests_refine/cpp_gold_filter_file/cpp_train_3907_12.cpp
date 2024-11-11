#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int maxk = 30;
int n, m;
int head[maxn], vis[maxn], cnt;
struct Edge {
  int v;
  int nxt;
  Edge() {}
  Edge(int x, int y) {
    v = x;
    nxt = y;
  }
} e[maxn];
void add(int u, int v) {
  e[cnt] = Edge(v, head[u]);
  head[u] = cnt++;
}
long long par[maxk][maxn];
long long d[maxn];
long long up[maxn];
long long down[maxn];
long long num[maxn];
long long sum_up[maxn];
long long sum_num[maxn];
pair<long long, long long> dfs(int u, int p, int de) {
  long long a = 0;
  int b = 0;
  par[0][u] = p;
  d[u] = de;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].v;
    pair<long long, long long> t;
    if (v != p) {
      t = dfs(v, u, de + 1);
      up[i] = t.first, num[i] = t.second;
      a += t.first, b += t.second;
    }
  }
  a += b;
  b += 1;
  sum_up[u] = a, sum_num[u] = b;
  return make_pair(a, b);
}
void dfs_down(int u, int p, int de) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].v;
    if (v != p) {
      down[v] = sum_up[u] - sum_up[v] - sum_num[v] + n - sum_num[v];
      down[v] += down[u];
      dfs_down(v, u, de + 1);
    }
  }
}
void ini() {
  dfs(1, -1, 0);
  dfs_down(1, -1, 0);
  for (int k = 0; k < int(maxk - 1); k++) {
    for (int u = 1; u < int(n + 1); u++) {
      if (par[k][u] < 0)
        par[k + 1][u] = -1;
      else
        par[k + 1][u] = par[k][par[k][u]];
    }
  }
}
int lca(int u, int v) {
  if (d[u] > d[v]) swap(u, v);
  for (int k = 0; k < int(maxk); k++) {
    if ((d[v] - d[u]) >> k & 1) {
      v = par[k][v];
    }
  }
  if (u == v) return u;
  for (int k = maxk - 1; k >= int(0); k--) {
    if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
  }
  return par[0][u];
}
int find(int v, int de) {
  for (int k = maxk - 1; k >= int(0); k--) {
    if (de < (1 << k)) continue;
    v = par[k][v];
    de -= (1 << k);
  }
  return v;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < int(n - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  ini();
  for (int i = 0; i < int(m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int rt = lca(u, v);
    double res = 0;
    if (v == rt) swap(u, v);
    if (u == rt) {
      int t = find(v, d[v] - d[u] - 1);
      res = 1.0 * down[t] / (n - sum_num[t]) + 1.0 * sum_up[v] / sum_num[v];
      res += d[v] - d[t] + 1;
    } else {
      res = 1.0 * sum_up[u] / sum_num[u] + 1.0 * sum_up[v] / sum_num[v];
      res += d[u] + d[v] - 2 * d[rt] + 1;
    }
    printf("%.12lf\n", res);
  }
  return 0;
}
