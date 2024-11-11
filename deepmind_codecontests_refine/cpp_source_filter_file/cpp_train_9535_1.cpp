#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n;
  cin >> n;
  int64_t a[n];
  for (auto &it : a) cin >> it;
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  if (n == 2) {
    cout << max(a[0], a[1]) << ' ' << max(a[0], a[1]) << endl;
    return 0;
  }
  int64_t odd[n - 1];
  int64_t even[n - 2];
  for (int64_t i = 0; i < n; i++) {
    odd[i] = max(a[i], a[i + 1]);
    even[i] = max(min(a[i], a[i + 1]), min(a[i + 1], a[i + 2]));
  }
  int64_t lo = (n - !(n % 2)) / 2 - 1, ro = lo + !(n % 2);
  int64_t le = (n - n % 2) / 2 - 1, re = le + (n % 2);
  int64_t mxo = 0, mxe = 0;
  for (int64_t k = 0; k <= n - 3; k++) {
    if ((n - k) % 2 == 0) {
      mxe = max({mxe, even[le], even[re]});
      cout << mxe << ' ';
      le--, re++;
    } else {
      mxo = max({mxo, odd[lo], odd[ro]});
      cout << mxo << ' ';
      lo--, ro++;
    }
  }
  cout << *max_element(a, a + n) << ' ' << *max_element(a, a + n) << endl;
}
