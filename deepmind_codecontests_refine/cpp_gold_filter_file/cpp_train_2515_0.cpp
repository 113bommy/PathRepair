#include <bits/stdc++.h>
inline long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
int sa[300010], sb[300010];
int sum[4000010], mxr[4000010], cnt;
inline void update(int x, int l, int r, const int& p, const int& d) {
  sum[x] += d;
  if (l == r) {
    mxr[x] = std::max(sum[x], 0);
    return;
  }
  if (p <= ((l + r) >> 1))
    update(x << 1, l, ((l + r) >> 1), p, d);
  else
    update(x << 1 | 1, ((l + r) >> 1) + 1, r, p, d);
  mxr[x] = std::max(mxr[x << 1 | 1], sum[x << 1 | 1] + mxr[x << 1]);
}
inline int query(int x, int l, int r, const int& L) {
  if (L <= l) return mxr[x];
  if (L <= ((l + r) >> 1)) {
    int _ls = query(x << 1, l, ((l + r) >> 1), L), _rs = mxr[x << 1 | 1];
    return std::max(_rs, sum[x << 1 | 1] + _ls);
  } else
    return query(x << 1 | 1, ((l + r) >> 1) + 1, r, L);
}
int main() {
  int n = gi(), m = gi(), N = 1000000;
  for (int i = 1; i <= n; ++i) sa[i] = gi(), update(1, 1, N, sa[i], 1);
  for (int i = 1; i <= m; ++i) sb[i] = gi(), update(1, 1, N, sb[i], -1);
  int q = gi(), op, p, x;
  for (int i = 1; i <= q; ++i) {
    op = gi(), p = gi(), x = gi();
    if (op == 1) {
      update(1, 1, N, sa[p], -1);
      update(1, 1, N, sa[p] = x, 1);
    } else {
      update(1, 1, N, sb[p], 1);
      update(1, 1, N, sb[p] = x, -1);
    }
    int l = 0, r = N, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (query(1, 1, N, mid + 1) > 0)
        l = mid + 1;
      else
        r = mid;
    }
    printf("%d\n", l ? l : -1);
  }
  return 0;
}
