#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, mx = 0, mn = 10000000000, ans;
  cin >> n;
  int nn = n;
  while (nn--) {
    cin >> a;
    mn = min(mn, a);
    mx = max(mx, a);
  }
  ans = mx - mn - n + 1;
  cout << ans;
  return 0;
}
