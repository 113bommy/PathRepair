#include <bits/stdc++.h>
using namespace std;
const long long nmax = 1000000007;
void solve() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long ans = 0;
  if ((x2 - x1) > 0 && (y2 - y1) > 0) {
    ans += 2;
  }
  ans += abs(x2 - x1);
  ans += abs(y2 - y1);
  cout << ans << '\n';
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
