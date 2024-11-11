#include <bits/stdc++.h>
using namespace std;
long long s, x, ans = 1;
int getBit(long long state, int pos) { return state >> (pos - 1) & 1; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s >> x;
  s -= x;
  if (s % 2 != 0) {
    cout << 0;
    return 0;
  }
  s /= 2;
  for (int i = 60; i > 0; --i) {
    int b1 = getBit(x, i), b2 = getBit(s, i);
    if (b1 == 1)
      if (b2 == 0) {
        cout << 0;
        return 0;
      } else
        ans *= 2;
  }
  if (s == x) ans -= 2;
  cout << ans;
  return 0;
}
