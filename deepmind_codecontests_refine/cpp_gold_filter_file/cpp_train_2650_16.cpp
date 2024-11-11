#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, k;
  cin >> l >> r >> k;
  if (k == 1) {
    cout << l << endl << 1 << endl << l << endl;
    return 0;
  }
  if (k == 2) {
    if (l % 2 == 0) {
      cout << 1 << endl << 2 << endl << l << " " << l + 1 << endl;
    } else {
      if (r == l + 1) {
        if (l == 1) {
          cout << 1 << endl << 1 << endl << 1 << endl;
        } else {
          if (l < (l ^ r)) {
            cout << l << endl << 1 << endl << l << endl;
          } else {
            cout << (l ^ r) << endl << 2 << endl << l << " " << r << endl;
          }
        }
      } else {
        cout << 1 << endl << 2 << endl << l + 1 << " " << l + 2 << endl;
      }
    }
    return 0;
  }
  if (l == 1) {
    cout << 0 << endl << 3 << endl << 1 << " " << 2 << " " << 3 << endl;
    return 0;
  }
  long long x = 3;
  while (x < l) {
    x <<= 1LL;
    x += 1LL;
  }
  long long y = x + 1 + (x >> 1LL);
  if (y + 1 <= r) {
    cout << 0 << endl << 3 << endl << x << " " << y << " " << y + 1 << endl;
    return 0;
  }
  if (k > 3) {
    if (l % 2 == 0) {
      cout << 0 << endl
           << 4 << endl
           << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
    } else {
      if (l + 4 <= r) {
        cout << 0 << endl
             << 4 << endl
             << l + 1 << " " << l + 2 << " " << l + 3 << " " << l + 4 << endl;
      } else {
        cout << 1 << endl << 2 << endl << l + 1 << " " << l + 2 << endl;
      }
    }
    return 0;
  }
  if (l % 2 == 0) {
    cout << 1 << endl << 2 << endl << l << " " << l + 1 << endl;
  } else {
    cout << 1 << endl << 2 << endl << l + 1 << " " << l + 2 << endl;
  }
  return 0;
}
