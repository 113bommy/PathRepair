#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n, x;
signed main() {
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  if (n == 1) {
    cout << 0 << endl;
  } else {
    int ans = 0;
    if (x >= a[n])
      ans = x - a[2];
    else if (x <= a[1])
      ans = a[n - 1] - x;
    else {
      int res1 = min(abs(a[n - 1] - x), abs(x - a[1])) + a[n - 1] - a[1];
      int res2 = min(abs(a[n] - x), abs(x - a[2])) + a[n] - a[2];
      ans = min(res1, res2);
    }
    cout << ans << endl;
  }
  return 0;
}
