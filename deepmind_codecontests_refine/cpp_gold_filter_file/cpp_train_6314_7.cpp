#include <bits/stdc++.h>
using namespace std;
long long step[100];
bool check(long long n, long long x, int y) {
  return ((1ll << y) - 1) * (2 * n - 2 * x + 1) < 2 * x - 1;
}
int main() {
  long long n;
  int q;
  while (~scanf("%I64d%d", &n, &q)) {
    long long l = 1;
    int sz = 0;
    for (sz = 0; sz < 64 && l <= n; sz++) {
      long long m = (l + n) / 2;
      if (check(n, m, sz + 1))
        step[sz] = m - 1;
      else
        step[sz] = m;
      l = step[sz] + 1;
      if (sz == 0 && step[sz] == 1 || sz > 0 && step[sz] - step[sz - 1] == 1) {
        sz++;
        break;
      }
    }
    while (q--) {
      long long p;
      scanf("%I64d", &p);
      int flag = 1;
      for (int y = 0; y < sz && flag; y++) {
        long long x, c = (1ll << y) - 1;
        if (2 * n - p <= c + 1)
          x = n;
        else {
          unsigned long long nn = n, cc = c;
          x = n + 1 - ((2 * nn + cc + 1 - p) / (2 * cc + 2));
        }
        if (y == 0 && x > 0 && x <= step[y] ||
            y > 0 && x > step[y - 1] && x <= step[y]) {
          if (2 * x - 1 - (2 * n - 2 * x + 1) * ((1ll << y) - 1) == p) {
            printf("%I64d\n", x), flag = 0;
          }
        }
      }
      if (flag) {
        long long x = step[sz - 1] + 1, y = sz;
        while (x < n && y < 64) {
          if (2 * x - 1 - (2 * n - 2 * x + 1) * ((1ll << y) - 1) == p) break;
          x++, y++;
        }
        printf("%I64d\n", x);
      }
    }
  }
  return 0;
}
