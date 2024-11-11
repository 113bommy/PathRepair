#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  if (f) return -sum;
  return sum;
}
const int N = 300005;
const int orz = 2000000000;
const int otz = 1000000000;
int n, m, tp[N], a[N], b[N], c[N], mx[N];
bool hav[N];
namespace Seg1 {
int t[N * 4], at, v;
inline void build(int p, int l, int r) {
  if (l == r) {
    t[p] = mx[l] = orz;
    return;
  }
  int mid = (l + r) >> 1;
  t[p] = orz;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}
inline void ch(int p, int l, int r, int L, int R) {
  if (l == L && r == R) {
    t[p] = min(t[p], v);
    return;
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    ch(p << 1, l, mid, L, R);
  else if (L > mid)
    ch(p << 1 | 1, mid + 1, r, L, R);
  else
    ch(p << 1, l, mid, L, mid), ch(p << 1 | 1, mid + 1, r, mid + 1, R);
}
inline void dn(int p, int l, int r) {
  v = min(v, t[p]);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (at <= mid)
    dn(p << 1, l, mid);
  else
    dn(p << 1 | 1, mid + 1, r);
}
inline void formax(int k) {
  v = orz;
  at = k;
  dn(1, 1, n);
  mx[k] = v;
  hav[k] = 1;
}
}  // namespace Seg1
namespace Seg2 {
int t[N * 4], at, v;
inline void build(int p, int l, int r) {
  if (l == r) {
    t[p] = mx[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  t[p] = max(t[p << 1], t[p << 1 | 1]);
}
inline void ch(int p, int l, int r) {
  if (l == r) {
    t[p] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (at <= mid)
    ch(p << 1, l, mid);
  else
    ch(p << 1 | 1, mid + 1, r);
  t[p] = max(t[p << 1], t[p << 1 | 1]);
}
inline int ask(int p, int l, int r, int L, int R) {
  if (l == L && r == R) return t[p];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return ask(p << 1, l, mid, L, R);
  else if (L > mid)
    return ask(p << 1 | 1, mid + 1, r, L, R);
  else
    return max(ask(p << 1, l, mid, L, mid),
               ask(p << 1 | 1, mid + 1, r, mid + 1, R));
}
}  // namespace Seg2
inline void output() {
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", mx[i] == orz ? 0 : mx[i]);
  exit(0);
}
int up[32], g[N], cs[N], tot;
int main() {
  int i, j, x;
  n = read();
  m = read();
  Seg1::build(1, 1, n);
  for (i = 1; i <= m; i++) {
    tp[i] = read();
    a[i] = read();
    b[i] = read();
    if (tp[i] == 1)
      Seg1::v = c[i] = read(), Seg1::ch(1, 1, n, a[i], b[i]);
    else if (!hav[a[i]])
      Seg1::formax(a[i]);
  }
  for (i = 1; i <= n; i++)
    if (!hav[i]) Seg1::formax(i);
  Seg2::build(1, 1, n);
  for (i = 1; i <= m; i++) {
    if (tp[i] == 2)
      Seg2::v = b[i], Seg2::at = a[i], Seg2::ch(1, 1, n);
    else if (Seg2::ask(1, 1, n, a[i], b[i]) != c[i]) {
      puts("NO");
      return 0;
    }
  }
  for (i = 0; i <= 29; i++) up[i] = (1 << i) - 1;
  int FREE = 0, ans = 0;
  for (i = 1; i <= n; i++) {
    if (mx[i] != orz)
      g[++tot] = mx[i];
    else if (!FREE)
      FREE = i;
    else
      mx[FREE] = otz, mx[i] = up[29], output();
  }
  sort(g + 1, g + tot + 1);
  tot = unique(g + 1, g + tot + 1) - g - 1;
  for (i = 1; i <= n; i++) {
    if (i == FREE) continue;
    x = lower_bound(g + 1, g + tot + 1, mx[i]) - g;
    if ((++cs[x]) == 2)
      for (j = 29; j >= 0; j--)
        if (up[j] <= mx[i]) {
          mx[i] = up[j];
          break;
        }
  }
  if (FREE) {
    x = mx[FREE] = 0;
    for (i = 1; i <= n; i++) ans |= mx[i];
    for (i = 29; i >= 0; i--)
      if (!((ans >> i) & 1) && ((x | (1 << i)) <= otz)) x |= (1 << i);
    mx[FREE] = x;
  }
  output();
  return 0;
}
