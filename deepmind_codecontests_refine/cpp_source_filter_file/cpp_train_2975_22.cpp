#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
void solve() {
  long long a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << 3 << "\n";
  cout << e + c - a << " " << f + d - b << "\n";
  cout << e + a - c << " " << f + b - d << "\n";
  cout << a + c - e << " " << b + d + f << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
