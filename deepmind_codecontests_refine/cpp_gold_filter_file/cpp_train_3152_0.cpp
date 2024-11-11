#include <bits/stdc++.h>
using namespace std;
long long a, b, x, y, n;
long long f(long long a, long long b, long long x, long long y, long long n) {
  if (a - x > n) return (a - n) * b;
  n -= a - x;
  a = x;
  if (b - y <= n)
    b = y;
  else
    b -= n;
  return a * b;
}
void solve() {
  cin >> a >> b >> x >> y >> n;
  cout << min(f(a, b, x, y, n), f(b, a, y, x, n)) << '\n';
}
void solve(bool testcase) {
  long long t;
  cin >> t;
  while (t--) solve();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve(true);
  return 0;
}
