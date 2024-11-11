#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, k;
    cin >> x >> y >> k;
    if ((x % 2 == 0)) {
      if (y % 2) {
        if (k <= (y - 1) * x && (k % 2 == 0))
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        if (k % 2)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
      }
    } else {
      if (k > (y / 2) && (k - (y / 2)) % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
