#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  long long _;
  cin >> _;
  while (_--) {
    string a;
    cin >> a;
    long long f = 0, s = 0;
    long long ans = 10;
    for (long long i = 0; i < 10; i++) {
      if (a[i] == '1') {
        if (i % 2 == 0) {
          f++;
        } else {
          s++;
        }
      }
      if (a[i] == '?') {
        if (i % 2 == 0) f++;
      }
      if (s + (10 - i) / 2 < f || f + (9 - i) / 2 < s) {
        ans = i + 1;
        break;
      }
    }
    f = 0, s = 0;
    for (long long i = 0; i < 10; i++) {
      if (a[i] == '1') {
        if (i % 2 == 0) {
          f++;
        } else {
          s++;
        }
      }
      if (a[i] == '?') {
        if (i % 2 != 0) s++;
      }
      if (f + (9 - i) / 2 < s || s + (10 - i) / 2 < f) {
        ans = min(ans, i + 1);
        break;
      }
    }
    cout << ans << '\n';
  }
}
