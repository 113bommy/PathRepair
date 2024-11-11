#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int nn = n - 2 * (x - 1);
  int mm = m - 2 * (x - 1);
  int ans = 0;
  if (nn > 0 and mm > 0) {
    if (nn == 1) {
      ans = mm / 2 + mm % 2;
    } else if (mm == 1) {
      ans = nn / 2 + nn % 2;
    } else if (nn == 2) {
      ans = mm;
    } else if (mm == 2) {
      ans = nn;
    } else {
      bool w1 = (mm % 2 == 0);
      ans += nn / 2 + nn % 2;
      nn -= w1 ? 1 : 0;
      ans += nn / 2 + nn % 2;
      ans += (mm - 3) / 2 + (mm - 3) % 2;
      bool w2 = (nn % 2 == 0);
      mm += w2 ? 1 : 0;
      ans += (mm - 3) / 2 + (mm - 3) % 2;
    }
  }
  cout << ans << endl;
  return 0;
}
