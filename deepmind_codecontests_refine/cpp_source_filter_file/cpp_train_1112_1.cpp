#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 10;
const int M = (int)2e6 + 10;
int n, m;
int cnt, lst[N], nxt[M], to[M];
void add(int u, int v) {
  nxt[++cnt] = lst[u];
  lst[u] = cnt;
  to[cnt] = v;
  nxt[++cnt] = lst[v];
  lst[v] = cnt;
  to[cnt] = u;
}
bool vis[N];
int cid[N], fa[N];
vector<int> cir[N];
int f[N], f0[N], f1[N], g[N];
int rk[N][2];
void dfs(int u, int pre) {
  vis[u] = 1;
  fa[u] = pre;
  for (int j = lst[u]; j; j = nxt[j]) {
    int v = to[j];
    if (v == pre) continue;
    if (vis[v]) {
      if (cid[u]) continue;
      ++m;
      for (int p = u; p != v; p = fa[p]) {
        cir[m].push_back(p);
        cid[p] = m;
      }
      cir[m].push_back(v);
      cid[v] = m;
      continue;
    }
    dfs(v, u);
  }
  if (!cid[u]) {
    cid[u] = ++m;
    cir[m].push_back(u);
  }
}
void dpf(int u) {
  vis[u] = 1;
  for (int j = lst[u]; j; j = nxt[j]) {
    int v = to[j];
    if (vis[v]) continue;
    dpf(v);
    if (cid[v] != cid[u]) {
      f0[u] = max(f[u], f[v] + 1);
      if (!rk[u][0] || f[rk[u][0]] <= f[v])
        rk[u][1] = rk[u][0], rk[u][0] = v;
      else if (!rk[u][1] || f[rk[u][1]] <= f[v])
        rk[u][1] = v;
    }
  }
  int p = cid[u], m = cir[p].size();
  if (u == cir[p][m - 1]) {
    for (int i = 0; i < m; i++) {
      int v = cir[p][i];
      f1[u] = max(f1[u], f[v] + min(i + 1, m - 1 - i));
    }
  }
  f[u] = max(f0[u], f1[u]);
}
int q[N][2], head, tail;
void dpg(int u) {
  vis[u] = 1;
  int pre = fa[u];
  if (pre && cid[pre] != cid[u]) {
    g[u] = max(g[u], g[pre] + 1);
    g[u] = max(g[u], f1[pre] + 1);
    if (u == rk[pre][0]) {
      if (rk[pre][1]) g[u] = max(g[u], f[rk[pre][1]] + 2);
    } else
      g[u] = max(g[u], f0[pre] + 1);
  }
  f0[u] = max(f0[u], g[u]);
  int p = cid[u], m = cir[p].size();
  if (u == cir[p][m - 1]) {
    head = tail = 1;
    q[head][0] = f0[cir[p][0]], q[head][1] = 0;
    for (int i = 1; i <= m / 2; i++) {
      while (head <= tail && q[tail][0] <= f0[cir[p][i]] + i) tail--;
      ++tail;
      q[tail][0] = f0[cir[p][i]] + i, q[tail][1] = i;
    }
    for (int i = 0; i < m - 1; i++) {
      if (q[head][1] == i) head++;
      g[cir[p][i]] = max(g[cir[p][i]], q[head][0] - i);
      int next = m / 2 + i + 1;
      while (head <= tail && q[tail][0] <= f0[cir[p][next % m]] + next) tail--;
      ++tail;
      q[tail][0] = f0[cir[p][next % m]] + next, q[tail][1] = next;
    }
    head = tail = 1;
    q[head][0] = f0[cir[p][m / 2]], q[head][1] = m / 2;
    for (int i = m / 2 + 1; i < m; i++) {
      while (head <= tail && q[tail][0] <= f0[cir[p][i]] + m - i) tail--;
      ++tail;
      q[tail][0] = f0[cir[p][i]] + m - i, q[tail][1] = i;
    }
    for (int i = 0; i < m - 1; i++) {
      if (q[head][1] == m / 2 + i) head++;
      g[cir[p][i]] = max(g[cir[p][i]], q[head][0] + i);
      int next = m + i;
      while (head <= tail && q[tail][0] <= f0[cir[p][next % m]] + m - next)
        tail--;
      ++tail;
      q[tail][0] = f0[cir[p][next % m]] + m - next, q[tail][1] = next;
    }
  }
  for (int j = lst[u]; j; j = nxt[j]) {
    int v = to[j];
    if (vis[v]) continue;
    dpg(v);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d %d", &u, &v);
    add(u, v);
  }
  m = 0;
  dfs(1, 0);
  memset(vis, 0, sizeof(vis));
  dpf(1);
  memset(vis, 0, sizeof(vis));
  dpg(1);
  for (int i = 1; i <= n; i++) printf("%d ", max(f[i], g[i]));
  return 0;
}
