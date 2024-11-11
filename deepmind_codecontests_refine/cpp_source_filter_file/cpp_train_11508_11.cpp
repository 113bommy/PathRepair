#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h, i, j, k, l, p;
  cin >> n >> d >> h;
  if (d > 2 * h)
    cout << "-1" << endl;
  else {
    if (d == 1 && h == 1)
      cout << "-1" << endl;
    else {
      i = 1;
      j = i + 1;
      for (k = 1; k <= h; k++) {
        cout << i << " " << j << endl;
        i = j;
        j = i + 1;
      }
      n = n - h - 1;
      d = d - h;
      if (d) {
        p = n / d;
        n = n % d;
        for (k = 1; k <= p; k++) {
          i = 1;
          for (l = 1; l <= d; l++) {
            cout << i << " " << j << endl;
            i = j;
            j = i + 1;
          }
        }
        i = 1;
        for (k = 1; k <= n; k++) {
          cout << i << " " << j << endl;
          i = j;
          j = i + 1;
        }
      } else {
        i = 2;
        for (k = 1; k <= n; k++) {
          cout << i << " " << j << endl;
          j += 1;
        }
      }
    }
  }
  return 0;
}
