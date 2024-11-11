#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (n == 1) {
      cout << "0\n";
    } else {
      if (k == 1) {
        cout << n - 1 << "\n";
      } else {
        long long a = 0;
        long long cnt = 0;
        while (pow(2, a) < k) {
          cnt++;
          a++;
        }
        long long x = pow(2, a);
        if (n <= x) {
          long long p = 0;
          long long q = 0;
          while (n > 1) {
            n = n - pow(2, q);
            q++;
            p++;
          }
          cout << p << "\n";
        } else {
          long long y = n - x;
          long long z = y % k;
          if (z == 0) {
            cout << a + (y / x) << "\n";
          } else {
            cout << a + (y / x) + 1 << "\n";
          }
        }
      }
    }
  }
  return 0;
}
