#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, m, l, r;
long long a[maxn], d[maxn], v;
struct ss {
  int l, r, lm, mm, rm;
} seg[maxn << 2];
inline int sign(long long x) { return !x ? 0 : x < 0 ? -1 : 1; }
void pushup(int x) {
  int l = seg[x].l, r = seg[x].r, m = (l + r) >> 1;
  seg[x].mm = max(seg[x << 1].mm, seg[x << 1 | 1].mm);
  seg[x].lm = seg[x << 1].lm;
  seg[x].rm = seg[x << 1 | 1].rm;
  if (!d[m] || !d[m + 1] || sign(d[m]) < sign(d[m + 1])) return;
  seg[x].mm = max(seg[x].mm, seg[x << 1].rm + seg[x << 1 | 1].lm);
  if (seg[x].lm == m - l + 1) seg[x].lm += seg[x << 1 | 1].lm;
  if (seg[x].rm == r - m) seg[x].rm += seg[x << 1].rm;
}
void build(int x, int l, int r) {
  seg[x].l = l, seg[x].r = r;
  if (l == r) {
    seg[x].lm = seg[x].mm = seg[x].rm = !!d[l];
    return;
  }
  int m = (l + r) >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  pushup(x);
}
void update(int x, int p, long long v) {
  int L = seg[x].l, R = seg[x].r;
  if (L == R) {
    d[p] += v;
    seg[x].lm = seg[x].mm = seg[x].rm = !!d[p];
    return;
  }
  int m = (L + R) >> 1;
  if (m >= p) update(x << 1, p, v);
  if (m < p) update(x << 1 | 1, p, v);
  pushup(x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 2; i <= n; ++i) d[i - 1] = a[i] - a[i - 1];
  --n;
  if (n) build(1, 1, n);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%lld", &l, &r, &v);
    if (!n) {
      puts("1");
      continue;
    }
    if (l != 1) update(1, l - 1, v);
    if (r != n + 1) update(1, r, v);
    printf("%d\n", seg[1].mm + 1);
  }
  return 0;
}
