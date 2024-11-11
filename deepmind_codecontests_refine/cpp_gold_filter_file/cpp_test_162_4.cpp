#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, mod = 1e9 + 7, ans, a[200011];
string s, s2;
bool flag, vis[2000111];
vector<long long> v, tmp;
bool okD(long long d, long long mid, long long i) {
  return tmp[i] - 3 * d >= mid;
}
bool ok(long long mid) {
  tmp = v;
  for (long long i = n - 1; i >= 2; i--) {
    long long d = tmp[i] - mid;
    d = min(v[i], d);
    if (d < 0) return false;
    d /= 3;
    tmp[i] -= d * 3;
    tmp[i - 1] += d;
    tmp[i - 2] += 2 * d;
  }
  long long ret = 1e9;
  for (long long i = 0; i < n; i++) ret = min(ret, tmp[i]);
  return ret >= mid;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    v.resize(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long L = 1, R = 1e9;
    while (L <= R) {
      long long mid = (L + R + 1) / 2;
      if (ok(mid))
        ans = mid, L = mid + 1;
      else
        R = mid - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
