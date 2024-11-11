#include <bits/stdc++.h>
using namespace std;
int n, m;
int deep[400009], ll[200009], rr[200009], dfsx[400009];
int c[400009], vol[200009];
int tot;
int tag1[800009], tag2[800009];
int sec[800009];
vector<int> son[200009];
void dfs(int x, int d) {
  dfsx[++tot] = x;
  deep[tot] = d;
  ll[x] = tot;
  c[tot] = vol[x];
  for (int i = 0; i < son[x].size(); i++) {
    int y = son[x][i];
    dfs(y, d + 1);
  }
  dfsx[++tot] = x;
  deep[tot] = d;
  rr[x] = tot;
  c[tot] = vol[x];
}
void pushdown(int k, int l, int r) {
  tag1[k * 2] += tag1[k];
  tag1[k * 2 + 1] += tag1[k];
  tag1[k] = 0;
  tag2[k * 2] += tag2[k];
  tag2[k * 2 + 1] += tag2[k];
  tag2[k] = 0;
}
void build(int k, int l, int r) {
  if (l == r) {
    if (deep[l] % 2 == 0)
      tag2[k] = c[l];
    else
      tag1[k] = c[l];
    return;
  }
  int mid = (l + r) / 2;
  build(k * 2, l, mid);
  build(k * 2 + 1, mid + 1, r);
}
void modify(int k, int l, int r, int x, int y, int v, int u) {
  if (l >= x && r <= y) {
    if (u)
      tag1[k] += v, tag2[k] -= v;
    else
      tag1[k] -= v, tag2[k] += v;
    return;
  }
  int mid = (l + r) / 2;
  pushdown(k, l, r);
  if (mid >= x) modify(k * 2, l, mid, x, y, v, u);
  if (mid < y) modify(k * 2 + 1, mid + 1, r, x, y, v, u);
}
int query(int k, int l, int r, int x) {
  if (l == r && l == x) {
    if (deep[l] % 2 == 0)
      return tag2[k];
    else
      return tag1[k];
  }
  int mid = (l + r) / 2;
  pushdown(k, l, r);
  if (mid >= x)
    return query(k * 2, l, mid, x);
  else
    return query(k * 2 + 1, mid + 1, r, x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &vol[i]);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    son[x].push_back(y);
  }
  dfs(1, 0);
  build(1, 1, 2 * n);
  for (int i = 1; i <= m; i++) {
    int op, x, w;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &w);
      modify(1, 1, n * 2, ll[x], rr[x], w, deep[ll[x]] % 2);
    } else {
      printf("%d\n", query(1, 1, n * 2, ll[x]));
    }
  }
  return 0;
}
