#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - '0';
    c = getchar();
  }
  return n * f;
}
int n, m, pin, a[1000 + 5], hd, tl, q[1000 << 3], dp[1000 << 3];
bool tg[1000 + 5];
int main() {
  register int i, x;
  m = read();
  n = read();
  for (i = 1; i <= n; ++i) tg[read()] = true;
  for (i = 0; i <= 1000; ++i)
    if (tg[i]) a[++pin] = i;
  hd = 1;
  tl = 0;
  for (i = 1; i <= pin; ++i) {
    a[i] -= m;
    q[++tl] = a[i];
    dp[a[i] + 1000] = 1;
  }
  while (hd <= tl) {
    x = q[hd++];
    if (!x) break;
    for (i = 1; i <= pin; ++i)
      if (x + a[i] <= 2 * 1000 && x + a[i] >= -1000 && !dp[x + a[i] + 1000]) {
        dp[x + a[i] + 1000] = dp[x + 1000] + 1;
        q[++tl] = x + a[i];
      }
  }
  printf("%d", dp[1000] ? dp[1000] : -1);
}
