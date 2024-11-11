#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
void solve() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 0; i < 64; ++i) ans += n / pow(2, i);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
