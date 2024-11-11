#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int a[200010], b[200010];
int tree[200010 * 34], ls[200010 * 34], rs[200010 * 34], rt[200010], cnt;
void build(int l, int r, int &o) {
  if (!o) o = ++cnt;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, ls[o]), build(mid + 1, r, rs[o]);
}
void add(int l, int r, int &o, int las, int x, int y) {
  if (!o) o = ++cnt;
  if (l == r) {
    tree[o] = tree[las] + 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    rs[o] = rs[las], add(l, mid, ls[o], ls[las], x, y);
  else
    ls[o] = ls[las], add(mid + 1, r, rs[o], rs[las], x, y);
  tree[o] = tree[ls[o]] + tree[rs[o]];
}
int query(int nowl, int nowr, int o1, int o2, int x) {
  if (nowl == nowr) return nowl <= x ? (tree[o2] - tree[o1]) : 0;
  int mid = (nowl + nowr) >> 1;
  if (x <= mid)
    return query(nowl, mid, ls[o1], ls[o2], x);
  else
    return tree[ls[o2]] - tree[ls[o1]] +
           query(mid + 1, nowr, rs[o1], rs[o2], x);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + n + 1);
  int len = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
  build(1, len, rt[0]);
  for (int i = 1; i <= n; i++) add(1, len, rt[i], rt[i - 1], a[i], 1);
  for (int k = 1; k < n; k++) {
    int h = (n + k - 2) / k;
    int ans = 0;
    for (int j = 1; j <= h; j++) {
      int g1 = k * (j - 1) + 2, g2 = min(k * j + 1, n);
      if (a[j] != 1) ans += query(1, len, rt[g1 - 1], rt[g2], a[j] - 1);
    }
    printf("%d%c", ans, k == n - 1 ? '\n' : ' ');
  }
  return 0;
}
