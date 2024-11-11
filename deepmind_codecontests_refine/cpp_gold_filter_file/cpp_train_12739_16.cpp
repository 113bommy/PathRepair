#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<int> e[MAXN];
vector<int> p[MAXN];
int n, m;
int res[MAXN];
int step, tl[MAXN], tr[MAXN];
struct node {
  int l, r, flag, s;
} t[MAXN << 3];
void dfs1(int u, int fa) {
  tl[u] = step++;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs1(v, u);
  }
  tr[u] = step - 1;
}
void build(int k, int l, int r) {
  t[k].l = l;
  t[k].r = r;
  t[k].flag = t[k].s = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void modify(int k, int l, int r) {
  if (t[k].l == l && t[k].r == r) {
    t[k].flag--;
    if (t[k].flag == 0) t[k].s = t[k << 1].s + t[k << 1 | 1].s;
    return;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if (r <= mid)
    modify(k << 1, l, r);
  else if (l > mid)
    modify(k << 1 | 1, l, r);
  else {
    modify(k << 1, l, mid);
    modify(k << 1 | 1, mid + 1, r);
  }
  if (t[k].flag == 0) t[k].s = t[k << 1].s + t[k << 1 | 1].s;
}
void insert(int k, int l, int r) {
  if (t[k].l == l && t[k].r == r) {
    t[k].flag++;
    t[k].s = r - l + 1;
    return;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if (r <= mid)
    insert(k << 1, l, r);
  else if (l > mid)
    insert(k << 1 | 1, l, r);
  else {
    insert(k << 1, l, mid);
    insert(k << 1 | 1, mid + 1, r);
  }
  if (t[k].flag == 0) t[k].s = t[k << 1].s + t[k << 1 | 1].s;
}
void dfs2(int u, int fa) {
  if (p[u].size() > 0) insert(1, tl[u], tr[u]);
  for (int i = 0; i < p[u].size(); i++) {
    int v = p[u][i];
    insert(1, tl[v], tr[v]);
  }
  res[u] = t[1].s;
  if (res[u] > 0) res[u]--;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == fa) continue;
    dfs2(v, u);
  }
  if (p[u].size() > 0) modify(1, tl[u], tr[u]);
  for (int i = 0; i < p[u].size(); i++) {
    int v = p[u][i];
    modify(1, tl[v], tr[v]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  step = 0;
  dfs1(0, -1);
  build(1, 0, n - 1);
  dfs2(0, -1);
  for (int i = 0; i < n; i++) printf("%d%c", res[i], (i == n - 1) ? '\n' : ' ');
  return 0;
}
