#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
vector<int> G[100005];
int f[100005], dep[100005], siz[100005], son[100005];
int dfn[100005], top[100005], id[100005];
int tree[100005 << 2], lazy[100005 << 2];
void dfs1(int u, int fa) {
  f[u] = fa, dep[u] = dep[fa] + 1, siz[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int t) {
  top[u] = t, id[u] = ++cnt;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == f[u] || son[u] == v) continue;
    dfs2(v, v);
  }
}
void modify(int num, int l, int r, int pos, int val) {
  if (l == r) {
    tree[num] = val;
    return;
  }
  int mid = (l + r) >> 1, ans = 0;
  if (pos <= mid)
    modify(num << 1, l, mid, pos, val);
  else
    modify(num << 1 | 1, mid + 1, r, pos, val);
  tree[num] = tree[num << 1] + tree[num << 1 | 1];
}
int query(int num, int l, int r, int L, int R) {
  if (r < L || R < l) return 0;
  if (L <= l && r <= R) return tree[num];
  int mid = (l + r) >> 1;
  return query(num << 1, l, mid, L, R) + query(num << 1 | 1, mid + 1, r, L, R);
}
int solve(int x, int y) {
  int fx = top[x], fy = top[y], ans = 0, now;
  while (fx ^ fy) {
    if (dep[fx] >= dep[fy]) {
      now = query(1, 1, n, id[fx], id[x]);
      if (now) return -1;
      ans += id[x] - id[fx] + 1;
      x = f[fx], fx = top[x];
    } else {
      now = query(1, 1, n, id[fy], id[y]);
      if (now) return -1;
      ans += id[y] - id[fy] + 1;
      y = f[fy], fy = top[y];
    }
  }
  if (id[x] <= id[y]) {
    now = query(1, 1, n, id[x] + 1, id[y]);
    if (now) return -1;
    ans += id[y] - id[x];
  } else {
    now = query(1, 1, n, id[y] + 1, id[x]);
    if (now) return -1;
    ans += id[x] - id[y];
  }
  return ans;
}
int u[100005], v[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u[i], &v[i]);
    G[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  scanf("%d", &m);
  for (int i = 1, opt, x, y; i <= m; i++) {
    scanf("%d %d", &opt, &x);
    switch (opt) {
      case 1: {
        if (dep[u[x]] > dep[v[x]])
          modify(1, 1, n, id[u[x]], 0);
        else
          modify(1, 1, n, id[v[x]], 0);
        break;
      }
      case 2: {
        if (dep[u[x]] > dep[v[x]])
          modify(1, 1, n, id[u[x]], 1);
        else
          modify(1, 1, n, id[v[x]], 1);
        break;
      }
      case 3: {
        scanf("%d", &y);
        printf("%d\n", solve(x, y));
        break;
      }
    }
  }
  return 0;
}
