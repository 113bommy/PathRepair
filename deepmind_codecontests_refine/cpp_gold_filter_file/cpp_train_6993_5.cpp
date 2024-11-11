#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  int id;
  friend bool operator<(node p, node q) {
    if (p.val == q.val)
      return p.id < q.id;
    else
      return p.val < q.val;
  }
} tt[200000 + 5];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n, q;
int a[200000 + 5];
int minp[200000 + 5], maxp[200000 + 5];
struct segment_tree {
  struct node {
    int l;
    int r;
    int mark;
  } tree[200000 * 4 + 5];
  void build(int l, int r, int pos) {
    tree[pos].l = l;
    tree[pos].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
  }
  void push_down(int pos) {
    if (tree[pos].mark) {
      tree[pos << 1].mark = tree[pos << 1 | 1].mark = tree[pos].mark;
      tree[pos].mark = 0;
    }
  }
  void update(int L, int R, int pos) {
    if (L <= tree[pos].l && R >= tree[pos].r) {
      tree[pos].mark = 1;
      return;
    }
    push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (L <= mid) update(L, R, pos << 1);
    if (R > mid) update(L, R, pos << 1 | 1);
  }
  int query(int upos, int pos) {
    if (tree[pos].l == tree[pos].r) return tree[pos].mark;
    push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (upos <= mid)
      return query(upos, pos << 1);
    else
      return query(upos, pos << 1 | 1);
  }
} T;
int top = 0;
int s[200000 + 5];
int cnt[200000 + 5];
int main() {
  scanf("%d %d", &n, &q);
  memset(minp, 0x3f, sizeof(minp));
  int maxv = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    minp[a[i]] = min(minp[a[i]], i);
    maxp[a[i]] = max(maxp[a[i]], i);
    maxv = max(maxv, a[i]);
  }
  T.build(1, n, 1);
  for (int i = 1; i <= maxv; i++) {
    if (minp[i] != 0x3f3f3f3f && maxp[i] != 0 && maxp[i] - 1 >= minp[i]) {
      T.update(minp[i], maxp[i] - 1, 1);
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    if (!T.query(i, 1)) {
      s[++top] = i;
    }
  }
  int ans = 0;
  for (int i = 1; i <= top; i++) {
    int l = s[i - 1] + 1, r = s[i];
    int maxv = 0;
    for (int j = l; j <= r; j++) {
      cnt[a[j]]++;
      maxv = max(maxv, cnt[a[j]]);
    }
    ans += (r - l + 1) - maxv;
  }
  printf("%d\n", ans);
}
