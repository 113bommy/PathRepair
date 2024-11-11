#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  cin >> l >> r >> a;
  int t = max(l, r);
  if ((l == 0 || r == 0) && a == 0) {
    cout << 0;
    return 0;
  } else {
    int b = a - abs(l - r);
    if (b >= 0) {
      t = t * 2;
      t = t + (b / 2) * 2;
    } else {
      t = t + b;
      t = 2 * t;
    }
  }
  cout << t;
  return 0;
}
