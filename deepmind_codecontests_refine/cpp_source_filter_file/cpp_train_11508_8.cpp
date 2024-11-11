#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, d, h, i, p, q, s;
  cin >> n >> d >> h;
  if (d > (2 * h)) {
    cout << "-1";
  }
  if ((d == 1) && (h == 1)) {
    if (n == 2) {
      cout << "1 2";
    } else {
      cout << "-1";
    }
  } else if ((d == h)) {
    for (i = 1; i <= h - 1; i++) {
      cout << i << " " << i + 1 << endl;
    }
    p = h + 2;
    for (i = h + 1; i <= n; i++) {
      cout << h << " " << i << endl;
    }
  } else {
    if (d > h) {
      for (i = 1; i <= h; i++) {
        cout << i << " " << i + 1 << endl;
      }
      cout << "1 " << h + 2 << endl;
      for (i = (h + 2); i <= d; i++) {
        cout << i << " " << i + 1 << endl;
      }
      for (i = (d + 2); i <= n; i++) {
        cout << "1 " << i << endl;
      }
    }
  }
}
