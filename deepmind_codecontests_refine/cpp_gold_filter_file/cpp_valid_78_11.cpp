#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, a, l, r, ans;
  cin >> t;
  for (int p = 0; p < t; p++) {
    cin >> l >> r;
    if (l < (r / 2)) {
      ans = r / 2;
      if (r % 2 == 0) {
        cout << (r / 2) - 1 << endl;
      } else {
        cout << r % ((r / 2) + 1) << endl;
      }
    } else if (l == (r / 2)) {
      if (r % 2 == 0) {
        cout << (r / 2) - 1 << endl;
      } else {
        cout << r % ((r / 2) + 1) << endl;
      }
    } else {
      cout << r % l << endl;
    }
  }
  return 0;
}
