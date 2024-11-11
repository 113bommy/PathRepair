#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  int k = 0;
  cin >> l >> r >> a;
  if (l > 0 && a > 0 || r > 0 && a > 0 || l > 0 && r > 0) {
    while (l != r && a != 0) {
      if (l < r) l++;
      if (r < l) r++;
      a--;
    }
    if (l == r) k = l + r;
    while (l != r) {
      if (l > r) l--;
      if (l < r) r--;
      k = l + r;
    }
    if (a > 1 && a % 2 == 0) k += a;
    if (a > 1 && a % 2 != 0) {
      a--;
      k += a;
    }
    cout << k;
  } else
    cout << 0;
  return 0;
}
