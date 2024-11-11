#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int head[MAXN], edge[MAXN << 1], next1[MAXN << 1], from[MAXN], to[MAXN];
int esz, dfs_clock, flag, n;
int ans[MAXN];
vector<int> q[MAXN];
void addedge(int u, int v) {
  edge[esz] = v;
  next1[esz] = head[u];
  head[u] = esz++;
}
void dfs(int u, int p) {
  from[u] = ++dfs_clock;
  for (int i = head[u]; i + 1; i = next1[i]) {
    int v = edge[i];
    if (v == p) continue;
    dfs(v, u);
  }
  to[u] = dfs_clock;
}
int sum[MAXN << 2];
int coun[MAXN << 2];
void pushup(int o, int len) {
  if (coun[o] > 0)
    sum[o] = len;
  else
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
void update(int l, int r, int o, int L, int R, int v) {
  if (L <= l && r <= R) {
    coun[o] += v;
    if (coun[o] > 0)
      sum[o] = r - l + 1;
    else {
      if (l == r)
        sum[o] = 0;
      else
        sum[o] = sum[o << 1] + sum[o << 1 | 1];
    }
    return;
  }
  int m = l + r >> 1;
  if (L <= m) update(l, m, o << 1, L, R, v);
  if (m < R) update(m + 1, r, o << 1 | 1, L, R, v);
  pushup(o, r - l + 1);
}
void solve(int u, int p) {
  int L = q[u].size();
  if (L > 0 && !flag) {
    flag = u;
  }
  for (int i = 0; i < L; i++) {
    int v = q[u][i];
    if (to[v] < from[flag] || from[v] > to[flag]) {
      update(1, n, 1, from[v], to[v], 1);
    }
  }
  if (flag) {
    ans[u] = to[flag] - from[flag] + sum[1];
  }
  for (int i = head[u]; i + 1; i = next1[i]) {
    int v = edge[i];
    if (v == p) continue;
    solve(v, u);
  }
  for (int i = 0; i < L; i++) {
    int v = q[u][i];
    if (to[v] < from[flag] || from[v] > to[flag]) {
      update(1, n, 1, from[v], to[v], -1);
    }
  }
  if (flag == u) {
    flag = 0;
  }
}
int main() {
  memset(head, -1, sizeof(head));
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    q[u].push_back(v);
    q[v].push_back(u);
  }
  dfs(1, 0);
  solve(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
