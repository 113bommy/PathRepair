#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    double a, b;
    double ans = 0;
    cin >> a >> b;
    if (b == 0) {
      cout << "1.00000000000" << endl;
      continue;
    }
    if (a == 0) {
      cout << "0.50000000" << endl;
      continue;
    }
    double q = min(b, a / 4);
    ans = (a * b + q * (2 * a - 4 * q) / 2) / (2 * b * a);
    cout << fixed << setprecision(7) << ans << endl;
  }
  return 0;
}
