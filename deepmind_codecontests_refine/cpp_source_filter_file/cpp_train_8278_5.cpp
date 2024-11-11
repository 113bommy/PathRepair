#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 1;
const int32_t MOD = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 1e5 + 5;
long long n, k;
long long a[N], b[N];
bool check(long long c, long long magic_powder) {
  for (long long i = 0; i < n; i++) {
    if (b[i] / a[i] < c) {
      long long req = c * a[i] - b[i];
      if (magic_powder < req) {
        return false;
      }
      magic_powder -= req;
    }
  }
  return true;
}
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long l = 0, r = INF;
  long long ans;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    if (check(mid, k)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
