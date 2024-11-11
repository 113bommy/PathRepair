#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  bool right = true;
  if (k <= n / 2) {
    right = false;
  }
  if (k != 1 && k != n) {
    if (right) {
      for (int i = 0; i < n - k; i++) {
        cout << "RIGHT"
             << "\n";
      }
    } else {
      for (int i = k; i > 0; i--) {
        cout << "LEFT"
             << "\n";
      }
    }
  }
  if (right) {
    for (int i = n - 1; i > 0; i--) {
      cout << "PRINT " << s[i] << "\n";
      cout << "LEFT"
           << "\n";
    }
    cout << "PRINT " << s[0] << "\n";
  } else {
    for (int i = 0; i < n - 1; i++) {
      cout << "PRINT " << s[i] << "\n";
      cout << "RIGHT"
           << "\n";
    }
    cout << "PRINT " << s[n - 1] << "\n";
  }
  return 0;
}
