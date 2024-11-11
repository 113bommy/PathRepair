#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, gcd, lcm, ans;
  cin >> n >> x;
  ans = x;
  for (int i = 2; i <= n; i++) {
    cin >> y;
    if (ans < y) {
      for (lcm = 1; (lcm % ans) > 0 || (lcm % y) > 0; lcm++) {
        lcm == lcm;
      }
      gcd = (ans * y) / lcm;
      if (gcd == 1 && ans != 1) {
        ans = 1;
      } else
        ans = gcd;
    } else if (ans > y) {
      for (lcm = 1; (lcm % ans) > 0 || (lcm % y) > 0; lcm++) {
        lcm == lcm;
      }
      gcd = (ans * y) / lcm;
      if (gcd == 1 && y != 1)
        ans %= y;
      else if (y == 1) {
        ans = 1;
      } else
        ans = gcd;
    }
  }
  ans *= n;
  cout << ans << endl;
  return 0;
}
