#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k1 = 0, k0 = 0;
    char a[200];
    cin >> a;
    for (int i = 0; a[i]; i++) {
      if (a[i] == '1') k1++;
      if (a[i] == '0') k0++;
    }
    if (k1 == 0 || k0 == 0) {
      int k = k1 + k0;
      while (k--) cout << a[0];
      cout << endl;
    } else {
      if (a[0] == '0') {
        for (int i = 0; i < k1 + k0; i++) {
          if (a[i] == '0') {
            if (a[i + 1] == '1') {
              cout << "01";
              i++;
            } else {
              cout << "01";
            }
          } else
            cout << "01";
        }
      } else {
        for (int i = 0; i < k1 + k0; i++) {
          if (a[i] == '1') {
            if (a[i + 1] == '0') {
              cout << "10";
              i++;
            } else {
              cout << "10";
            }
          } else
            cout << "10";
        }
      }
      cout << endl;
    }
  }
}
