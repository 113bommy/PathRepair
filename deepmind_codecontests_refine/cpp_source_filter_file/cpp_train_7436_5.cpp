#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  if (k == 1) {
    for (i = 0; i < n - 1; i++) {
      cout << "PRINT " << str[i] << "\n"
           << "RIGHT" << endl;
    }
    cout << "PRINT " << str[n - 1];
  } else if (k == n) {
    for (i = n - 1; i > 0; i--) {
      cout << "PRINT " << str[i] << "\n"
           << "LEFT" << endl;
    }
    cout << "PRINT " << str[0];
  } else if (k <= n / 2) {
    for (i = 0; i < k; i++) {
      cout << "LEFT" << endl;
    }
    for (i = 0; i < n - 1; i++) {
      cout << "PRINT " << str[i] << "\n"
           << "RIGHT" << endl;
    }
    cout << "PRINT " << str[n - 1];
  } else {
    for (i = k; i < n; i++) {
      cout << "RIGHT" << endl;
    }
    for (i = n - 1; i > 0; i--) {
      cout << "PRINT " << str[i] << "\n"
           << "LEFT" << endl;
    }
    cout << "PRINT " << str[0];
  }
}
