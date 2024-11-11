#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x;
  cin >> s >> x;
  if (s < x || ((s - x) & 1) || (((s - x) / 2) & x)) {
    cout << 0 << endl;
    return 0;
  }
  long long v = x, ans = 1;
  while (v) {
    if (v & 1) ans *= 2;
    v >>= 1;
  }
  if (s == x) ans -= 2;
  cout << ans << endl;
  return 0;
}
