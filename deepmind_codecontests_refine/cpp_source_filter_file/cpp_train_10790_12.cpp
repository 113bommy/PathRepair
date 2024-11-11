#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  cin >> l >> r >> a;
  int ans = 0;
  if (l > r) {
    if (a >= (l - r)) {
      ans += l + (l - r);
      a -= (l - r);
    } else {
      ans += (r + a) * 2;
      a = 0;
    }
  } else if (r > l) {
    if (a >= (r - l)) {
      ans += r + (r - l);
      a -= (r - l);
    } else {
      ans += (l + a) * 2;
      a = 0;
    }
  } else {
    ans = r + l;
  }
  ans += (a / 2) * 2;
  cout << ans << endl;
}
