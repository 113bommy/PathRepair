#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200020];
int p[200020], q[200020];
int mn[200020 << 1][20];
int tot = 0;
int pos[200020];
void dfs(int u) {
  pos[u] = tot, mn[tot++][0] = u;
  for (int v : g[u]) {
    dfs(v);
    mn[tot++][0] = u;
  }
}
void build(int *a, int n) {
  for (int i = 1; i <= n; i++) mn[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    }
  }
}
int lca(int u, int v) {
  u = pos[u], v = pos[v];
  if (u > v) swap(u, v);
  int d = 31 - __builtin_clz(v - u + 1);
  return min(mn[u][d], mn[v - (1 << d) + 1][d]);
}
int ed[200020][2];
void merge(int *l, int *r, int *tar) {
  if (l[0] < 0 || r[0] < 0) {
    tar[0] = -1;
    return;
  }
  vector<int> v;
  for (int i = 0; i < 2; i++) v.push_back(l[i]), v.push_back(r[i]);
  int rt = lca(v[0], v[1]);
  for (int i = 2; i < 4; i++) rt = lca(rt, v[i]);
  for (int i = v.size() - 1; i >= 0; i--) {
    for (int j = 0; j < v.size(); j++) {
      if (j == i) continue;
      if (lca(v[i], v[j]) == v[i]) {
        v.erase(v.begin() + i);
        break;
      }
    }
  }
  if (v.size() > 2) {
    tar[0] = -1;
  } else if (v.size() == 2 && rt != lca(v[0], v[1])) {
    tar[0] = -1;
  } else {
    for (int i = 0; i < v.size(); i++) tar[i] = v[i];
    if (v.size() == 1) tar[1] = rt;
  }
}
void push_up(int id) { merge(ed[id << 1], ed[id << 1 | 1], ed[id]); }
void build(int l, int r, int id) {
  if (l == r) {
    ed[id][0] = ed[id][1] = q[l];
    return;
  }
  int m = l + r >> 1;
  build(l, m, id << 1);
  build(m + 1, r, id << 1 | 1);
  push_up(id);
}
void update(int l, int r, int id, int p, int x) {
  if (l == r) {
    ed[id][0] = ed[id][1] = x;
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    update(l, m, id << 1, p, x);
  else
    update(m + 1, r, id << 1 | 1, p, x);
  push_up(id);
}
int cur[2];
int query(int l, int r, int id) {
  if (l == r) return l;
  int m = l + r >> 1;
  int tmp[2];
  if (l > 1)
    merge(cur, ed[id << 1], tmp);
  else {
    for (int i = 0; i < 2; i++) tmp[i] = ed[id << 1][i];
  }
  if (tmp[0] == -1)
    return query(l, m, id << 1);
  else {
    for (int i = 0; i < 2; i++) cur[i] = tmp[i];
    return query(m + 1, r, id << 1 | 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]), q[p[i]] = i;
  for (int i = 1; i < n; i++) {
    int d;
    scanf("%d", &d);
    d--;
    g[d].push_back(i);
  }
  dfs(0);
  for (int j = 1; (1 << j) <= tot; j++) {
    for (int i = 0; i + (1 << j) - 1 < tot; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    }
  }
  build(0, n - 1, 1);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int i, j;
      scanf("%d%d", &i, &j);
      i--, j--;
      update(0, n - 1, 1, p[i], q[p[j]]);
      update(0, n - 1, 1, p[j], q[p[i]]);
      swap(p[i], p[j]);
      swap(q[p[i]], q[p[j]]);
    } else {
      if (ed[1][0] >= 0)
        printf("%d\n", n);
      else
        printf("%d\n", query(0, n - 1, 1));
    }
  }
}
