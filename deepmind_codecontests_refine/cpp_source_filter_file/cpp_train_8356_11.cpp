#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if ((n == 1) or (n % 2 == 0 and n < 7)) {
      cout << -1 << "\n";
    } else {
      if (n % 3 == 0) {
        cout << (n / 3) << " 0 0"
             << "\n";
      } else if (n % 3 == 1) {
        cout << (n / 3) - 2 << " 0 1"
             << "\n";
      } else {
        cout << (n / 3) - 1 << " 1 0"
             << "\n";
      }
    }
  }
  return 0;
}
