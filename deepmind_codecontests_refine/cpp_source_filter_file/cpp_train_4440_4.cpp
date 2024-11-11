#include <bits/stdc++.h>
using namespace std;
int main() {
  int q = 1;
  while (q--) {
    long long int r, g, b;
    cin >> r >> g >> b;
    if (r % 2 == 0)
      r = r / 2;
    else {
      r = r / 2;
      r++;
    }
    if (g % 2 == 0)
      g = g / 2;
    else {
      g = g / 2;
      g++;
    }
    if (b % 2 == 0)
      b = b / 2;
    else {
      b = b / 2;
      b++;
    }
    long long int ans = 30;
    if (r >= g && r >= b) {
      ans += (r - 1) * 3;
    } else if (g >= r && g >= b) {
      ans += (g * 3);
      ans--;
      ans--;
    } else if (b >= r && b >= g) {
      ans += b * 3;
      ans--;
    }
    if (r == 0 && g == 0 && b == 0) ans = 0;
    cout << ans;
    cout << endl;
  }
  return 0;
}
