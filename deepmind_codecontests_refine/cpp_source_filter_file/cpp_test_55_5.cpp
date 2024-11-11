#include <bits/stdc++.h>
using namespace std;
void _debug() { cerr << '\n'; }
template <typename A, typename... B>
void _debug(A a, B... b) {
  cerr << a << ' ', _debug(b...);
}
const int oo = 2000000000;
const int mod = 1e9 + 7;
long long fp(long long v, long long x) {
  long long res = 1;
  while (x) {
    if (x & 1) res = res * v % mod;
    v = v * v % mod;
    x >>= 1;
  }
  return res % mod;
}
void solve() {
  long long h;
  cin >> h;
  long long sum = 0;
  sum = (1 << h) - 2;
  long long ans = fp(4, sum) % mod;
  ans = ans * 6 % mod;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) solve();
}
