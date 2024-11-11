#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k, i, j, l, ur, uc, lr, lc, p, c;
  cin >> t;
  for (l = 0; l < t; l++) {
    cin >> n >> k;
    long long int a[310][310] = {0, 0, 0};
    if (k % n == 0)
      cout << "0\n";
    else
      cout << "2\n";
    ur = 1, uc = 1, lr = n, lc = 1, p = 1, c = 0;
    while (k != 0) {
      if (p % 2 != 0) {
        for (i = ur, j = uc; j <= n; i++, j++) {
          a[i][j] = 1;
          k--;
          if (k == 0) {
            c = 1;
            break;
          }
        }
        if (c == 1) break;
        uc = uc + 1;
      } else {
        for (i = lr, j = lc; i <= n; i++, j++) {
          a[i][j] = 1;
          k--;
          if (k == 0) {
            c = 1;
            break;
          }
        }
        if (c == 1) break;
        lr = lr - 1;
      }
      p++;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
