#include <bits/stdc++.h>
#pragma GCC optimize "03"
using namespace std;
const long long int inf = INT_MAX;
const double eps = 0.0000001;
const double PI = acos(-1.0);
const long long int MOD = 1e9 + 7;
const long long int N = 1e5 + 5;
long long int n, k;
long long int sum(long long int x) { return (k - 1) * k / 2 - (x - 1) * x / 2; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long int l = 0, r = k - 1;
  long long int ans = -1;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    if (sum(mid) <= n - 1) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if ((k - 1) * k / 2 < n - 1)
    cout << -1;
  else if (n == 1)
    cout << 0;
  else if (k >= n)
    cout << 1;
  else if (sum(ans) == n - 1)
    cout << k - ans;
  else
    cout << k - ans + 1;
  return 0;
}
