#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (2 * a <= b) {
      cout << a * abs(x) + b * abs(y) << '\n';
      continue;
    }
    long long ans;
    if (abs(x) < abs(y))
      ans = b * abs(x) + a * (abs(y) - abs(x));
    else
      ans = b * abs(y) + a * (abs(x) - abs(y));
    cout << ans << '\n';
  }
  return 0;
}
