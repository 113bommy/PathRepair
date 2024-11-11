#include <bits/stdc++.h>
using namespace std;
const long long N = 100001;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  cout << max(a, max(b, c));
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
    cout << "\n";
  }
}
