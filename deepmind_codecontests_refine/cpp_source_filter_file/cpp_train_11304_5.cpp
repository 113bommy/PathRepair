#include <bits/stdc++.h>
using namespace std;
const long long int inf = 9e18;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long double a, b;
    cin >> a >> b;
    long double ans;
    if (b == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (a < 4 * b)
      ans = (a / 8 + b) / (2 * b);
    else {
      ans = (a - b) / a;
    }
    cout << fixed << setprecision(9) << ans << "\n";
  }
}
