#include <bits/stdc++.h>
using namespace std;
struct Node {
  int typ;
  long long l, r;
  bool operator<(Node a) {
    if (typ != a.typ || typ != 2) return typ > a.typ;
    return min(l, r) < min(a.l, a.r);
  }
} tree[400005], Tree[400005];
int data[100005];
long long xf[100005];
long long Ans = 0;
Node Max(Node a, Node b) {
  if (a < b) return b;
  return a;
}
Node Min(Node a, Node b) {
  if (a < b) return a;
  return b;
}
void buildtree(int l, int r, int node) {
  if (l == r) {
    tree[node].l = -xf[l];
    tree[node].r = xf[r + 1];
    tree[node].typ = (tree[node].l < 0) + (tree[node].r < 0);
    Tree[node] = tree[node];
    if (Tree[node].typ != 2) Tree[node].typ = -1;
    return;
  }
  int mid = (l + r) / 2;
  buildtree(l, mid, node * 2);
  buildtree(mid + 1, r, node * 2 + 1);
  tree[node] = Max(tree[node * 2], tree[node * 2 + 1]);
  Tree[node] = Min(Tree[node * 2], Tree[node * 2 + 1]);
}
void update(int l, int r, int node, int c, int val, int zt) {
  if (l == r) {
    if (zt == 0)
      tree[node].l += val;
    else
      tree[node].r += val;
    tree[node].typ = (tree[node].l < 0) + (tree[node].r < 0);
    Tree[node] = tree[node];
    if (Tree[node].typ != 2) Tree[node].typ = -1;
    return;
  }
  int mid = (l + r) / 2;
  if (c <= mid)
    update(l, mid, node * 2, c, val, zt);
  else
    update(mid + 1, r, node * 2 + 1, c, val, zt);
  tree[node] = Max(tree[node * 2], tree[node * 2 + 1]);
  Tree[node] = Min(Tree[node * 2], Tree[node * 2 + 1]);
}
Node query(int l, int r, int node, int _l, int _r) {
  int mid = (l + r) >> 1;
  if (_l > r || _r < l) {
    Node a;
    a.typ = 3;
    return a;
  } else if (_l <= l && _r >= r)
    return tree[node];
  else
    return Max(query(l, mid, node << 1, _l, _r),
               query(mid + 1, r, node << 1 | 1, _l, _r));
}
Node Query(int l, int r, int node, int _l, int _r) {
  int mid = (l + r) >> 1;
  if (_l > r || _r < l) {
    Node a;
    a.typ = -1;
    return a;
  } else if (_l <= l && _r >= r)
    return Tree[node];
  else
    return Min(Query(l, mid, node << 1, _l, _r),
               Query(mid + 1, r, node << 1 | 1, _l, _r));
}
long long solve(long long x, long long a) {
  a = -a;
  if (a > x) return -x;
  return x - 2 * a;
}
long long __abs(long long a) { return a > 0 ? a : -a; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); i++) scanf("%d", &data[i]);
  for (int i = (2); i < (n + 1); i++) xf[i] = data[i - 1] - data[i];
  for (int i = (2); i < (n + 1); i++) Ans += __abs(xf[i]);
  int m;
  scanf("%d", &m);
  buildtree(2, n - 1, 1);
  while (m--) {
    int co, l, r, x;
    scanf("%d%d%d%d", &co, &l, &r, &x);
    if (co == 1) {
      Node ans = query(2, n - 1, 1, l, r);
      long long ANS;
      if (ans.typ == 0)
        ANS = x * 2 + Ans;
      else if (ans.typ == 1)
        ANS = Ans + x + solve(x, min(ans.l, ans.r));
      else
        ANS = Ans + solve(x, ans.l) + solve(x, ans.r);
      ans = Query(2, n - 1, 1, l, r);
      if (ans.typ == 2) ANS = max(ANS, Ans + solve(x, ans.l) + solve(x, ans.r));
      printf("%lld\n", ANS);
    } else {
      if (l - 1 > 1) update(2, n - 1, 1, l - 1, -x, 1);
      update(2, n - 1, 1, l, x, 0);
      update(2, n - 1, 1, r, x, 1);
      if (r + 1 < n) update(2, n - 1, 1, r + 1, -x, 0);
      Ans -= __abs(xf[l]);
      Ans -= __abs(xf[r + 1]);
      xf[l] -= x;
      xf[r + 1] += x;
      Ans += __abs(xf[l]);
      Ans += __abs(xf[r + 1]);
    }
  }
  return 0;
}
