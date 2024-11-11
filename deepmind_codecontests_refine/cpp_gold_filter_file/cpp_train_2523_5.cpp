#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y;
  cin >> x >> y;
  long long a, b;
  cin >> a >> b;
  long long ans = (x + y) * a;
  ans = min(ans, x * b + abs(x - y) * a);
  ans = min(ans, y * b + abs(x - y) * a);
  cout << ans << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n = 1;
  cin >> n;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
