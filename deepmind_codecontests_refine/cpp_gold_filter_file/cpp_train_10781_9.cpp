#include <bits/stdc++.h>
using namespace std;
int n, m, a[300005], l, r, w;
struct Node {
  int ans, lans, rans, ld, ru, len;
  long long lw, rw, maxw;
  long long bj;
} tree[1200005];
Node merge1(Node a, Node b) {
  Node ans;
  ans.bj = 0;
  ans.lw = a.lw;
  ans.rw = b.rw;
  ans.maxw = max(a.maxw, b.maxw);
  ans.len = a.len + b.len;
  ans.ld = a.ld;
  if (a.ld == a.len && a.rw > b.lw) ans.ld = a.ld + b.ld;
  ans.lans = a.lans;
  if (a.lans == a.len && a.rw == a.maxw && a.rw < b.lw)
    ans.lans = a.lans + b.lans;
  if (a.lans == a.len && a.rw > b.lw) ans.lans = max(ans.lans, a.lans + b.ld);
  ans.ru = b.ru;
  if (b.ru == b.len && b.lw > a.rw) ans.ru = b.ru + a.ru;
  ans.rans = b.rans;
  if (b.rans == b.len && b.lw < a.rw && b.lw == b.maxw)
    ans.rans = b.rans + a.rans;
  if (b.rans == b.len && b.lw > a.rw) ans.rans = max(ans.rans, b.rans + a.ru);
  ans.ans = max(a.ans, b.ans);
  if (a.rw > b.lw) ans.ans = max(ans.ans, a.rans + b.ld);
  if (a.rw < b.lw) ans.ans = max(ans.ans, a.ru + b.lans);
  return ans;
}
void build(int x, int l, int r) {
  if (l == r) {
    tree[x].ans = tree[x].lans = tree[x].rans = tree[x].ld = tree[x].ru =
        tree[x].len = 1;
    tree[x].bj = 0;
    tree[x].lw = tree[x].rw = tree[x].maxw = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
  tree[x] = merge1(tree[x * 2], tree[x * 2 + 1]);
}
void down(int x) {
  if (tree[x].bj != 0) {
    tree[2 * x].bj += tree[x].bj;
    tree[2 * x + 1].bj += tree[x].bj;
    tree[2 * x].lw += tree[x].bj;
    tree[2 * x + 1].lw += tree[x].bj;
    tree[2 * x].rw += tree[x].bj;
    tree[2 * x + 1].rw += tree[x].bj;
    tree[2 * x].maxw += tree[x].bj;
    tree[2 * x + 1].maxw += tree[x].bj;
    tree[x].bj = 0;
  }
}
void change(int x, int l, int r, int ll, int rr, int w) {
  if (l == ll && rr == r) {
    tree[x].bj += w;
    tree[x].lw += w;
    tree[x].rw += w;
    tree[x].maxw += w;
    return;
  }
  down(x);
  int mid = (l + r) / 2;
  if (rr <= mid)
    change(x * 2, l, mid, ll, rr, w);
  else if (ll >= mid + 1)
    change(x * 2 + 1, mid + 1, r, ll, rr, w);
  else {
    change(x * 2, l, mid, ll, mid, w);
    change(x * 2 + 1, mid + 1, r, mid + 1, rr, w);
  }
  tree[x] = merge1(tree[x * 2], tree[x * 2 + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  build(1, 1, n);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &l, &r, &w);
    change(1, 1, n, l, r, w);
    printf("%d\n", tree[1].ans);
  }
  return 0;
}
