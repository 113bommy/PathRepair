#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    long long x = a / c;
    if (a % c != 0) x++;
    long long y = b / d;
    if (b % d != 0) y++;
    if ((x + y) <= k)
      cout << x << y << endl;
    else
      cout << "-1" << endl;
  }
}
