#include <bits/stdc++.h>
int n, opt[6010], p[18000010];
inline void print() {
  for (register int i(1); i <= n; i++) {
    printf("%d ", opt[i]);
  }
  puts("");
  return;
}
signed main() {
  scanf("%d", &n), p[1] = 1;
  int m((n * n + n) >> 1);
  for (register int i(2); i <= m; i++) {
    if (!p[i]) {
      for (register int j(i << 1); j <= m; j += i) {
        p[j] = 1;
      }
    }
  }
  for (register int i(1); i <= n; i++) {
    opt[i] = 1;
  }
  if (!p[m]) {
    return print(), 0;
  }
  m & 1 && p[m - 2] ? opt[3] = 3, m -= 3 : 8;
  for (register int i(2); i <= n; i++) {
    if (!p[i] && !p[m - i]) {
      opt[i] = 2;
      break;
    }
  }
  return print(), 0;
}
