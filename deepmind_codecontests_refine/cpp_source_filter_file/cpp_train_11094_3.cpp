#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001000];
long long a[1000100];
struct node {
  int lhill, maxval, rhill;
} tree[6 * 500000];
int sig(int x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
void calc(int cur, int l, int r) {
  int m = (l + r) / 2;
  int dc = cur * 2;
  tree[cur].maxval = max(tree[dc].maxval, tree[dc + 1].maxval);
  if (!a[m] || !a[m + 1] || sig(a[m]) < sig(a[m + 1])) {
    tree[cur].lhill = tree[dc].lhill;
    tree[cur].rhill = tree[dc + 1].rhill;
  } else {
    tree[cur].maxval =
        max(tree[cur].maxval, tree[dc].rhill + tree[dc + 1].lhill);
    if (tree[dc].maxval == m - l + 1) {
      tree[cur].lhill = tree[dc].lhill + tree[dc + 1].lhill;
    } else {
      tree[cur].lhill = tree[dc].lhill;
    }
    if (tree[dc + 1].maxval == r - m) {
      tree[cur].rhill = tree[dc + 1].rhill + tree[dc].rhill;
    } else {
      tree[cur].rhill = tree[dc + 1].rhill;
    }
  }
}
void build(int cur, int l, int r) {
  if (l == r) {
    int x = !!a[l];
    tree[cur] = {x, x, x};
  } else {
    int m = (l + r) / 2;
    int dc = cur * 2;
    build(dc, l, m);
    build(dc + 1, m + 1, r);
    calc(cur, l, r);
  }
}
void update(int cur, int l, int r, int pos, int val) {
  if (l == r) {
    a[pos] += val;
    int x = !!a[l];
    tree[cur] = {x, x, x};
  } else {
    int m = (l + r) / 2;
    int dc = cur * 2;
    if (pos <= m) {
      update(dc, l, m, pos, val);
    } else {
      update(dc + 1, m + 1, r, pos, val);
    }
    calc(cur, l, r);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  for (int i = 0; i < n - 1; i++) {
    a[i] = arr[i + 1] - arr[i];
  }
  if (n > 1) build(1, 0, n - 2);
  int m;
  scanf("%d", &m);
  while (m--) {
    int l, r, d;
    scanf("%d %d %d", &l, &r, &d);
    if (n == 1) {
      puts("1");
      continue;
    }
    if (l != 1) update(1, 0, n - 2, l - 2, d);
    if (r != n) update(1, 0, n - 2, r - 1, -d);
    printf("%d\n", tree[1].maxval + 1);
  }
  return 0;
}
