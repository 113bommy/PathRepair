#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, tot, x;
int T[N], lson[N * 20], rson[N * 20], c[N * 20];
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
int query(int x, int y, int pos) {
  int ans = 0, l = 1, r = n;
  while (l <= r) {
    if (r == pos) return ans + c[y] - c[x];
    if (l >= r) return ans;
    int mid = (l + r) / 2;
    if (pos <= mid) {
      x = lson[x], y = lson[y];
      r = mid;
    } else {
      ans += c[lson[y]] - c[lson[x]];
      x = rson[x], y = rson[y];
      l = mid + 1;
    }
  }
}
long long solve(int l, int r, int d, int u) {
  if (l > r || d > u) return 0;
  int x = query(T[l - 1], T[r], u) - query(T[l - 1], T[r], d - 1);
  return 1LL * x * (x - 1) / 2;
}
int main() {
  scanf("%d%d", &n, &q);
  T[0] = build(1, n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    T[i] = update(T[i - 1], x, 1);
  }
  while (q--) {
    int l, r, d, u;
    scanf("%d%d%d%d", &l, &d, &r, &u);
    long long ans = 1LL * n * (n - 1) / 2;
    ans -= solve(1, l - 1, 1, n);
    ans -= solve(r + 1, n, 1, n);
    ans -= solve(1, n, u + 1, n);
    ans -= solve(1, n, 1, d - 1);
    ans += solve(1, l - 1, u + 1, n);
    ans += solve(1, l - 1, 1, d - 1);
    ans += solve(r + 1, n, u + 1, n);
    ans += solve(r + 1, n, 1, d - 1);
    printf("%lld\n", ans);
  }
  return 0;
}
