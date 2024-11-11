#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a[2], k[2], n;
  cin >> a[0] >> a[1] >> k[0] >> k[1] >> n;
  long long tot = a[0] * (k[0] - 1) + a[1] * (k[1] - 1);
  long long ans[2] = {0};
  if (tot >= n) {
    ans[0] = 0;
  } else {
    ans[0] = min(a[0] + a[1], n - tot);
  }
  if (k[0] > k[1]) {
    swap(a[0], a[1]);
    swap(k[0], k[1]);
  }
  long long x = n / k[0];
  ans[1] += min(a[0], x);
  n -= ans[1] * k[0];
  long long y = n / k[1];
  ans[1] += min(a[1], y);
  cout << ans[0] << ' ' << ans[1] << '\n';
  return 0;
}
