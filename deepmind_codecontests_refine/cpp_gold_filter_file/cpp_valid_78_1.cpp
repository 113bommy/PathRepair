#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-8;
const int INF = 1000000000;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r, ans, any;
    cin >> l >> r;
    ans = 0;
    if (l > r / 2 + 1)
      ans = r % l;
    else if (r > 50) {
      any = (r / 2) - 20;
      for (int i = any; any + 40 >= i; i++) {
        if (i >= l) ans = max(ans, r % i);
      }
    } else {
      for (int i = l; r > i; i++) {
        ans = max(ans, r % i);
      }
    }
    cout << ans;
    cout << "\n";
  }
}
