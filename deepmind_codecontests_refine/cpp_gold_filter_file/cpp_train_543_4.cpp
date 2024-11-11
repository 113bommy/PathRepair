#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x = 8, y = 1, sum = 0, tot = 1, i = 1;
    cin >> n;
    while (tot < n * n) {
      sum += x * y;
      i++;
      x = 8 * i;
      y++;
      tot += x;
    }
    cout << sum << "\n";
  }
}
