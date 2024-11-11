#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  cin >> l >> r >> a;
  if (l <= r) swap(l, r);
  if (l - r <= a) {
    a -= (l - r), r += (l - r), l += a / 2, r += a / 2;
    ;
    cout << l + r << '\n';
  } else {
    r += a;
    cout << 2 * r << '\n';
  }
  return 0;
}
