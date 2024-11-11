#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    if (r > n) {
      long long ans = (1 + n - 1) * (n - 1) / 2 + 1;
      cout << ans << "\n";
    } else {
      long long ans = (1 + r) * (r) / 2;
      cout << ans << "\n";
    }
  }
}
