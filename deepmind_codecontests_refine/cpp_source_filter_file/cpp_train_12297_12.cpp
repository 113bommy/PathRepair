#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q > 0) {
    int l, r;
    cin >> l >> r;
    int a = (r - l + 1) / 2;
    int b = 0;
    if (l % 2 == 0) {
      b = a * (-1);
    } else {
      b = a;
    }
    if ((r - l + 1) % 2 != 0) {
      if (l % 2 == 0)
        b -= r;
      else
        b += r;
    }
    if (r == l) {
      if (r % 2 == 0)
        b = r;
      else
        b = r * (-1);
    }
    cout << b << endl;
    q--;
  }
  return 0;
}
