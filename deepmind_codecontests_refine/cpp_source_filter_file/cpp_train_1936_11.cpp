#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
struct treenode {
  int num, ord;
};
treenode tree[2000000];
const int p = 10000007;
bool b[10000007];
int h[500000];
int o[500000], x[500000], y[500000], z[500000];
int i, j, m, n, t;
inline void pushdown(int l, int r, int node) {
  if (l != r) {
    if (!tree[node << 1].ord)
      tree[node << 1].num = min(tree[node << 1].num, tree[node].num);
    if (!tree[node << 1 | 1].ord)
      tree[node << 1 | 1].num = min(tree[node << 1 | 1].num, tree[node].num);
  }
  return;
}
inline void buildtree(int l, int r, int node) {
  tree[node].num = inf;
  if (l != r) {
    int mid = (l + r) >> 1;
    buildtree(l, mid, node << 1);
    buildtree(mid + 1, r, node << 1 | 1);
  }
  return;
}
inline void insertmin(int l, int r, int x, int y, int z, int node) {
  pushdown(l, r, node);
  if ((l == x) && (r == y)) {
    if (!tree[node].ord) tree[node].num = min(tree[node].num, z);
  } else {
    int mid = (l + r) >> 1;
    if (y <= mid)
      insertmin(l, mid, x, y, z, node << 1);
    else if (x > mid)
      insertmin(mid + 1, r, x, y, z, node << 1 | 1);
    else {
      insertmin(l, mid, x, mid, z, node << 1);
      insertmin(mid + 1, r, mid + 1, y, z, node << 1 | 1);
    }
  }
  return;
}
inline void protectnode(int l, int r, int x, int node) {
  pushdown(l, r, node);
  if (l == r)
    tree[node].ord = 1;
  else {
    int mid = (l + r) >> 1;
    if (x <= mid)
      protectnode(l, mid, x, node << 1);
    else
      protectnode(mid + 1, r, x, node << 1 | 1);
  }
  return;
}
inline void resettree(int l, int r, int node) {
  pushdown(l, r, node);
  if (l == r)
    h[l] = tree[node].num;
  else {
    int mid = (l + r) >> 1;
    resettree(l, mid, node << 1);
    resettree(mid + 1, r, node << 1 | 1);
    tree[node].num = max(tree[node << 1].num, tree[node << 1 | 1].num);
  }
  return;
}
inline void insertmax(int l, int r, int x, int y, int node) {
  if (l == r)
    tree[node].num = y;
  else {
    int mid = (l + r) >> 1;
    if (x <= mid)
      insertmax(l, mid, x, y, node << 1);
    else
      insertmax(mid + 1, r, x, y, node << 1 | 1);
    tree[node].num = max(tree[node << 1].num, tree[node << 1 | 1].num);
  }
  return;
}
inline int askmax(int l, int r, int x, int y, int node) {
  if ((l == x) && (r == y)) return tree[node].num;
  int mid = (l + r) >> 1;
  if (y <= mid) return askmax(l, mid, x, y, node << 1);
  if (x > mid) return askmax(mid + 1, r, x, y, node << 1 | 1);
  return max(askmax(l, mid, x, mid, node << 1),
             askmax(mid + 1, r, mid + 1, y, node << 1 | 1));
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &o[i]);
    if (o[i] == 1)
      scanf("%d%d%d", &x[i], &y[i], &z[i]);
    else
      scanf("%d%d", &x[i], &z[i]);
  }
  buildtree(1, n, 1);
  memset(h, 64, sizeof(h));
  for (i = 1; i <= m; i++)
    if (o[i] == 1)
      insertmin(1, n, x[i], y[i], z[i], 1);
    else
      protectnode(1, n, x[i], 1);
  resettree(1, n, 1);
  for (i = 1; i <= m; i++)
    if (o[i] == 2)
      insertmax(1, n, x[i], z[i], 1);
    else if (askmax(1, n, x[i], y[i], 1) != z[i])
      return puts("NO"), 0;
  puts("YES");
  for (i = 1; i <= n; i++)
    if (h[i] == inf) t++;
  if (t > 1)
    for (i = 1; i <= n; i++)
      if ((h[i] == inf) && (t))
        t = 0, printf("%d ", (1 << 29) - 1);
      else if (h[i] == inf)
        printf("%d ", h[i] - 1);
      else
        printf("%d ", h[i]);
  else {
    for (i = 1; i <= n; i++)
      if (h[i] != inf) {
        if (!b[h[i] % p])
          b[h[i] % p] = true;
        else {
          for (j = 0; j <= 30; j++)
            if ((1 << j) >= h[i]) break;
          j--;
          if (j >= 0) h[i] = (1 << j) - 1;
        }
      }
    t = 0;
    for (i = 1; i <= n; i++)
      if (h[i] != inf) t = t | h[i];
    for (i = 1; i <= n; i++)
      if (h[i] == inf) {
        h[i] = 0;
        for (j = 29; j >= 0; j--)
          if ((!(t & (1 << j))) && (h[i] + (1 << j) < inf))
            h[i] = h[i] + (1 << j);
      }
    for (i = 1; i <= n; i++) printf("%d ", h[i]);
  }
  return 0;
}
