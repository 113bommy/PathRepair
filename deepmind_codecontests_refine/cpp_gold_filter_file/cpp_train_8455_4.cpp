#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    int r = -1;
    bool b = true;
    for (int j = 1; j < n + 1; j++) {
      r = -1;
      for (int k = 0; k < n; k++) {
        if (a[k] == j) {
          if (r == -1) {
            r = k;
          } else if (r + 1 != k and b) {
            cout << "YES" << endl;
            b = false;
          }
        }
      }
    }
    if (b) cout << "NO" << endl;
  }
  return 0;
}
