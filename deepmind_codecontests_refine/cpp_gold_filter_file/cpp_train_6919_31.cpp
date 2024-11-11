#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int a[N], b[N], c[N], d[N], y[N];
struct eve {
  int x, l, r, d;
  inline bool operator<(const eve &b) const { return x < b.x; }
} q[N];
int sum[N], tag[N];
inline void modify(int i, int l, int r, int L, int R, int d) {
  if (L <= l && r <= R)
    tag[i] += d;
  else {
    int mid = (l + r) >> 1;
    if (L < mid) modify((i << 1), l, mid, L, R, d);
    if (mid < R) modify(((i << 1) | 1), mid, r, L, R, d);
  }
  sum[i] = tag[i] ? y[r] ^ y[l] : sum[(i << 1)] ^ sum[((i << 1) | 1)];
}
int main() {
  int n = gi(), m = gi(), lim, i, k = gi(), len = 0, l, r, mid, ans = 0;
  for (lim = 0; 1 << lim <= k; lim++)
    ;
  for (i = 1; i <= m; i++)
    a[i] = gi(), b[i] = y[++len] = gi() - 1, c[i] = gi(),
    d[i] = y[++len] = gi();
  sort(y + 1, y + 1 + len);
  len = unique(y + 1, y + 1 + len) - y - 1;
  for (i = 1, n = 0; i <= m; i++) {
    for (l = 1, r = len; l != r;
         b[i] <= y[mid = (l + r) >> 1] ? r = mid : l = mid + 1)
      ;
    b[i] = l;
    for (l = 1, r = len; l != r;
         d[i] <= y[mid = (l + r) >> 1] ? r = mid : l = mid + 1)
      ;
    d[i] = l;
    q[++n] = (eve){a[i] - 1, b[i], d[i], 1};
    q[++n] = (eve){c[i], b[i], d[i], -1};
  }
  sort(q + 1, q + 1 + n);
  for (i = 1; i <= n; i++) {
    if (i != 1 && q[i].x != q[i - 1].x) ans ^= (q[i].x ^ q[i - 1].x) & sum[1];
    modify(1, 1, len, q[i].l, q[i].r, q[i].d);
  }
  puts(ans & ((1 << lim) - 1) ? "Hamed" : "Malek");
  return 0;
}
