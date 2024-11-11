#include <bits/stdc++.h>
const int SIZE = 2e5 + 50;
long long p[SIZE], a[SIZE];
long long arr[SIZE];
namespace SegTree {
struct node {
  long long l, r;
  long long minn;
} T[SIZE * 3];
long long lazy[SIZE * 3];
void build(long long l, long long r, int rt) {
  T[rt].l = l;
  T[rt].r = r;
  if (l == r) {
    T[rt].minn = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  T[rt].minn = 0;
}
void update(long long L, long long R, long long x, int rt) {
  if (R < L) return;
  if (L <= T[rt].l && R >= T[rt].r) {
    T[rt].minn += x;
    lazy[rt] += x;
    return;
  }
  long long mid = (T[rt].l + T[rt].r) >> 1;
  if (lazy[rt]) {
    T[rt << 1].minn += lazy[rt];
    T[rt << 1 | 1].minn += lazy[rt];
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
  if (L <= mid) update(L, R, x, rt << 1);
  if (R > mid) update(L, R, x, rt << 1 | 1);
  T[rt].minn = std::min(T[rt << 1].minn, T[rt << 1 | 1].minn);
}
};  // namespace SegTree
int main() {
  long long n;
  scanf("%lld", &n);
  SegTree::build(1, n, 1);
  for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    SegTree::update(p[i] + 1, n, a[i], 1);
  }
  long long ans = std::min(a[1], a[n]);
  for (int i = 1; i <= n; i++) {
    SegTree::update(p[i] + 1, n, (-1) * a[i], 1);
    SegTree::update((long long)1, p[i] - 1, a[i], 1);
    ans = std::min(ans, SegTree::T[1].minn);
  }
  printf("%lld\n", ans);
}
