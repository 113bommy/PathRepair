#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = N << 3;
const int mod = 1e9 + 7;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int a[N], x[N], L[N], R[N];
int s[M], sum[M], abc[M], ab[M], cde[M], de[M];
int c[N], rt[N], lc[M], rc[M], tot;
inline void update(int i) {
  s[i] = s[lc[i]] + s[rc[i]];
  sum[i] = (sum[lc[i]] + sum[rc[i]] + 1LL * ab[lc[i]] * cde[rc[i]] +
            1LL * abc[lc[i]] * de[rc[i]]) %
           mod;
  abc[i] = (abc[lc[i]] + abc[rc[i]] + 1LL * ab[lc[i]] * s[rc[i]]) % mod;
  cde[i] = (cde[lc[i]] + cde[rc[i]] + 1LL * s[lc[i]] * de[rc[i]]) % mod;
  ab[i] = (ab[lc[i]] + ab[rc[i]]) % mod;
  de[i] = (de[lc[i]] + de[rc[i]]) % mod;
}
inline void modify(int &i, int l, int r, int k, int t) {
  if (!i) i = ++tot;
  if (l == r) {
    sum[i] = abc[i] = cde[i] = 0;
    if (t)
      s[i] = 1, ab[i] = L[k], de[i] = R[k];
    else
      s[i] = ab[i] = de[i] = 0;
  } else {
    int mid = (l + r) >> 1;
    k <= mid ? modify(lc[i], l, mid, k, t) : modify(rc[i], mid + 1, r, k, t);
    update(i);
  }
}
int main() {
  int n = gi(), i, len = 0, l, r, t, m, mid, ans = 0;
  for (i = 1; i <= n; i++) a[i] = x[i] = gi();
  sort(x + 1, x + 1 + n);
  len = unique(x + 1, x + 1 + n) - x - 1;
  for (i = 1; i <= n; a[i++] = l) {
    for (l = 1, r = len; l != r;
         a[i] <= x[mid = (l + r) >> 1] ? r = mid : l = mid + 1)
      ;
    for (t = l; t; t ^= t & -t) L[i] += c[t];
    for (t = l; t <= len; t += t & -t) c[t]++;
  }
  for (i = 1; i <= len; i++) c[i] = 0;
  for (i = n; i; i--) {
    for (t = a[i]; t; t ^= t & -t) R[i] += c[t];
    for (t = a[i]; t <= len; t += t & -t) c[t]++;
  }
  m = gi();
  for (i = 1; i <= n; i++) modify(rt[a[i]], 1, n, i, 1);
  for (i = 1; i <= len; i++) (ans += sum[rt[i]]) %= mod;
  while (m--) {
    t = gi(), i = gi();
    (ans -= sum[rt[a[i]]]) %= mod;
    modify(rt[a[i]], 1, n, i, t == 2);
    (ans += sum[rt[a[i]]]) %= mod;
    if (ans < 0) ans += mod;
    printf("%d\n", ans);
  }
  return 0;
}
