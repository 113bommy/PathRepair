#include <bits/stdc++.h>
using namespace std;
long long int x, y, p, q;
bool is(long long int mid) {
  long long int sub = q * mid, ans = p * mid, maxi;
  maxi = sub - y;
  if (ans >= x && ans <= x + maxi) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> p >> q;
    if (p == 1 && q == 1) {
      if (x == y)
        cout << 0 << endl;
      else
        cout << -1 << endl;
    } else if (p == 0) {
      if (x == 0)
        cout << 0 << endl;
      else
        cout << -1 << endl;
    } else {
      long long int sub = (q - y % q) % q;
      long long int l = (y + sub) / q, r = (1e18) / q, ans = r;
      while (l < r) {
        long long int mid = (l + r) / 2;
        if (is(mid))
          r = mid, ans = mid;
        else
          l = mid + 1;
      }
      cout << ans * q - y << endl;
    }
  }
  return 0;
}
