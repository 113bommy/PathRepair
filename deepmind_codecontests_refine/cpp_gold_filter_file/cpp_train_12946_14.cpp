#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, m, k, u, v, y, tm[N], dep[N], f[N][18], id[N], cnt[N], ont[N], tot;
vector<int> s[N];
int LCA(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int k = dep[v] - dep[u], j = 17; j >= 0; j--)
    if ((k >> j) & 1) v = f[v][j], k ^= (1 << j);
  if (u == v) return u;
  for (int k = 17; f[u][0] != f[v][0]; u = f[u][k], v = f[v][k])
    for (; k && f[u][k] == f[v][k]; k--)
      ;
  return f[u][0];
}
void dfs(int u) {
  id[cnt[u] = tot++] = u;
  for (int j = 0; j < s[u].size(); j++) dep[s[u][j]] = dep[u] + 1, dfs(s[u][j]);
  ont[u] = tot;
}
struct node {
  node *l, *r;
  int sum;
} pool[6010000], *rt[101000], *cur = pool, *tmp;
node *build(int l, int r) {
  node *p = cur++;
  int mid = (l + r) >> 1;
  if (l != r) p->l = build(l, mid), p->r = build(mid + 1, r);
  return p;
}
node *add(node *q, int l, int r, int x, int d) {
  if (x > r) return q;
  node *p = cur++;
  if (l == r)
    p->sum = q->sum + d;
  else {
    int mid = (l + r) >> 1;
    if (x <= mid)
      p->l = add(q->l, l, mid, x, d), p->r = q->r;
    else
      p->l = q->l, p->r = add(q->r, mid + 1, r, x, d);
    p->sum = p->l->sum + p->r->sum;
  }
  return p;
}
int ask(node *l, node *r, int x) {
  int tl = 1, tr = n, ans = 0;
  x = cnt[x];
  while (tl != tr) {
    int mid = (tl + tr) >> 1;
    if (x <= mid)
      l = l->l, r = r->l, tr = mid;
    else
      ans += r->l->sum - l->l->sum, l = l->r, r = r->r, tl = mid + 1;
  }
  return ans + r->sum - l->sum;
}
int query(int u, int x, int l, int r) {
  x = dep[u] - ask(rt[l], rt[r], u) - x + 1;
  for (int k = 17; k >= 0; k--) {
    int t = dep[f[u][k]] - ask(rt[l], rt[r], f[u][k]);
    if (x <= t) u = f[u][k];
  }
  return u;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++)
    scanf("%d", &f[i][0]), s[f[i][0]].push_back(i);
  for (int j = 1; j < 18; j++)
    for (int i = 1; i < n + 1; i++) f[i][j] = f[f[i][j - 1]][j - 1];
  dfs(0);
  scanf("%d", &m);
  rt[0] = build(1, n);
  for (int i = 1; i < m + 1; i++) {
    scanf("%d", &k);
    if (k == 1)
      scanf("%d", &u), tm[u] = i, tmp = add(rt[i - 1], 1, n, cnt[u], 1),
                       rt[i] = add(tmp, 1, n, ont[u], -1);
    else {
      scanf("%d%d%d%d", &u, &v, &k, &y);
      rt[i] = rt[i - 1];
      int p = LCA(u, v), pu = dep[u] - ask(rt[y], rt[i], u),
          pv = dep[v] - ask(rt[y], rt[i], v),
          pf = dep[p] - ask(rt[y], rt[i], p);
      pu = pu - pf + (tm[p] <= y);
      pv = pv - pf;
      if (k > pu + pv - (tm[u] <= y) - (tm[v] <= y))
        puts("-1");
      else if (k <= pu - (tm[u] <= y))
        printf("%d\n", query(u, k + (tm[u] <= y), y, i));
      else
        printf("%d\n", query(v, pv + pu - k - (tm[u] <= y) + 1, y, i));
    }
  }
}
