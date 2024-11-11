#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { a* b / gcd(a, b); }
const long long N = 1e9;
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
