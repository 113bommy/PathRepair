#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    long double x = a;
    long double y = b;
    if (b == 0) {
      cout << 1.0000000 << '\n';
      continue;
    } else if (a == 0) {
      cout << 0.000000 << '\n';
      continue;
    }
    long double ans = 1;
    long double deno = 2 * x * y;
    if (x / 4 <= y) {
      ans = ans * 0.5 * x * x / 4 + x * y;
      ans /= deno;
    } else {
      ans = ans * 0.5 * x * x / 4 + x * y - (x - 4 * y) * (x / 4 - y) * 0.5;
      ans /= deno;
    }
    cout << fixed << setprecision(18) << ans << '\n';
  }
}
