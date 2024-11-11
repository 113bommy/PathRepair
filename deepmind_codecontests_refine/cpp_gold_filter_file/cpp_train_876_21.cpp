#include <bits/stdc++.h>
const int Maxn = 100010;
int n, m, ll, len;
int a[Maxn], b[Maxn], s[Maxn << 1], l[Maxn], r[Maxn];
int f[Maxn], g[Maxn];
inline void mmax(int& x, const int& y) {
  if (y > x) x = y;
}
inline int sum(const int& x, const int& y) { return s[y] - s[x - 1]; }
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (register int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    ++s[b[i]];
  }
  std::sort(a + 1, a + n + 1);
  std::sort(b + 1, b + m + 1);
  a[0] = -300000;
  a[n + 1] = 300000;
  for (register int i = 1; i <= n; ++i)
    if (a[i] == a[i - 1] + 1)
      l[i] = l[i - 1];
    else
      l[i] = i;
  for (register int i = n; i; --i)
    if (a[i] == a[i + 1] - 1)
      r[i] = r[i + 1];
    else
      r[i] = i;
  for (register int i = 1; i <= 200000; ++i) s[i] += s[i - 1];
  for (register int i = 1; i <= n; ++i) {
    mmax(f[i], f[i - 1] + sum(a[i], a[i]));
    mmax(g[i], f[i - 1] + sum(a[i], a[i]));
    for (register int j = 1; j <= m && (len = a[i] - b[j]) > 0; ++j)
      if (len < i) mmax(g[i], f[l[i - len] - 1] + sum(b[j], a[i]));
    mmax(f[i], g[i]);
    for (register int j = m; j && (len = b[j] - a[i]) >= 0; --j)
      if (len <= n - i) mmax(f[r[i + len]], g[i] + sum(a[i] + 1, b[j]));
  }
  printf("%d\n", f[n]);
}
