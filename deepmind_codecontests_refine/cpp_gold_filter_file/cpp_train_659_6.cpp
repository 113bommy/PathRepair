#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int y, k, n;
  cin >> y >> k >> n;
  if (y >= n)
    cout << -1;
  else {
    if ((y + 1) % k == 0) {
      for (long long int i = 1; i <= n - y; i += k) cout << i << " ";
    } else {
      long long int i = 1 + k - (y + 1) % k;
      if (i > n - y)
        cout << -1;
      else {
        for (; i <= n - y; i += k) cout << i << " ";
      }
    }
  }
  return 0;
}
