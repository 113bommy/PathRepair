#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long x, y, n;
    cin >> x >> y >> n;
    if ((n % x - y) >= 0)
      cout << n - ((n % x) - y) << endl;
    else
      cout << n - (n % x) - x + y << endl;
  }
  return 0;
}
