#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, test;
  string a[10];
  cin >> test;
  while (test--) {
    for (i = 0; i < 8; i++) cin >> a[i];
    k = -1;
    if (test) getchar();
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (a[i][j] == 'K') {
          if (k == -1) {
            k = i;
            l = j;
          } else {
            m = i;
            n = j;
          }
        }
      }
    }
    if (k == m) {
      if (abs(l - n) == 4)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (l == n) {
      if (abs(k - m) == 4)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (abs(k - m) == 4 && abs(l - n) == 4)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
