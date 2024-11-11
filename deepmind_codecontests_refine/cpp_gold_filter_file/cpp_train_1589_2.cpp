#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, n;
    cin >> x >> y >> n;
    int res;
    if (x <= n) {
      res = (n - y) / x * x + y;
    } else {
      res = y;
    }
    cout << res << '\n';
  }
  return 0;
}
