#include <bits/stdc++.h>
using namespace std;
long long n, a[1000006], a1[1000006];
long long tree[4000006], lo[1000006], hi[1000006];
void upd(int x, int l, int r, int p) {
  if (l > r || p < l || p > r) return;
  if (l == p && r == p) {
    ++tree[x];
    return;
  }
  upd((x << 1), l, ((l + r) >> 1), p);
  upd((x << 1) + 1, ((l + r) >> 1) + 1, r, p);
  tree[x] = tree[x << 1] + tree[(x << 1) + 1];
}
void upd(int p) { upd(1, 0, n + 1, p); }
long long query(int x, int l, int r, int p, int q) {
  if (l > r || p < l || p > r) return 0;
  if (p <= l && r <= q) return tree[x];
  return query((x << 1), l, ((l + r) >> 1), p, q) +
         query((x << 1) + 1, ((l + r) >> 1) + 1, r, p, q);
}
long long query(int p, int q) { return query(1, 0, n + 1, p, q); }
int main() {
  long long ans = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    a1[i] = a[i];
  }
  sort(a1 + 1, a1 + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(a1 + 1, a1 + n + 1, a[i]) - a1;
  }
  for (int i = 1; i <= n; ++i) {
    hi[i] = query(a[i] + 1, n + 1);
    upd(a[i]);
  }
  memset(tree, 0, sizeof(tree));
  for (int i = n; i > 0; --i) {
    lo[i] = query(0, a[i] - 1);
    upd(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    ans += lo[i] * hi[i];
  }
  printf("%lld\n", ans);
  return 0;
}
