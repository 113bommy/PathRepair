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
double a[100005], X, Y;
double sqr(double x) { return x * x; }
double tonplus1(int p) { return sqrt(sqr(Y) + sqr(X - a[p])); }
double st;
double gonplus1(int l, int r) {
  return a[r] - a[l] +
         (min(abs(st - a[l]) + tonplus1(r), abs(st - a[r]) + tonplus1(l)));
}
double saikou(int l, int r) { return a[r] - a[l] + (tonplus1(r), tonplus1(l)); }
double ans = 200000000000000000ll;
int main() {
  long long i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  int K;
  cin >> n >> K;
  for (i = 1; i <= n; i++) cin >> a[i];
  cin >> X >> Y;
  st = a[K];
  sort(a + 1, a + n + 1);
  if (K == n + 1) {
    ans = saikou(1, n);
  } else {
    ans = min(ans, gonplus1(1, n));
    for (i = 1; i <= n; i++) {
      if (i != 1) ans = min(ans, gonplus1(1, i - 1) + saikou(i, n));
      if (i != 1) ans = min(ans, saikou(1, i - 1) + gonplus1(i, n));
    }
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}
