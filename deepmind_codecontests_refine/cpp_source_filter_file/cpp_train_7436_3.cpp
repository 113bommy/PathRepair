#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n - k > k) {
    while (k > 1) {
      cout << "LEFT\n";
      k--;
    }
    for (; k <= n; k++) {
      cout << "PRINT " << s[k - 1] << "\n";
      if (k != n) {
        cout << "RIGHT\n";
      }
    }
  } else {
    while (k < n) {
      cout << "RIGHT\n";
      k++;
    }
    for (; k > 0; k--) {
      cout << "PRINT " << s[k - 1] << "\n";
      if (k != 1) {
        cout << "LEFT\n";
      }
    }
  }
}
