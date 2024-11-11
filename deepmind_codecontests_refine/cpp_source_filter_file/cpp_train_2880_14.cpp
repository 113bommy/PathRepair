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
double sqr(double x) { return x * x; }
double a[1005];
int main() {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  cin >> n;
  u1 = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n / 2; i++)
    for (j = max((n - 1) / 2 + 1, i + 1); j <= n; j++) {
      u1 = max(u1, ((2 * j - n) * a[i] - (2 * i - n) * a[j]) / (2 * (i + j)));
    }
  printf("%.12lf\n", u1);
  return 0;
}
