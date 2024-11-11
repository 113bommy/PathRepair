#include <bits/stdc++.h>
using namespace std;
const int M = 400005;
const int MOD = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, ans, a[M], b[M], p[M], dp[M], f[M], vis[M], suf[M];
int cmp(int x, int y) { return a[x] < a[y]; }
int lowbit(int x) { return x & (-x); }
void ins(int x, int c) {
  for (int i = x; i <= 2 * n; i += lowbit(i)) f[i] = (f[i] + c) % MOD;
}
int ask(int x) {
  int res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) res = (res + f[i]) % MOD;
  return res;
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read(), p[i] = i;
  m = read();
  for (int i = 1; i <= m; i++) vis[read()] = 1;
  sort(p + 1, p + 1 + n, cmp);
  for (int i = n; i >= 1; i--) {
    if (vis[p[i]]) suf[i] = b[p[i]];
    suf[i] = max(suf[i], suf[i + 1]);
  }
  for (int i = 1; i <= n; i++)
    if (suf[i] > b[p[i]]) vis[p[i]] = 1;
  for (int i = n; i >= 1; i--) {
    dp[i] = ask(b[p[i]]) + 1;
    ins(b[p[i]], dp[i]);
    if (vis[p[i]]) ans = (ans + dp[i]) % MOD;
  }
  printf("%d\n", ans);
}
