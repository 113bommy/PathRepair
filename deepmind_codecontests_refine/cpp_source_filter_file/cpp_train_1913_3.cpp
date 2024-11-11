#include <bits/stdc++.h>
using namespace std;
const int N = 100001, MOD = 1000000007;
long long check(int x, int y, int k, int n) {
  int y_up0 = max(1, y - k);
  int y_up1 = max(y - 1, 1);
  int y_down0 = min(n, y + k);
  int y_down1 = min(n, y + 1);
  long long res = 1, a, b;
  res += min(x - 1, k);
  res += min(n - x, k);
  res += min(k, y - 1);
  res += min(k, n - y);
  int ymax;
  if (y != 1) {
    a = min(k - (y - y_up0), x - 1);
    b = k - (y - y_up1);
    ymax = 0;
    if (b > x - 1) ymax = y - k + (x - 1);
    if (!ymax)
      res += (a + b) * (y_up1 - y_up0 + 1) / 2;
    else
      res += (a + x - 1) * (ymax - y_up0 + 1) / 2 +
             (long long)(x - 1) * (y_up1 - ymax);
    a = min(k - (y - y_up0), n - x);
    b = k - (y - y_up1);
    ymax = 0;
    if (b > n - x) ymax = y - k + (n - x);
    if (!ymax)
      res += (a + b) * (y_up1 - y_up0 + 1) / 2;
    else
      res += (a + n - x) * (ymax - y_up0 + 1) / 2 +
             (long long)(n - x) * (y_up1 - ymax);
  }
  if (y != n) {
    a = min(k - (y_down0 - y), x - 1);
    b = k - (y_down1 - y);
    ymax = 0;
    if (b > x - 1) ymax = k - (x - 1) + y;
    if (!ymax)
      res += (a + b) * (y_down0 - y_down1 + 1) / 2;
    else
      res += (a + x - 1) * (y_down0 - ymax + 1) / 2 +
             (long long)(x - 1) * (ymax - y_down1);
    a = min(k - (y_down0 - y), n - x);
    b = k - (y_down1 - y);
    ymax = 0;
    if (b > n - x) ymax = k - (n - x) + y;
    if (!ymax)
      res += (a + b) * (y_down0 - y_down1 + 1) / 2;
    else
      res += (a + n - x) * (y_down0 - ymax + 1) / 2 +
             (long long)(n - x) * (ymax - y_down1);
  }
  return res;
}
int main(void) {
  int n, x, y;
  long long c;
  while (scanf("%d%d%d%I64d", &n, &x, &y, &c) != EOF) {
    if (n == 1 || c == 1)
      puts("0");
    else {
      int l = 1, r = n << 1, m;
      while (l <= r) {
        long long xx;
        if ((xx = check(x, y, m = (l + r) >> 1, n)) >= c)
          r = m - 1;
        else
          l = m + 1;
      }
      printf("%d\n", l);
    }
  }
}
