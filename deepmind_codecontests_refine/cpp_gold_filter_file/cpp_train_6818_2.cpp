#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
inline int gi() {
  char c = getchar();
  bool f = 1;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') c = getchar(), f = 0;
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return f ? sum : -sum;
}
int n, m, a[maxn], ans[maxn], vis[maxn], b[maxn], f[maxn], g[maxn], h[maxn],
    q[maxn];
int calc(int t, int x) {
  int p = lower_bound(b + 1, b + m + 1, x) - b - 1;
  return vis[p] = 1, ans[t] = b[p];
}
int main() {
  n = gi();
  for (int i = 1; i <= n; ++i) a[i] = gi(), f[i] = 2e9;
  ++n;
  f[n] = a[n] = 2e9;
  m = gi();
  for (int i = 1; i <= m; ++i) b[i] = gi();
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; ++i)
    if (~a[i]) {
      int p = lower_bound(f + 1, f + n + 1, a[i]) - f - 1;
      f[p + 1] = a[i];
      g[p + 1] = i;
      h[i] = p + 1;
      q[i] = g[p];
    } else {
      for (int j = m, p = n; j >= 1; --j) {
        while (f[p] >= b[j]) --p;
        f[p + 1] = b[j];
        g[p + 1] = i;
      }
    }
  for (int i = h[n], j = n, x = a[n]; i; --i) {
    if (~a[j]) {
      if (~a[q[j]])
        x = a[q[j]];
      else
        x = calc(q[j], a[j]);
      j = q[j];
    } else {
      int flg = 0;
      for (int k = j - 1; !flg && k; --k)
        if (~a[k] && h[k] == i - 1 && a[k] < x) x = a[j = k], flg = 1;
      if (flg) continue;
      for (int k = j - 1; !flg && k; --k)
        if (!~a[k]) x = calc(j = k, x), flg = 1;
    }
  }
  for (int i = 1, j = 1; i <= n; ++i)
    if (!~a[i]) {
      if (ans[i]) continue;
      while (vis[j]) ++j;
      vis[j] = 1;
      ans[i] = b[j];
    } else
      ans[i] = a[i];
  for (int i = 1; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
