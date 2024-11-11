#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y, n, m = 0;
    cin >> x >> y >> n;
    m = n % x;
    if (m == y)
      cout << n << "\n";
    else if (m > y)
      cout << (n - (m - y)) << "\n";
    else {
      n -= m;
      cout << (n - x - y) << "\n";
    }
  }
  return 0;
}
