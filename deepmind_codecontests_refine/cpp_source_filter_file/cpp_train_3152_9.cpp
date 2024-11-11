#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, x, y, n, f1, f2, ans = 1e9, m;
    cin >> a >> b >> x >> y >> n;
    m = n;
    f1 = max(x, a - n);
    n -= (a - f1);
    f2 = max(y, b - n);
    ans = min(ans, f1 * f2);
    f1 = max(y, b - m);
    m -= (b - f1);
    f2 = max(x, a - m);
    ans = min(ans, f1 * f2);
    cout << ans << endl;
  }
}
