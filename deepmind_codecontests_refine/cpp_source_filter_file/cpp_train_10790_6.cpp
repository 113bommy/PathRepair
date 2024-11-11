#include <bits/stdc++.h>
using namespace std;
int l, r, a;
int main() {
  cin >> l >> r >> a;
  if (l < r) {
    if (a + l <= r)
      l += a, a = 0;
    else
      a -= r - l, l = r;
  } else if (r < l) {
    if (a + r <= l)
      r += a;
    else
      a -= l - r, r = l;
  }
  int ans = min(r, l) * 2;
  if (a >= 2) {
    if (a & 1) a--;
    ans += a;
  }
  cout << ans << endl;
}
