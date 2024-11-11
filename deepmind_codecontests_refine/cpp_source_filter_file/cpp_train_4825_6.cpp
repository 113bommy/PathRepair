#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int mod = 1e9 + 9;
int n, k, m, a, b, c, d;
struct Data {
  int x, y;
  Data() {}
  Data(int x, int y) : x(x), y(y) {}
} da[N];
bool operator<(const Data &A, const Data &B) { return A.x < B.x; }
struct Seg {
  int l, r, mid;
  int ch[2];
  pair<int, int> val;
} tree[N * 30];
int tot;
pair<int, int> update(pair<int, int> a, pair<int, int> b) {
  return make_pair(
      max(a.first + b.first, max(a.first + b.second, a.second + b.first) + 1),
      a.first + b.first);
}
int BTree(int l, int r) {
  int loc = ++tot;
  if (l > r) {
    tree[loc].mid = l;
    tree[loc].ch[0] = tree[loc].ch[1] = -1;
    tree[loc].val = make_pair(0, -1);
    return loc;
  }
  tree[loc].l = l;
  tree[loc].r = r;
  tree[loc].mid = l;
  for (int i = l + 1; i <= r; i++) {
    if (da[tree[loc].mid].y > da[i].y) tree[loc].mid = i;
  }
  tree[loc].ch[0] = BTree(l, tree[loc].mid - 1);
  tree[loc].ch[1] = BTree(tree[loc].mid + 1, r);
  tree[loc].val = update(tree[tree[loc].ch[0]].val, tree[tree[loc].ch[1]].val);
  return loc;
}
pair<int, int> Query(int l, int r, int idx) {
  if (r < l) return make_pair(0, -1);
  if (tree[idx].l == l && tree[idx].r == r) {
    return tree[idx].val;
  }
  if (r < tree[idx].mid) return Query(l, r, tree[idx].ch[0]);
  if (r == tree[idx].mid) {
    pair<int, int> ret = Query(l, r - 1, tree[idx].ch[0]);
    ret = make_pair(max(ret.first, ret.second + 1), max(ret.first, ret.second));
    return ret;
  }
  if (l > tree[idx].mid) return Query(l, r, tree[idx].ch[1]);
  return update(Query(l, tree[idx].mid - 1, tree[idx].ch[0]),
                Query(tree[idx].mid + 1, r, tree[idx].ch[1]));
}
int x[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &da[i].x, &da[i].y);
  }
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = k + 1; i <= n; i++) {
    da[i].x = (1ll * da[i - 1].x * a + b) % mod;
    da[i].y = (1ll * da[i - 1].y * c + d) % mod;
  }
  sort(da + 1, da + n + 1);
  for (int i = 1; i <= n; i++) x[i] = da[i].x;
  tot = 0;
  int root = BTree(1, n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = lower_bound(x + 1, x + n + 1, l) - x;
    r = upper_bound(x + 1, x + n + 1, r) - x - 1;
    if (r < l)
      printf("0\n");
    else
      printf("%d\n", Query(l, r, root).first);
  }
  return 0;
}
