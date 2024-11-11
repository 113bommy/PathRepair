#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node {
  long long sum, mx;
} tree[100005 * 6];
void push_up(int node) {
  tree[node].mx = max(tree[node << 1].mx, tree[node << 1 | 1].mx);
  tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
}
void build(int left, int right, int node) {
  if (left == right) {
    scanf("%I64d", &tree[node].mx);
    tree[node].sum = tree[node].mx;
    return;
  }
  int mid = (left + right) >> 1;
  build(left, mid, node << 1);
  build(mid + 1, right, node << 1 | 1);
  push_up(node);
}
long long get_sum(int left, int right, int node, int L, int R) {
  if (L <= left && R >= right) {
    return tree[node].sum;
  }
  int mid = (left + right) >> 1;
  long long sum = 0;
  if (L <= mid) {
    sum += get_sum(left, mid, node << 1, L, R);
  }
  if (R > mid) {
    sum += get_sum(mid + 1, right, node << 1 | 1, L, R);
  }
  return sum;
}
void Update(int left, int right, int node, int L, int R, long long Mod) {
  if (tree[node].mx < Mod) {
    return;
  }
  if (left >= L && right <= R) {
    if (left == right) {
      tree[node].sum %= Mod;
      tree[node].mx %= Mod;
      return;
    }
    int mid = (left + right) >> 1;
    Update(left, mid, node << 1, L, R, Mod);
    Update(mid + 1, right, node << 1 | 1, L, R, Mod);
    push_up(node);
    return;
  }
  int mid = (left + right) >> 1;
  if (L <= mid) {
    Update(left, mid, node << 1, L, R, Mod);
  }
  if (R > mid) {
    Update(mid + 1, right, node << 1 | 1, L, R, Mod);
  }
  push_up(node);
}
void Update_one(int left, int right, int node, int p, long long val) {
  if (left == right) {
    tree[node].mx = val;
    tree[node].sum = val;
    return;
  }
  int mid = (left + right) >> 1;
  if (p <= mid) {
    Update_one(left, mid, node << 1, p, val);
  } else {
    Update_one(mid + 1, right, node << 1 | 1, p, val);
  }
  push_up(node);
}
int main() {
  scanf("%d%d", &n, &m);
  build(1, n, 1);
  while (m--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      printf("%I64d\n", get_sum(1, n, 1, l, r));
    } else if (type == 2) {
      int l, r;
      long long Mod;
      scanf("%d%d%I64d", &l, &r, &Mod);
      Update(1, n, 1, l, r, Mod);
    } else {
      int p;
      long long val;
      scanf("%d%I64d", &p, &val);
      Update_one(1, n, 1, p, val);
    }
  }
  return 0;
}
