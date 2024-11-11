#include <bits/stdc++.h>
using namespace std;
struct node {
  int leftColors[10], rightColors[10];
  int leftParent[10], rightParent[10];
  int components;
  node() { components = 0; }
};
int n;
node merge(node l, node r) {
  node ans;
  ans.components = l.components + r.components;
  for (int e = 0; e < n; e++) ans.leftParent[e] = l.leftParent[e];
  for (int e = 0; e < n; e++) ans.leftColors[e] = l.leftColors[e];
  for (int e = 0; e < n; e++) ans.rightParent[e] = r.rightParent[e];
  for (int e = 0; e < n; e++) ans.rightColors[e] = r.rightColors[e];
  for (int e = 0; e < n; e++) {
    if (l.rightColors[e] == r.leftColors[e] &&
        l.rightParent[e] != r.leftParent[e]) {
      ans.components--;
      int tmp = l.rightParent[e];
      for (int f = 0; f < n; f++)
        if (ans.leftParent[e] == tmp) ans.leftParent[e] = r.leftParent[e];
      for (int f = 0; f < n; f++)
        if (ans.rightParent[e] == tmp) ans.rightParent[e] = r.leftParent[e];
      for (int f = 0; f < n; f++)
        if (l.leftParent[e] == tmp) l.leftParent[e] = r.leftParent[e];
      for (int f = 0; f < n; f++)
        if (l.rightParent[e] == tmp) l.rightParent[e] = r.leftParent[e];
    }
  }
  return ans;
}
const int maxn = 100100;
node tree[maxn << 2];
int grid[11][maxn];
void build(int id, int l, int r) {
  if (l == r) {
    for (int e = 0; e < n; e++) {
      if (e && grid[e][l] == tree[id].leftColors[e - 1])
        tree[id].leftParent[e] = tree[id].leftParent[e - 1],
        tree[id].rightParent[e] = tree[id].rightParent[e - 1],
        tree[id].leftColors[e] = tree[id].leftColors[e - 1],
        tree[id].rightColors[e] = tree[id].rightColors[e - 1];
      else {
        tree[id].leftParent[e] = l * 20 + e;
        tree[id].rightParent[e] = l * 20 + e;
        tree[id].leftColors[e] = grid[e][l];
        tree[id].rightColors[e] = grid[e][l];
        tree[id].components++;
      }
    }
  } else {
    int mid = (l + r) >> 1;
    build(id + id, l, mid);
    build(id + id + 1, mid + 1, r);
    tree[id] = merge(tree[id + id], tree[id + id + 1]);
  }
}
node query(int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) return tree[id];
  int mid = (l + r) >> 1;
  if (y <= mid) return query(id + id, l, mid, x, y);
  if (x > mid) return query(id + id + 1, mid + 1, r, x, y);
  return merge(query(id + id, l, mid, x, y),
               query(id + id + 1, mid + 1, r, x, y));
}
int main() {
  int m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int e = 0; e < n; e++)
    for (int f = 0; f < m; f++) scanf("%d", &grid[e][f]);
  build(1, 0, m - 1);
  for (int e = 0; e < q; e++) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", query(1, 0, m - 1, l - 1, r - 1).components);
  }
  return 0;
}
