#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, c, ans = 0, d;
  cin >> k;
  if (k > 36) {
    cout << -1;
    return 0;
  } else if (k == 36) {
    cout << "888888888888888888";
    return 0;
  } else {
    c = k % 2;
    if (c == 0) {
      c = k / 2;
      while (c > 0) {
        ans = ans * 10 + 8;
        c = c - 1;
      }
    } else {
      c = k / 2;
      d = k / 2;
      while (c > 0) {
        ans = ans * 10 + 8;
        c = c - 1;
      }
      ans = 9 * pow(10, d) + ans;
    }
    cout << ans;
  }
}
