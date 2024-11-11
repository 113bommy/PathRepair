#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int n, q, k, tot;
int a[100100];
int T[3000100], lson[3000100], rson[3000100], c[3000100];
int build(int l, int r) {
  int root = tot++;
  c[root] = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    lson[root] = build(l, mid);
    rson[root] = build(mid + 1, r);
  }
  return root;
}
int update(int root, int pos, int val) {
  int newroot = tot++, tmp = newroot;
  c[newroot] = c[root] + val;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      lson[newroot] = tot++;
      rson[newroot] = rson[root];
      newroot = lson[newroot];
      root = lson[root];
      r = mid;
    } else {
      rson[newroot] = tot++;
      lson[newroot] = lson[root];
      newroot = rson[newroot];
      root = rson[root];
      l = mid + 1;
    }
    c[newroot] = c[root] + val;
  }
  return tmp;
}
int query(int root, int pos) {
  int ret = 0;
  int l = 1, r = n;
  while (l != r) {
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      ret += c[rson[root]];
      root = lson[root];
      r = mid;
    } else {
      root = rson[root];
      l = mid + 1;
    }
  }
  ret += c[root];
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  T[0] = build(1, n);
  for (int i = 1; i <= n; ++i) {
    int tmp = a[i];
    g[tmp].push_back(i);
    if ((int)g[tmp].size() > k) {
      int las = g[tmp][g[tmp].size() - 1 - k];
      int tx = update(T[i - 1], las, -1);
      T[i] = update(tx, i, 1);
    } else {
      T[i] = update(T[i - 1], i, 1);
    }
  }
  int ans = 0;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + ans) % n + 1;
    r = (r + ans) % n + 1;
    if (l > r) swap(l, r);
    ans = query(T[r], l);
    printf("%d\n", ans);
  }
  return 0;
}
