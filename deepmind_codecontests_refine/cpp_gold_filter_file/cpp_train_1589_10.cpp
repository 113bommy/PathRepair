#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y >> n;
    if (n < x) {
      cout << y << endl;
      continue;
    } else {
      long long int res, ans;
      res = n / x;
      ans = (res * x) + y;
      if (ans > n) {
        while (res) {
          ans = (res * x) + y;
          if (ans % x == y && ans < n) {
            break;
          }
          res--;
        }
        cout << res * x + y << endl;
      } else {
        cout << res * x + y << endl;
      }
    }
  }
}
