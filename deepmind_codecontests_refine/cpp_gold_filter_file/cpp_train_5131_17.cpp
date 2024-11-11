#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 8e5 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 1e8 + 7;
const double eps = 1e-8;
const long double pi = acos(-1.0L);
long long read() {
  long long x = 0, t = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') t = -1;
  while (isdigit(ch)) {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * t;
}
long long a, b, c, d;
long long cal(long long k) {
  long long res = 0;
  long long x = max(k - c / d, 1LL);
  res = k * a -
        ((x - 1) * c + (-(x + k) * (k - x + 1) / 2 + (k - x + 1) * k) * d) * b;
  return res;
}
void solve() {
  a = read(), b = read(), c = read(), d = read();
  if (a > b * c)
    printf("-1\n");
  else {
    long long l = 1, r = 1e6 + 5, ans = 0;
    while (l <= r) {
      long long m1 = l + (r - l) / 3;
      long long m2 = r - (r - l) / 3;
      long long t1 = cal(m1), t2 = cal(m2);
      ans = max(ans, t1);
      ans = max(ans, t2);
      if (t1 < t2)
        l = m1 + 1;
      else
        r = m2 - 1;
    }
    printf("%lld\n", ans);
  }
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}
