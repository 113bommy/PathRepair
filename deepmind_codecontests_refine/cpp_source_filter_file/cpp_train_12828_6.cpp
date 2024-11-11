#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 5;
int main() {
  long long n, x, y, sum, t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    sum = (x + y);
    if (sum <= n) {
      cout << "1 " << sum - 1 << endl;
    } else {
      cout << sum - n + 1 << " " << n << endl;
    }
  }
  return 0;
}
