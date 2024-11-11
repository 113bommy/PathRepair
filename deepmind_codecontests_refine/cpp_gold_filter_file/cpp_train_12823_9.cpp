#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  bool zf = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    zf = 1;
  else
    res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + c - '0';
  if (zf == 1) return -res;
  return res;
}
int n, m, dta[15][2005];
inline int calc() {
  int A = 0;
  for (register int i = 1; i <= n; ++i) {
    int s = -1;
    for (register int j = 1; j <= m; ++j) {
      s = max(s, dta[i][j]);
    }
    A += s;
  }
  return A;
}
signed main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (register int i = 1; i <= n; ++i) {
      for (register int j = 1; j <= m; ++j) {
        dta[i][j] = read();
      }
    }
    int ans = calc();
    double tt = 1e6;
    while (tt > 1e-10) {
      int x = rand() % m + 1;
      int t = dta[1][x];
      for (register int i = 1; i < n; ++i) {
        dta[i][x] = dta[i + 1][x];
      }
      dta[n][x] = t;
      int now = calc();
      if (now > ans) {
        ans = now;
      } else {
        if (exp((ans - now) / t) * RAND_MAX < rand()) {
          t = dta[n][x];
          for (register int i = n; i >= 2; --i) {
            dta[i][x] = dta[i - 1][x];
          }
          dta[1][x] = t;
        }
      }
      tt *= 0.999;
    }
    printf("%d\n", ans);
  }
  return 0;
}
