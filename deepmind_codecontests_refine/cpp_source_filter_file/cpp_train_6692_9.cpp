#include <bits/stdc++.h>
using namespace std;
int t;
int nrcif(int x) {
  int ans = 0;
  while (x) ans++, x /= 10;
  return ans;
}
int main() {
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int nr = nrcif(x), lc = x % 10, ans = 0;
    ans = (lc - 1) * 10;
    if (nr == 1)
      ans++;
    else if (nr == 2)
      ans += 2;
    else if (nr == 3)
      ans += 3;
    else
      ans += 4;
    cout << ans << '\n';
  }
  return 0;
}
