#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, p, k, m, t, x, y, ans, res, mn, mx;
  cin >> n;
  long long a[n + 1];
  ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i != 1)
      ans += fabs(a[i] - a[i - 1]);
    else
      ans += fabs(a[i]);
  }
  cout << ans << endl;
  return 0;
}
