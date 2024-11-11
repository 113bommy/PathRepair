#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int L, v, l, r;
    cin >> L >> v >> l >> r;
    int ans = 0;
    ans = (L / v);
    ans -= r / v - (l - 1) / v;
    cout << ans << endl;
  }
  return 0;
}
