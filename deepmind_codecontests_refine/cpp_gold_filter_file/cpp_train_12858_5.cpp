#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
long long n, m, ans;
const long long md = 1000000007;
inline void add(long long& x, long long y) {
  x += y;
  if (x >= md) x -= md;
}
inline long long qp(long long x, long long y) {
  long long rt = 1;
  for (; y; y >>= 1, (x *= x) %= md)
    if (y & 1) (rt *= x) %= md;
  return rt;
}
inline long long inv(long long x) { return qp(x, md - 2); }
inline void solve() {
  cin >> n >> m;
  long long inv_2 = inv(2);
  long long t = sqrt(n);
  for (long long i = 1; i <= min(m, t); ++i) add(ans, n % i);
  long long lst = t + 1;
  for (; (long long)(n / lst) == (long long)(n / t) and lst <= m;)
    add(ans, n % lst), ++lst;
  for (int i = t; i; --i) {
    if (lst > m) break;
    long long cur = n / i;
    cur = min(cur, m);
    long long beg = lst * i;
    long long end = cur * i;
    long long delta = cur - lst + 1;
    delta %= md;
    long long t1 = n % md * delta % md;
    t1 %= md;
    long long t2 = (beg + end) % md * delta % md;
    t2 *= inv_2;
    t2 %= md;
    long long t3 = t1 - t2;
    t3 %= md;
    if (t3 < 0) t3 += md;
    ans += t3;
    ans %= md;
    if (ans < 0) ans += md;
    lst = cur + 1;
    if (lst > m) break;
  }
  ans += max(0ll, m - n) % md * (n % md) % md;
  ans %= md;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  for (; T--;) solve();
}
