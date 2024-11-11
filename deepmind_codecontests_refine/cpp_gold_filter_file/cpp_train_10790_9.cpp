#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  cin >> l >> r >> a;
  if (l == 0 && r == 0) {
    if (a == 0)
      cout << "0" << endl;
    else {
      if (a % 2 == 0)
        cout << a << endl;
      else
        cout << a - 1 << endl;
    }
  } else if (l == 0) {
    if (a >= r)
      cout << 2 * r + (a - r) / 2 * 2;
    else
      cout << 2 * a;
  } else if (r == 0) {
    if (a >= l)
      cout << 2 * l + (a - l) / 2 * 2;
    else
      cout << 2 * a;
  } else {
    int min_x = min(l, r);
    int max_x = max(l, r);
    if (a <= (max_x - min_x))
      cout << 2 * (min_x + a) << endl;
    else {
      a -= max_x - min_x;
      cout << (a - a % 2) + 2 * max_x << endl;
    }
  }
  return 0;
}
