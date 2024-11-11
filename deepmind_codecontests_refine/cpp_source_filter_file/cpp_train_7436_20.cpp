#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  cin >> n >> k;
  cin >> s;
  k--;
  if (k == 0) {
    for (int i = 0; i < n - 1; i++) {
      cout << "PRINT " << s[i] << endl;
      cout << "RIGHT" << endl;
    }
    cout << "PRINT " << s[n - 1] << endl;
    return 0;
  }
  if (k == n - 1) {
    for (int i = n - 1; i > 0; i--) {
      cout << "PRINT " << s[i] << endl;
      cout << "LEFT" << endl;
    }
    cout << "PRINT " << s[0] << endl;
    return 0;
  }
  int m = n / 2;
  if (k < m) {
    for (int i = 0; i < m - k; i++) {
      cout << "LEFT" << endl;
    }
    for (int i = 0; i < n - 1; i++) {
      cout << "PRINT " << s[i] << endl;
      cout << "RIGHT" << endl;
    }
    cout << "PRINT " << s[n - 1] << endl;
    return 0;
  }
  if (k >= m) {
    for (int i = 0; i < n - 1 - k; i++) {
      cout << "RIGHT" << endl;
    }
    for (int i = n - 1; i > 0; i--) {
      cout << "PRINT " << s[i] << endl;
      cout << "LEFT" << endl;
    }
    cout << "PRINT " << s[0] << endl;
    return 0;
  }
  return 0;
}
