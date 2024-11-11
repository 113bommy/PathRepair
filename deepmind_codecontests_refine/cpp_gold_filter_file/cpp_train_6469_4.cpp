#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  long long data;
  long long Max, lazy;
  int flag;
};
node tree[N << 2];
long long a[N], k[N], t[N], sum[N];
void Merge(int root) {
  tree[root].data = tree[root << 1].data + tree[root << 1 | 1].data;
  tree[root].Max = max(tree[root << 1].Max, tree[root << 1 | 1].Max);
}
void creat(int root, int l, int r) {
  tree[root].lazy = 0;
  tree[root].flag = 0;
  if (l == r) {
    tree[root].data = a[l] - t[l - 1];
    tree[root].Max = tree[root].data;
    return;
  }
  int mid = (l + r) / 2;
  creat(root << 1, l, mid);
  creat(root << 1 | 1, mid + 1, r);
  Merge(root);
}
void pushdown(int root, int l, int r) {
  if (tree[root].flag) {
    int mid = (l + r) / 2;
    tree[root << 1].data = tree[root].lazy * (mid - l + 1);
    tree[root << 1 | 1].data = tree[root].lazy * (r - (mid + 1) + 1);
    tree[root << 1].Max = tree[root].lazy;
    tree[root << 1 | 1].Max = tree[root].lazy;
    tree[root << 1].lazy = tree[root].lazy;
    tree[root << 1 | 1].lazy = tree[root].lazy;
    tree[root].lazy = 0;
    tree[root << 1].flag = tree[root << 1 | 1].flag = 1;
    tree[root].flag = 0;
  }
}
int query(int root, int l, int r, int pos, long long v) {
  if (pos > r) return -1;
  if (l == r) {
    return l;
  }
  pushdown(root, l, r);
  int mid = (l + r) / 2;
  int ret = -1;
  if (pos <= mid && tree[root << 1].Max > v)
    ret = query(root << 1, l, mid, pos, v);
  if (ret == -1 && tree[root << 1 | 1].Max > v)
    ret = query(root << 1 | 1, mid + 1, r, pos, v);
  return ret;
}
void update(int root, int l, int r, int ul, int ur, long long v) {
  if (ul <= l && r <= ur) {
    tree[root].data = (r - l + 1) * v;
    tree[root].lazy = v;
    tree[root].Max = v;
    tree[root].flag = 1;
    return;
  }
  pushdown(root, l, r);
  int mid = (l + r) / 2;
  if (ul <= mid) update(root << 1, l, mid, ul, ur, v);
  if (ur > mid) update(root << 1 | 1, mid + 1, r, ul, ur, v);
  Merge(root);
}
long long get_data(int root, int l, int r, int pos) {
  if (l == r) {
    return tree[root].data;
  }
  pushdown(root, l, r);
  int mid = (l + r) / 2;
  if (pos <= mid)
    return get_data(root << 1, l, mid, pos);
  else
    return get_data(root << 1 | 1, mid + 1, r, pos);
}
long long query_sum(int root, int l, int r, int ul, int ur) {
  if (ul <= l && r <= ur) {
    return tree[root].data;
  }
  pushdown(root, l, r);
  int mid = (l + r) / 2;
  long long ret = 0;
  if (ul <= mid) ret += query_sum(root << 1, l, mid, ul, ur);
  if (ur > mid) ret += query_sum(root << 1 | 1, mid + 1, r, ul, ur);
  return ret;
}
void show(int root, int l, int r) {
  if (l == r) {
    printf("!%lld", tree[root].data);
    return;
  }
  pushdown(root, l, r);
  int mid = (l + r) / 2;
  show(root << 1, l, mid);
  show(root << 1 | 1, mid + 1, r);
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  k[0] = 0;
  t[0] = 0;
  sum[0] = 0;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%lld", &k[i]);
    t[i] = k[i] + t[i - 1];
    sum[i] = t[i] + sum[i - 1];
  }
  creat(1, 1, n);
  int m;
  scanf("%d", &m);
  char op[5];
  int pos, v;
  while (m--) {
    scanf("%s %d %d", op, &pos, &v);
    if (op[0] == 's') {
      long long ans = query_sum(1, 1, n, pos, v);
      if (pos >= 2)
        printf("%lld\n", ans + sum[v - 1] - sum[pos - 2]);
      else
        printf("%lld\n", ans + sum[v - 1]);
    } else {
      long long bi = get_data(1, 1, n, pos);
      int ret = query(1, 1, n, pos + 1, bi + v);
      if (ret == -1) {
        update(1, 1, n, pos, n, bi + v);
      } else
        update(1, 1, n, pos, ret - 1, bi + v);
    }
  }
  return 0;
}
