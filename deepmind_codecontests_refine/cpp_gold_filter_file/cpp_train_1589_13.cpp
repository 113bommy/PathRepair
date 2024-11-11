#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long x, y, n;
  cin >> t;
  while (t--) {
    cin >> x >> y >> n;
    if (n % x > y)
      n -= (n % x - y);
    else if (n % x < y)
      n -= (n % x + x - y);
    cout << n << endl;
  }
  return 0;
}
