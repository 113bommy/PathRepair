#include <bits/stdc++.h>
using namespace std;
long long l, r, k;
int main() {
  cin >> l >> r >> k;
  if (k >= 4) {
    for (long long i = l; i + 2 < r; l++)
      if (l % 2 == 0) {
        cout << 0 << endl
             << 4 << endl
             << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << " "
             << endl;
        return 0;
      }
  }
  if (k >= 3) {
    long long c = 0, b = l;
    while (b) {
      b /= 2;
      c++;
    }
    b = 3;
    while (--c) b *= 2;
    if (b <= r) {
      cout << 0 << endl << 3 << endl << l << " " << (l ^ b) << " " << b << endl;
      return 0;
    }
  }
  if (k >= 2) {
    if (l % 2 == 0) {
      cout << 1 << endl << 2 << endl << l << " " << l + 1 << endl;
      return 0;
    }
    if (l % 2 == 1 && l + 2 <= r) {
      cout << 1 << endl << 2 << endl << l + 1 << " " << l + 2 << endl;
      return 0;
    }
    if ((l ^ r) < l) {
      cout << (l ^ r) << endl << 2 << endl << l << " " << r << endl;
      return 0;
    }
  }
  cout << l << endl << 1 << endl << l << endl;
  return 0;
}
