#include <bits/stdc++.h>
using namespace std;
const int M = 100000 + 10;
struct Node {
  int l, r, q;
};
struct Tree {
  int l, r;
  int ans;
  int lazy;
};
Tree tree[M * 3];
Node d[M];
int mex[M];
int n, m;
void get_same(int s) {
  if (tree[s].l == tree[s].r) return;
  if (tree[s].lazy) {
    tree[s << 1].ans = tree[s << 1].ans | tree[s].ans;
    tree[s << 1 | 1].ans = tree[s << 1 | 1].ans | tree[s].ans;
    tree[s << 1].lazy = tree[s << 1 | 1].lazy = 1;
    tree[s].lazy = tree[s].ans = 0;
  }
}
void bulit(int s, int l, int r) {
  tree[s].l = l;
  tree[s].r = r;
  tree[s].ans = 0;
  tree[s].lazy = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    bulit(s << 1, l, mid);
    bulit(s << 1 | 1, mid + 1, r);
  }
}
void updata(int s, int l, int r, int z) {
  if (tree[s].l == l && tree[s].r == r) {
    tree[s].ans = tree[s].ans | z;
    tree[s].lazy = 1;
    return;
  }
  get_same(s);
  int mid = (tree[s].l + tree[s].r) >> 1;
  if (r <= mid)
    updata(s << 1, l, r, z);
  else if (l > mid)
    updata(s << 1 | 1, l, r, z);
  else {
    updata(s << 1, l, mid, z);
    updata(s << 1 | 1, mid + 1, r, z);
  }
}
void inse(int s) {
  get_same(s);
  if (tree[s].l == tree[s].r) {
    mex[tree[s].l] = tree[s].ans;
    return;
  }
  inse(s << 1);
  inse(s << 1 | 1);
  tree[s].ans = tree[s << 1].ans & tree[s << 1 | 1].ans;
}
int query(int s, int l, int r) {
  if (tree[s].l == l && tree[s].r == r) {
    return tree[s].ans;
  }
  int mid = (tree[s].l + tree[s].r) >> 1;
  if (r <= mid)
    return query(s << 1, l, r);
  else if (l > mid)
    return query(s << 1 | 1, l, r);
  else
    return query(s << 1, l, mid) & query(s << 1 | 1, mid + 1, r);
}
bool solve() {
  for (int i = 0; i < m; i++) {
    if (query(1, d[i].l, d[i].r) != d[i].q) return false;
  }
  return true;
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    bulit(1, 1, n);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &d[i].l, &d[i].r, &d[i].q);
      updata(1, d[i].l, d[i].r, d[i].q);
    }
    inse(1);
    if (solve()) {
      puts("YES");
      for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", mex[i]);
      }
      printf("\n");
    } else {
      puts("NO");
    }
  }
  return 0;
}
