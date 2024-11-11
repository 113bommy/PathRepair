#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e5 + 5;
void solve() {
  long long k;
  cin >> k;
  long long first = pow(2, 17);
  cout << 2 << ' ' << 3 << '\n';
  cout << first + k << ' ' << first << ' ' << 0 << '\n'
       << k << " " << first + k << " " << k;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
