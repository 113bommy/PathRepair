#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, k, t;
  cin >> n >> k >> m >> t;
  long long l = n;
  while (t--) {
    long long x;
    cin >> x;
    if (x == 1) {
      long long y;
      cin >> y;
      if (y > k) {
        cout << ++l << " " << k << "\n";
      } else {
        cout << ++l << " " << ++k << "\n";
      }
    } else {
      long long y;
      cin >> y;
      if (y >= k) {
        l = y;
        cout << l << " " << k << "\n";
      } else {
        l = l - y;
        k = k - y;
        cout << l << " " << k << "\n";
      }
    }
  }
}
