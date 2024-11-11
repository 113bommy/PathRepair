#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, z, zz, belong[200005], deep[200005], size[200005], root[200005],
    treesize, ANS;
vector<int> e[200005];
struct segtree {
  int l, r, s, mark;
  int mid() { return (l + r) >> 1; }
} tree[16 * 200005];
int dfs(int x, int f, int id, int de) {
  belong[x] = id, deep[x] = de, size[x] = 1;
  for (int i = 0, l = e[x].size(); i < l; i++)
    if (e[x][i] != f) {
      if (x == 1)
        size[x] += dfs(e[x][i], x, i + 1, de + 1);
      else
        size[x] += dfs(e[x][i], x, id, de + 1);
    }
  return size[x];
}
void buildtree(int l, int r, int xx, int delta) {
  int x = xx + delta;
  tree[x].l = l, tree[x].r = r;
  if (l == r) return;
  int mid = tree[x].mid();
  buildtree(l, mid, (xx << 1), delta);
  buildtree(mid + 1, r, ((xx << 1) + 1), delta);
}
void add_mark(int l, int r, int ad, int xx, int delta) {
  int x = xx + delta;
  if (tree[x].l >= l && tree[x].r <= r) {
    tree[x].mark += ad;
    return;
  }
  if (tree[x].mark) {
    tree[delta + (xx << 1)].mark += tree[x].mark,
        tree[delta + ((xx << 1) + 1)].mark += tree[x].mark;
    tree[x].mark = 0;
  }
  int mid = tree[x].mid();
  if (l <= mid) add_mark(l, r, ad, (xx << 1), delta);
  if (r > mid) add_mark(l, r, ad, ((xx << 1) + 1), delta);
}
int query(int pnt, int xx, int delta) {
  int x = xx + delta;
  if (tree[x].l == tree[x].r) {
    return tree[x].mark;
  }
  if (tree[x].mark) {
    tree[delta + (xx << 1)].mark += tree[x].mark,
        tree[delta + ((xx << 1) + 1)].mark += tree[x].mark;
    tree[x].mark = 0;
  }
  int mid = tree[x].mid();
  if (pnt <= mid)
    return query(pnt, (xx << 1), delta);
  else
    return query(pnt, ((xx << 1) + 1), delta);
}
int main() {
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y), e[y].push_back(x);
  }
  dfs(1, 0, 0, 0);
  for (int i = 1, l = e[1].size(); i <= l; i++) {
    root[e[1][i - 1]] = treesize;
    treesize += size[e[1][i - 1]] * 4;
    buildtree(1, size[e[1][i - 1]], 1, root[e[1][i - 1]]);
  }
  root[0] = treesize;
  buildtree(1, 100005, 1, root[0]);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &x);
    if (x == 0) {
      scanf("%d%d%d", &y, &z, &zz);
      int b = e[1][belong[y] - 1];
      if (y != 1) {
        int k = min(size[b] - deep[y], zz), kk = min(deep[y] - 1, zz);
        add_mark(deep[y] - kk, deep[y] + k, z, 1, root[b]);
        if (deep[y] <= zz) ANS += z;
        int tt = zz - deep[y];
        if (tt > 0) {
          add_mark(1, tt, z, 1, root[0]);
          add_mark(1, tt, -z, 1, root[b]);
        }
      }
      if (y == 1) {
        ANS += z;
        add_mark(1, zz, z, 1, root[0]);
      }
    } else {
      scanf("%d", &y);
      int b = e[1][belong[y] - 1];
      if (y == 1)
        cout << ANS << endl;
      else {
        printf("%d\n", query(deep[y], 1, root[b]) + query(deep[y], 1, root[0]));
      }
    }
  }
  return 0;
}
