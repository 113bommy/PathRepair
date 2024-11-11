#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
const double PI = acos((double)-1);
int ts, ts2, ts3, ts4;
int n, m;
long long gcd(long long x, long long y) {
  long long t;
  for (; y != 0;) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
long long a[500], ans = 200000000000000000ll;
int main() {
  long long i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (i = 2; i <= n; i++)
    for (j = i; j <= n; j++) {
      t1 = a[i - 1];
      t2 = 0;
      for (k = i; k <= j; k++) {
        t2 += t1 / a[k];
        t1 %= a[k];
      }
      if (t1 == 0)
        t1 = a[i - 1];
      else
        t1 = a[i - 1] - t1 + a[j];
      t3 = t1;
      t4 = 0;
      for (k = 1; k <= n; k++) {
        t4 += t3 / a[k];
        t3 %= a[k];
        if (t4 > t2) break;
      }
      if (t4 > t2 && t1 < ans) ans = t1;
    }
  printf("%I64d\n", ans == 200000000000000000ll ? -1 : ans);
  return 0;
}
