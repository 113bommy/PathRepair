#include <bits/stdc++.h>
const int maxn = 5e4 + 1;
template <class T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x * 10) + (s & 15);
    s = getchar();
  }
  x *= f;
}
int n, a[maxn], m, l[maxn], r[maxn], f[maxn * 20], pre[maxn * 20], ans[maxn];
inline int qry(int l, int r) {
  if (l > r) std::swap(l, r);
  return pre[r] ^ pre[l - 1];
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= m; i++) read(l[i]), read(r[i]);
  for (int i = 1; i <= 1e6; i++) pre[i] = pre[i - 1] ^ i;
  for (int i = 1; i <= n; i++) {
    f[i] = a[i];
    for (int j = i + 1; j <= n; j++) {
      f[j] = std::max(f[j - 1], qry(a[i], a[j]));
    }
    for (int j = 1; j <= m; j++)
      if (i >= l[j] && i <= r[j]) ans[j] = std::max(ans[j], f[r[j]]);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
