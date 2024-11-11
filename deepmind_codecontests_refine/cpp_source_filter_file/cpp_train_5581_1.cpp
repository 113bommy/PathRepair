#include <bits/stdc++.h>
using namespace std;
int dp[36000];
int a[36000];
int pos[36000];
int pre[36000];
struct node {
  int l, r;
  int add;
  int mx;
} tree[36000 << 2];
void pushup(int index) {
  tree[index].mx = max(tree[index << 1].mx, tree[index << 1 | 1].mx);
}
void pushdown(int index) {
  if (tree[index].add > 0) {
    tree[index << 1].mx += tree[index].add;
    tree[index << 1 | 1].mx += tree[index].add;
    tree[index << 1].add += tree[index].add;
    tree[index << 1 | 1].add += tree[index].add;
    tree[index].add = 0;
  }
}
void build(int l, int r, int index) {
  tree[index].l = l;
  tree[index].r = r;
  tree[index].add = 0;
  if (l == r) {
    tree[index].mx = dp[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, index << 1);
  build(mid + 1, r, index << 1 | 1);
  pushup(index);
}
void updata(int l, int r, int index, int val) {
  if (l <= tree[index].l && r >= tree[index].r) {
    tree[index].mx += val;
    tree[index].add += val;
    return;
  }
  pushdown(index);
  int mid = (tree[index].l + tree[index].r) >> 1;
  if (l <= mid) {
    updata(l, r, index << 1, val);
  }
  if (r > mid) {
    updata(l, r, index << 1 | 1, val);
  }
  pushup(index);
}
int query(int l, int r, int index) {
  if (l <= tree[index].l && r >= tree[index].r) {
    return tree[index].mx;
  }
  pushdown(index);
  int mid = (tree[index].l + tree[index].r) >> 1;
  int Max = 0;
  if (l <= mid) {
    Max = max(query(l, r, index << 1), Max);
  }
  if (r > mid) {
    Max = max(query(l, r, index << 1 | 1), Max);
  }
  return Max;
}
int main() {
  int n, k;
  while (cin >> n >> k) {
    memset(dp, 0, sizeof(dp));
    memset(pos, 0, sizeof(pos));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pos[a[i]];
      pos[a[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
      build(1, n, 1);
      for (int j = 1; j <= n; j++) {
        updata(pre[j] + 1, j, 1, 1);
        dp[j] = query(1, j, 1);
      }
    }
    cout << dp[n] << "\n";
  }
  return 0;
}
