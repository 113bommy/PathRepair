#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, length = 1, ans = 1, z = 1;
  cin >> x;
  y = x;
  while (y >= 10) {
    length++;
    y = y / 10;
  }
  for (int i = 1; i < length; i++) {
    y *= 10L;
    y += 9L;
  }
  for (int i = 0; i <= length; i++) {
    ans = y;
    if (i > 0) ans -= z;
    if (ans <= x) break;
    if (i > 0) z *= 10;
  }
  cout << ans << endl;
  return 0;
}
