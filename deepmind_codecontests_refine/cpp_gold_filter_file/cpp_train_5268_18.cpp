#include <bits/stdc++.h>
using namespace std;
int n, m, q, flag[15][100005];
int l, r;
struct Node {
  int l[15], r[15];
  int sum;
};
Node tree[500005];
Node ans;
int fa[2000005];
int getfa(int x) {
  if (fa[x] != x) fa[x] = getfa(fa[x]);
  return fa[x];
}
Node update(Node lson, Node rson, int l, int mid, int r) {
  Node ans;
  ans.sum = lson.sum + rson.sum;
  for (int i = 1; i <= n; ++i) fa[lson.l[i]] = lson.l[i];
  for (int i = 1; i <= n; ++i) fa[lson.r[i]] = lson.r[i];
  for (int i = 1; i <= n; ++i) fa[rson.l[i]] = rson.l[i];
  for (int i = 1; i <= n; ++i) fa[rson.r[i]] = rson.r[i];
  for (int i = 1; i <= n; ++i) {
    if (flag[i][mid] == flag[i][mid + 1]) {
      const int dqx = getfa(lson.r[i]);
      const int dqy = getfa(rson.l[i]);
      if (dqx != dqy) {
        ans.sum--;
        fa[dqx] = dqy;
      }
    }
  }
  for (int i = 1; i <= n; ++i) ans.l[i] = getfa(lson.l[i]);
  for (int i = 1; i <= n; ++i) ans.r[i] = getfa(rson.r[i]);
  return ans;
}
void build(int x, int l, int r) {
  static int cnt = 0;
  if (l == r) {
    for (int i = 1; i <= n; ++i)
      if (flag[i][l] == flag[i - 1][l]) {
        tree[x].l[i] = tree[x].l[i - 1];
        tree[x].r[i] = tree[x].r[i - 1];
      } else {
        ++cnt;
        tree[x].l[i] = cnt;
        tree[x].r[i] = cnt;
        tree[x].sum++;
      }
    return;
  }
  const int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
  tree[x] = update(tree[x * 2], tree[x * 2 + 1], l, mid, r);
}
Node query(int x, int l, int r, int ll, int rr) {
  if (l == ll && rr == r) return tree[x];
  const int mid = (l + r) / 2;
  if (rr <= mid)
    return query(x * 2, l, mid, ll, rr);
  else if (ll >= mid + 1)
    return query(x * 2 + 1, mid + 1, r, ll, rr);
  else
    return update(query(x * 2, l, mid, ll, mid),
                  query(x * 2 + 1, mid + 1, r, mid + 1, rr), ll, mid, rr);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &flag[i][j]);
  build(1, 1, m);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    ans = query(1, 1, m, l, r);
    printf("%d\n", ans.sum);
  }
  return 0;
}
