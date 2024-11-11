#include <bits/stdc++.h>
using namespace std;
int tree[1000005], b[1000005], n, K;
long long ans = 0;
void add(int x, int y) {
  for (; x < 1000005; x += (x & -x)) tree[x] += y;
}
int query(int x) {
  int ret = 0;
  for (; x; x -= (x & -x)) ret += tree[x];
  return ret;
}
struct A {
  int x, r, q, L, R;
} a[1000005 << 1];
int cmp(A x, A y) { return x.r > y.r; }
int cmpp(A x, A y) { return x.q < y.q; }
void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  cdq(l, mid), cdq(mid + 1, r);
  int ll = l, rr = l - 1;
  for (int i = mid + 1; i <= r; i++) {
    while (ll <= mid && a[i].q - a[ll].q > K) add(a[ll].x, -1), ll++;
    while (rr < mid && a[rr + 1].q - a[i].q <= K) rr++, add(a[rr].x, 1);
    ans += query(a[i].R) - query(a[i].L - 1);
  }
  for (int i = ll; i <= rr; i++) add(a[i].x, -1);
  sort(a + l, a + r + 1, cmpp);
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q), b[i] = a[i].x;
  sort(b + 1, b + 1 + n);
  int m = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i].L = lower_bound(b + 1, b + 1 + m, a[i].x - a[i].r) - b;
    a[i].R = upper_bound(b + 1, b + 1 + m, a[i].x + a[i].r) - b - 1;
    a[i].x = lower_bound(b + 1, b + 1 + m, a[i].x) - b;
  }
  sort(a + 1, a + 1 + n, cmp);
  cdq(1, n);
  printf("%lld", ans);
  return 0;
}
