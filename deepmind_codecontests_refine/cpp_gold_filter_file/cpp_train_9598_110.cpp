#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, a, b;
  cin >> n >> a >> b;
  cout << min(n - a, b + 1);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
