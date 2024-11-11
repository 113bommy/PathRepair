#include <bits/stdc++.h>
using namespace std;
long long t;
long long L, v, l, r;
int main() {
  cin >> t;
  while (t--) {
    long long ans;
    cin >> L >> v >> l >> r;
    long long ord = L / v;
    long long trd = r / v - l / v;
    if ((r % v == 0 && l % v == 0)) {
      trd++;
    } else if (l % v == 0 && r % v != 0) {
      trd--;
    }
    if (r == l && l % v == 0 && r % v == 0) {
      trd = 1;
    }
    ans = ord - trd;
    cout << ans << endl;
  }
}
