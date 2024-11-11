#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    int ans = abs(a - b);
    int temp = a;
    a = min(a, b);
    b = max(temp, b);
    if (x > 0) {
      if ((a - 1) < x) {
        ans += a - 1;
        x -= (x - 1);
        if (x <= (n - b)) {
          ans += x;
        } else {
          ans += (n - b);
        }
      } else
        ans += x;
    }
    cout << ans << endl;
  }
  return 0;
}
