#include <bits/stdc++.h>
using namespace std;
long long n, m, i, a[100002], d[100002], f[100002], g[100002], s[100002],
    b[100002], val[100002], c[100002], top, ans = 1 << 30;
long long read() {
  char c = getchar();
  long long w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
long long lowbit(long long x) { return x & (-x); }
void add(long long x, long long y) {
  for (long long i = x; i >= 1; i -= lowbit(i)) c[i] = max(c[i], y);
}
long long ask(long long x) {
  long long ans = -1;
  for (long long i = x; i <= m; i += lowbit(i)) ans = max(ans, c[i]);
  return ans;
}
signed main() {
  n = read();
  for (i = 0; i <= n + 1; i++) a[i] = read();
  for (i = 1; i <= n; i++) d[i] = read();
  for (i = 1; i <= n; i++) {
    while (top && a[i] > a[f[s[top]]] + 2 * d[s[top]]) top--;
    f[i] = s[top];
    while (top && a[f[i]] + 2 * d[i] >= a[f[s[top]]] + 2 * d[s[top]]) top--;
    s[++top] = i;
  }
  top = 0;
  s[0] = n + 1;
  for (i = n; i >= 1; i--) {
    while (top && a[i] > a[f[s[top]]] + 2 * d[s[top]]) top--;
    g[i] = s[top];
    while (top && a[f[i]] + 2 * d[i] >= a[f[s[top]]] + 2 * d[s[top]]) top--;
    s[++top] = i;
  }
  for (i = 1; i <= n; i++) {
    if (a[g[i]] - a[f[i]] <= 2 * d[i]) {
      puts("0");
      return 0;
    }
    ans = min(ans, a[g[i]] - a[f[i]]);
  }
  for (i = 1; i <= n; i++) {
    if (a[i] - a[f[i]] < 2 * d[i]) b[i] = a[f[i]] + 2 * d[i], val[++m] = b[i];
  }
  sort(val + 1, val + m + 1);
  m = unique(val + 1, val + m + 1) - val - 1;
  for (i = 1; i <= n; i++) {
    if (a[g[i]] - a[i] < 2 * d[i]) {
      long long pos =
          lower_bound(val + 1, val + m + 1, a[g[i]] - 2 * d[i]) - val;
      long long tmp = ask(pos);
      if (tmp != -1) ans = min(ans, a[i] - tmp);
    }
    if (a[i] - a[f[i]] < 2 * d[i]) {
      long long pos = lower_bound(val + 1, val + m + 1, b[i]) - val;
      add(pos, a[i]);
    }
  }
  for (i = 1; i <= n; i++) {
    if (f[i] == 0 && a[g[i]] - a[i] < 2 * d[i]) ans = min(ans, a[i]);
    if (g[i] == n + 1 && a[i] - a[f[i]] < 2 * d[i])
      ans = min(ans, a[n + 1] - a[i]);
  }
  printf("%.8lf\n", 0.5 * ans);
  return 0;
}
