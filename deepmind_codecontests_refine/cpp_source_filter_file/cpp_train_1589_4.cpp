#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, n, i, j, k;
    cin >> x >> y >> n;
    i = n / x;
    if (n % x == y) {
      cout << n << endl;
    }
    if (n - x * i > y) {
      cout << x * i + y << endl;
    } else {
      j = x * i - x + y;
      if (j < 0)
        cout << "0" << endl;
      else
        cout << j << endl;
    }
  }
  return 0;
}
