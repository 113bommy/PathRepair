#include <bits/stdc++.h>
struct Segment_Tree {
  long long val, size, lson, rson;
} tree[5000100];
long long idx, ans, fa[1000100], R[1000100], root[1000100];
long long n, A, B;
void insert(long long &t, long long l, long long r, long long pos) {
  if (!t) t = ++idx;
  if (l == r) {
    tree[t].size = 1;
    tree[t].val = pos;
    return;
  }
  long long mid = (l + r) / 2;
  if (pos <= mid)
    insert(tree[t].lson, l, mid, pos);
  else
    insert(tree[t].rson, mid + 1, r, pos);
  tree[t].val = tree[tree[t].lson].val + tree[tree[t].rson].val;
  tree[t].size = tree[tree[t].lson].size + tree[tree[t].rson].size;
}
long long find(long long x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
long long merge(long long x, long long y) {
  if (!x || !y) return x | y;
  ans -= tree[tree[x].lson].val * tree[tree[x].rson].size +
         tree[tree[y].lson].val * tree[tree[y].rson].size;
  tree[x].lson = merge(tree[x].lson, tree[y].lson);
  tree[x].rson = merge(tree[x].rson, tree[y].rson);
  ans += tree[tree[x].lson].val * tree[tree[x].rson].size;
  tree[x].size += tree[y].size;
  tree[x].val += tree[y].val;
  return x;
}
void solve(long long x, long long y) {
  long long fx = find(x), fy = find(y);
  fa[fy] = fx;
  ans -= tree[root[fx]].val * fx + tree[root[fy]].val * fy;
  root[fx] = merge(root[fx], root[fy]);
  ans += tree[root[fx]].val * fx;
  R[fx] = R[fy];
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= 400000; i++) fa[i] = R[i] = i;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &A, &B);
    long long p = root[A] ? R[find(A)] + 1 : A;
    ans -= A * B;
    insert(root[p], 1, n, B);
    ans += p * B;
    if (root[p - 1]) solve(p - 1, p);
    if (root[p + 1]) solve(p, p + 1);
    printf("%lld\n", ans);
  }
}
