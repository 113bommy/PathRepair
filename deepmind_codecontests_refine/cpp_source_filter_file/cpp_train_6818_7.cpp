#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m, a[1000002], b[1000002], p[1000002], f[1000002], g[1000002],
    ans[1000002], l[1000002], v[1000002];
void get(int i, int k, int &x) {
  int o = lower_bound(b + 1, b + 1 + m, k) - b - 1;
  v[o] = 1;
  x = ans[i] = b[o];
}
int fd(int w) { return lower_bound(b + 1, b + m + 1, w) - b - 1; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), f[i] = inf;
  a[++n] = inf;
  f[n] = inf;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= n; ++i) {
    if (~a[i]) {
      int j = lower_bound(f + 1, f + n + 1, a[i]) - f - 1;
      l[i] = j + 1, p[i] = g[j], f[j + 1] = a[i], g[j + 1] = i;
    } else {
      for (int x = m, j = n; x; --x) {
        while (f[j] >= b[x]) --j;
        f[j + 1] = b[x], g[j + 1] = i;
      }
    }
  }
  int i = l[n], j = n, x = a[n];
  while (i--) {
    if (~a[j]) {
      if (~a[p[j]])
        j = p[j], x = a[j];
      else {
        int t = fd(a[j]);
        v[t] = 1, j = p[j], x = ans[j] = b[t];
      }
    } else {
      int flag = 0;
      for (int k = j - 1; k; --k)
        if (~a[k] && a[k] < x && l[k] == i - 1) {
          j = k, x = a[k];
          flag = 1;
          break;
        }
      if (flag) continue;
      for (int k = j - 1; k; --k)
        if (!~a[k]) {
          int t = fd(x);
          v[t] = 1, j = k, x = ans[j] = b[t];
          break;
        }
    }
  }
  for (int i = 1, j = 1; i <= n; ++i) {
    if (~a[i])
      ans[i] = a[i];
    else if (!ans[i]) {
      while (v[j]) ++j;
      v[j] = 1, ans[i] = b[j];
    }
  }
  for (int i = 1; i < n - 1; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n - 1]);
}
