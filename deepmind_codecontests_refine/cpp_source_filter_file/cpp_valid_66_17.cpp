#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long num[18]{29, 1,  2,  4,  5,  7,  8,  10, 11,
                    14, 16, 17, 19, 20, 22, 25, 26, 28};
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (n / 18) * 30 + num[n % 18] << endl;
  }
  return 0;
}
