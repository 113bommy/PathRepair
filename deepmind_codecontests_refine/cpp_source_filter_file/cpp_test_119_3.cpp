#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    long long a, ans = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a;
      ans += a;
    }
    cout << ((ans % n) == 0) << endl;
  }
  return 0;
}
