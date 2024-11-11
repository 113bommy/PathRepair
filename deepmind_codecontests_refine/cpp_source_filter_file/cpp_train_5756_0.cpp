#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 2) {
      cout << 3 << "\n";
      cout << 1 << " " << 2 << "\n";
    } else {
      cout << 2 << "\n";
      cout << n << " " << n - 2 << "\n";
      cout << n - 1 << " " << n - 1 << "\n";
      long long s = n - 1;
      for (long long i = n - 3; i >= 1; i--) {
        cout << i << " " << s << "\n";
        s = (i + s) / 2;
      }
    }
  }
  return 0;
}
