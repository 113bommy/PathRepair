#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
long long int a[100];
long long fastPower(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base;
    }
    power >>= 1;
    base = (base * base);
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned long long int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        if (a[i] != 0) {
          ans = 1;
          flag = true;
          break;
        }
      } else {
        if (k < fastPower(10ll, a[i] - a[i - 1])) {
          ans += (k + 1) * fastPower(10ll, a[i - 1]);
          flag = true;
          break;
        } else {
          for (int j = a[i - 1]; j < a[i]; j++) {
            ans += fastPower(10ll, j) * 9;
          }
          k = k - fastPower(10ll, a[i] - a[i - 1]) + 1;
        }
      }
    }
    if (flag) {
      cout << ans << "\n";
      ;
    } else {
      ans += (k + 1) * fastPower(10ll, a[n]);
      cout << ans << "\n";
      ;
    }
  }
  return 0;
}
