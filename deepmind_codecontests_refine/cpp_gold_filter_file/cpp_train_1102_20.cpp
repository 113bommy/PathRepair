#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    double a, b, ans;
    cin >> a >> b;
    if (b == 0) {
      cout << 1.00 << endl;
      continue;
    }
    if (a > 4 * b)
      ans = (a - b * 2) / a;
    else
      ans = a / 8.0 / b;
    cout << fixed << setprecision(10) << ans * 0.5 + 0.5 << endl;
  }
  return 0;
}
