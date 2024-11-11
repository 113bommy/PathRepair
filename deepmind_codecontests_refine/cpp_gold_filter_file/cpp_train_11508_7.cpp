#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  while (cin >> n >> d >> h) {
    if (d > 2 * h || (d == 1 && h == 1 && n > 2))
      cout << -1 << endl;
    else {
      int k = 1;
      for (int i = 2; i <= 1 + h; i++) {
        int a = k;
        int b = i;
        cout << a << " " << b << endl;
        k = b;
      }
      if (d - h > 0) {
        int t1 = k, t = 1;
        for (int i = 2 + h; i <= n; i++) {
          int a = t, b = i;
          cout << a << " " << b << endl;
          t = b;
          if ((i - t1) % (d - h) == 0) t = 1;
        }
      } else if (d - h == 0) {
        int t = 2;
        for (int i = 2 + h; i <= n; i++) {
          int a = t, b = i;
          cout << a << " " << b << endl;
        }
      }
    }
  }
  return 0;
}
