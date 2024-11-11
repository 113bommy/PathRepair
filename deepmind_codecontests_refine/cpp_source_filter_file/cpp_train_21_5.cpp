#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, l, r;
    cin >> n >> l >> r;
    long long s = 0;
    long long i;
    for (i = 1; i <= n - 1; i++) {
      s += 2 * (n - i);
      if (l <= s) {
        s = s - 2 * (n - 1);
        break;
      }
    }
    long long j, x = i;
    if (x == n) x = 1;
    if ((l - s) % 2 == 1) {
      j = i + (l + 1 - s) / 2;
      int f = 0;
      for (long long v = l; v <= r; v++) {
        if (f == 0) {
          cout << x << " ";
          f = 1;
        } else {
          cout << j << " ";
          j++;
          f = 0;
          if (j == n + 1) {
            x++;
            if (x == n) x = 1;
            j = x + 1;
          }
        }
      }
    } else {
      j = i + (l - s) / 2;
      int f = 1;
      for (long long v = l; v <= r; v++) {
        if (f == 0) {
          cout << x << " ";
          f = 1;
        } else {
          cout << j << " ";
          j++;
          f = 0;
          if (j == n + 1) {
            x++;
            if (x == n) x = 1;
            j = x + 1;
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
