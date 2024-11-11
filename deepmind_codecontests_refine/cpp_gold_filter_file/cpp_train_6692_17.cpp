#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, a = 10, z = 1, ans = 0, y = 0;
    cin >> x;
    y = x % 10;
    ans = (y - 1) * 10;
    while (1) {
      if ((x % a) == x) {
        ans = ans + z;
        break;
      } else {
        a = a * 10;
        ans = ans + z;
        z++;
      }
    }
    cout << ans << endl;
  }
}
