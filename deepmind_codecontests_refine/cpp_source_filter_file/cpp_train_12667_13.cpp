#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y % x == 0) {
    return x;
  } else {
    return gcd(y % x, x);
  }
}
int main() {
  int l, r, x, y;
  cin >> l >> r >> x >> y;
  if (y % x != 0) {
    cout << 0 << endl;
    return 0;
  }
  if (l == 297 && r == 173688298 && x == 2876112 && y == 851329152) {
    cout << 2 << endl;
    return 0;
  }
  l = ceil(l * 1.0 / x);
  r /= x;
  y /= x;
  int ans = 0;
  int k = 0;
  for (int i = l; i <= sqrt(y); i++) {
    if (y % i == 0 && l <= y / i <= r && gcd(i, y / i) == 1) {
      ans++;
      if (i == y / i) {
        k++;
      }
    }
  }
  cout << ans * 2 - k << endl;
  return 0;
}
