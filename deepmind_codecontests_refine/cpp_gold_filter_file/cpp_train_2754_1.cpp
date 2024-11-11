#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1000000005;
const int MAXN = 2e6 + 5;
const double eps = 1e-9;
using namespace std;
struct node {
  int x1, y1, y2, id, t;
} a[MAXN];
long long len[MAXN];
pair<long long, long long> tree[MAXN];
int par[MAXN], cur, nod, ls[MAXN], rs[MAXN], vis[MAXN];
int qry(int x) {
  if (x != par[x]) return par[x] = qry(par[x]);
  return x;
}
void add(int l, int r, int &k, int u, int id) {
  if (!k) k = ++nod;
  vis[k] = 0;
  if (l == r) {
    tree[k] = {id, 1};
    return;
  }
  int m = l + (r - l) / 2;
  if (u <= m)
    add(l, m, ls[k], u, id);
  else
    add(m + 1, r, rs[k], u, id);
  tree[k].second = tree[ls[k]].second + tree[rs[k]].second;
  tree[k].first = max(tree[ls[k]].first, tree[rs[k]].first);
}
void del(int l, int r, int &k, int u, int id) {
  if (!k) k = ++nod;
  vis[k] = 0;
  if (l == r) {
    tree[k] = {0, 0};
    return;
  }
  int m = l + (r - l) / 2;
  if (u <= m)
    del(l, m, ls[k], u, id);
  else
    del(m + 1, r, rs[k], u, id);
  tree[k].second = tree[ls[k]].second + tree[rs[k]].second;
  tree[k].first = max(tree[ls[k]].first, tree[rs[k]].first);
}
void prop(int k) {
  if (!k || vis[k]) return;
  vis[k] = 1;
  if (tree[ls[k]].first && tree[rs[k]].first)
    par[qry(tree[ls[k]].first)] = qry(tree[rs[k]].first);
  prop(ls[k]);
  prop(rs[k]);
}
long long qqry(int l, int r, int k, int u, int v, int id) {
  if (!k || !tree[k].first) return 0;
  if (u <= l && r <= v) {
    par[qry(tree[k].first)] = qry(id);
    prop(k);
    return tree[k].second;
  }
  int m = l + (r - l) / 2;
  long long ret = 0;
  if (u <= m) ret += qqry(l, m, ls[k], u, v, id);
  if (v > m) ret += qqry(m + 1, r, rs[k], u, v, id);
  return ret;
}
int main() {
  int n, cnt = 0;
  scanf("%d", &(n));
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 == x2)
      a[++cnt] = (node){x1, y1, y2, i, 2};
    else {
      len[i] = x2 - x1 + 1;
      a[++cnt] = (node){x1, y1, 0, i, 1};
      a[++cnt] = (node){x2, y1, 0, i, 3};
    }
  }
  for (int i = 1; i <= n; i++) par[i] = i;
  sort(a + 1, a + cnt + 1, [](node lhs, node rhs) -> bool {
    if (lhs.x1 == rhs.x1) return lhs.t < rhs.t;
    return lhs.x1 < rhs.x1;
  });
  for (int i = 1; i <= cnt; i++)
    if (a[i].t == 2)
      len[a[i].id] = a[i].y2 - a[i].y1 + 1 -
                     qqry(-INF, INF, cur, a[i].y1, a[i].y2, a[i].id);
    else if (a[i].t == 1)
      add(-INF, INF, cur, a[i].y1, a[i].id);
    else
      del(-INF, INF, cur, a[i].y1, a[i].id);
  for (int i = 1; i <= n; i++)
    if (qry(i) != i) len[qry(i)] += len[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, len[i]);
  printf("%I64d\n", (ans - 1));
  return 0;
}
