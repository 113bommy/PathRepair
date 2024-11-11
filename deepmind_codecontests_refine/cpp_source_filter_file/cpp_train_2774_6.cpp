#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, n, i, _min = 1e18 + 1, x, ans;
  cin >> n >> k;
  long long a[k], t;
  for (i = 0; i < k; ++i) {
    cin >> t;
    if ((n % t < _min) && (n >= t)) {
      _min = n % t;
      ans = n / t;
      x = i + 1;
    }
  }
  cout << x << " " << ans;
}
