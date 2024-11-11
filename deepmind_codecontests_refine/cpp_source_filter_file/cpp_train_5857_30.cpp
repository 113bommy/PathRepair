#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a >= b) {
      cout << (b * (b + 1)) / 2 << "\n";
    } else {
      a--;
      long long ans = 1 + ((a * (a + 1)) / 2);
      cout << ans << "\n";
    }
  }
}
