#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x, a[1005], i, odd, even;
  cin >> t;
  while (t--) {
    odd = 0;
    even = 0;
    cin >> n >> x;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 != 0) {
        odd++;
      } else {
        even++;
      }
    }
    if (odd > 0 && even > 0) {
      if (x < odd + even) {
        cout << "Yes" << endl;
      }
      if (x == odd + even) {
        if (odd % 2 != 0) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    } else if (odd == 0) {
      cout << "No" << endl;
    } else if (even == 0) {
      if (x % 2 != 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
