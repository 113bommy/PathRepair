#include <bits/stdc++.h>
using namespace std;
long long t, n, k, m;
int tree[800005];
int id[800005];
int ans[200005];
long long cnt = 0;
struct node {
  int l, r, t, id;
};
node a[200005];
int b[200005];
bool cmp(node a, node b) { return a.l == b.l ? a.id < b.id : a.l < b.l; }
void update(int l, int r, int p, int pos, int v, int b) {
  if (l == r) {
    tree[p] = v;
    id[p] = b;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    update(l, mid, p * 2, pos, v, b);
  } else {
    update(mid + 1, r, p * 2 + 1, pos, v, b);
  }
  tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
}
int query(int l, int r, int p, int pos, int rt) {
  if (tree[p] < rt) {
    return -1;
  }
  if (l == r) {
    if (tree[p] >= rt) {
      return id[p];
    } else {
      return -1;
    }
  }
  int ans = -1;
  int mid = (l + r) / 2;
  if (pos <= mid) {
    ans = query(l, mid, p * 2, pos, rt);
    if (ans == -1) {
      ans = query(mid + 1, r, p * 2 + 1, pos, rt);
    }
  } else {
    ans = query(mid + 1, r, p * 2 + 1, pos, rt);
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n + m; i++) {
    scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].t);
    b[i] = a[i].t;
    a[i].id = i;
  }
  sort(b + 1, b + n + m + 1);
  int len = unique(b + 1, b + n + m + 1) - b - 1;
  for (int i = 1; i <= n + m; i++) {
    a[i].t = lower_bound(b + 1, b + n + m + 1, a[i].t) - b;
  }
  sort(a + 1, a + m + n + 1, cmp);
  for (int i = 1; i <= n + m; i++) {
    if (a[i].id <= n) {
      update(1, len, 1, a[i].t, a[i].r, a[i].id);
    } else {
      ans[a[i].id - n] = query(1, len, 1, a[i].t, a[i].r);
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d ", ans[i]);
  }
}
