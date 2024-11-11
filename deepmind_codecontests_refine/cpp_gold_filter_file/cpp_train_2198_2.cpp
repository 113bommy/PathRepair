#include <bits/stdc++.h>
using namespace std;
long long t, a, ans;
signed main() {
  cin >> t;
  while (t--) {
    ans = 1;
    cin >> a;
    while (a != 0) {
      if (a % 2 != 0) {
        ans *= 2;
      }
      a = a / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
