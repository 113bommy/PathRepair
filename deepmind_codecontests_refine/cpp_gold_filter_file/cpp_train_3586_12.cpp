#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 1e5 + 2;
const int M = 1 << 19;
const int inf = 2e9;
const long long linf = 1e18;
long long n, m, k;
int ok(long long mid) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += min(m, mid / i);
  }
  return ans >= k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  long long l = 1, r = n * m, ans = 0;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (ok(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << '\n';
  return 0;
}
