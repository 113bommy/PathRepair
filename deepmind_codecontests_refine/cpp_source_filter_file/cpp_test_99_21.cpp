#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n, ans;
    cin >> x >> n;
    if (n == 0) {
      cout << x << endl;
      continue;
    }
    if (abs(x) % 2 == 0) {
      int a = abs(n - 1) % 4;
      if (a == 0) ans = x - 1 - 4 * ((n - 1) / 4);
      if (a == 1) ans = x - 1 - 4 * ((n - 1) / 4) + n;
      if (a == 2) ans = x - 1 - 4 * ((n - 1) / 4) + n + n - 1;
      if (a == 3) ans = x - 1 - 4 * ((n - 1) / 4) + n - 2 + n - 1 - n;
    }
    if (abs(x) % 2 == 1) {
      int b = abs(n - 1) % 4;
      if (b == 0) ans = x + 1 + 4 * ((n - 1) / 4);
      if (b == 1) ans = x + 1 + 4 * ((n - 1) / 4) - n;
      if (b == 2) ans = x + 1 + 4 * ((n - 1) / 4) - n - n - 1;
      if (b == 3) ans = x + 1 + 4 * ((n - 1) / 4) - n - 2 - n - 1 + n;
    }
    cout << ans << endl;
  }
  return 0;
}
