#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    int ans = 0;
    int ct_4 = n / 4;
    int rem = n % 4;
    if (rem == 1) {
      ct_4 -= 2;
      ans = ct_4 + 1;
    } else if (rem == 2) {
      ct_4 -= 1;
      ans = ct_4 + 1;
    } else if (rem == 3) {
      ct_4 -= 3;
      ans = ct_4 + 1;
    } else {
      ans = ct_4;
    }
    if (ct_4 < 0) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
