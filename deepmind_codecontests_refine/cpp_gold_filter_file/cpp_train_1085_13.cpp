#include <bits/stdc++.h>
using namespace std;
int minn(int x1, int x2) { return x1 < x2 ? x1 : x2; }
int maxx(int x1, int x2) { return x1 > x2 ? x1 : x2; }
int abs(int x) {
  if (x >= 0)
    return x;
  else
    return -x;
}
int main() {
  int n, m, x, y, t;
  scanf("%d%d%d%d", &n, &x, &m, &y);
  if (n > m) {
    t = n;
    n = m;
    m = t;
  }
  if (y < x) {
    t = x;
    x = y;
    y = t;
  }
  int x1 = m - abs(x - y);
  if (x1 < 0) x1 = 0;
  int x2 = n - abs(x - y);
  if (x2 < 0) x2 = 0;
  long long ans = 1;
  int i, d = y - x;
  for (i = 1; i <= m; i++) {
    if ((y - i) > (x + n)) {
      ans++;
      continue;
    }
    if ((y - i) < (x - n)) {
      ans++;
      continue;
    }
    if (i <= d) {
      long long g = minn(n - (d - i), 2 * i - 1);
      if (g > 0)
        ans += 2 * g;
      else
        ans++;
    } else {
      long long g = minn(minn(minn(i + d - 1, n) - (i - d - 1), 2 * i - 1), n);
      if (g > 0)
        ans += 2 * g;
      else
        ans++;
    }
  }
  if (x - n < y - m) ans += maxx(minn(y - m - x + n, n), 0);
  printf("%I64d\n", ans);
  return 0;
}
