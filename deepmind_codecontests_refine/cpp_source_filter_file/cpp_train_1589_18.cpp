#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y, n, r, k;
  cin >> t;
  while (t--) {
    cin >> x >> y >> n;
    r = n / x;
    k = x * r + y;
    if (k < n) {
      cout << k << endl;
    } else {
      cout << k - x << endl;
    }
  }
  return 0;
}
