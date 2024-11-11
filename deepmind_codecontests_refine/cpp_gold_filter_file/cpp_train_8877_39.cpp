#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = max(a + b, c + d);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
