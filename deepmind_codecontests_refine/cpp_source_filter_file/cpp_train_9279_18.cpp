#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
void solve() {
  long long n, x, y;
  cin >> n >> x >> y;
  if (x < n or y < n or (n - 1) + (y - n + 1) * (y - n + 1) < x) {
    cout << -1;
    return;
  }
  for (long long i = 0; i < n - 1; i++) cout << 1 << "\n";
  cout << y - n + 1;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
