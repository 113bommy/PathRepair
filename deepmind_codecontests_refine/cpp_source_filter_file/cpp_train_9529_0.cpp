#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int t = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = (ch == '-') ? -1 : f, ch = getchar();
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  return t * f;
}
int change(int n, int *a) {
  for (register int i = 0; i <= n; i++) {
    if (i == n && a[i] == -1) break;
    if (a[i] < 0) {
      int t = -a[i] + 1;
      t /= 2;
      a[i] += t << 1, a[i + 1] -= t;
    } else
      a[i + 1] += a[i] / 2, a[i] %= 2;
    if (i == n && a[i + 1] != 0) n++;
  }
  return n;
}
int a[201010], b[201010], tmp[201010];
int main() {
  int n = read(), m, K = read();
  for (register int i = 0; i <= n; i++) b[i] = a[i] = read();
  m = change(n, a);
  if (a[m] == -1) {
    memset(a, 0, sizeof(a));
    for (register int i = 0; i <= n; i++) a[i] = -b[i], b[i] = -b[i];
    m = change(n, a);
  }
  swap(n, m);
  int cnt = 0;
  for (register int i = 1; i <= n; i++)
    if (a[i] != 0) tmp[++cnt] = i;
  int st = tmp[1];
  if (st > m) st = m;
  long long num = 0;
  for (register int i = 1; i <= cnt; i++)
    if (tmp[i] - st <= 32)
      num += 1ll << (tmp[i] - st);
    else
      return puts("0") * 0;
  int ans = 0;
  for (register int i = st; i >= 0; i--) {
    if (num > 1ll << 32) break;
    long long t = b[i];
    t -= num;
    if (abs(t) <= K && (t != 0 || i != m)) ans++;
    num <<= 1;
  }
  printf("%d\n", ans);
  return 0;
}
