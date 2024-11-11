#include <bits/stdc++.h>
using namespace std;
const double p = 3.1415926535897932384;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 != 0) {
      long long oa = 0;
      for (long long i = 0; i < n; i = i + 2) {
        if ((s[i] - '0') % 2 != 0) {
          oa++;
        }
      }
      if (oa > 0) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else {
      long long ea = 0;
      for (long long i = 1; i < n; i = i + 2) {
        if ((s[i] - '0') % 2 == 0) {
          ea++;
        }
      }
      if (ea > 0) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
}
