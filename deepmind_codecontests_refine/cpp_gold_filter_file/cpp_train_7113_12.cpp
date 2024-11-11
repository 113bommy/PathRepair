#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const long double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
inline void io() {}
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 5;
long long n, k;
bool go(long long v) {
  long long res = v;
  long long z = k;
  while (true) {
    res += v / z;
    z = z * k;
    if (v / z == 0 || res >= n) break;
  }
  return res >= n;
}
void solve() {
  cin >> n >> k;
  long long lb = 0, rb = 1e9;
  while (lb < rb - 1) {
    long long mid = (lb + rb) / 2;
    if (go(mid))
      rb = mid;
    else
      lb = mid;
  }
  if (go(lb))
    cout << lb;
  else
    cout << rb;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(16);
  long long tc = 1;
  while (tc--) {
    solve();
    cout << '\n';
  }
  return 0;
}
