#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e18;
long long arr(long long n) { return 1ll * n * (n + 1) / 2; }
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (1ll * b * c < a) {
    cout << "-1\n";
    return;
  }
  auto check1 = [&](long long k) {
    assert(k >= 0);
    long long ret = 1ll * a * (k + 1);
    if (c <= d) {
      ret -= 1ll * k * c * b;
    } else {
      long long left = 1ll * k * d - c;
      if (left < 0) {
        left = -1;
      } else {
        left /= d;
      }
      long long cnt = k - left - 1;
      if (1.0 * arr(cnt) * d * b > INF) return -INF;
      if (cnt >= 0) ret -= 1ll * arr(cnt) * d * b;
      if (left >= 0) ret -= 1ll * (left + 1) * c * b;
    }
    return ret;
  };
  long long ans = a;
  const long long N = 1e9;
  long long l = 0, r = N;
  auto get = [&](long long ind) { return check1(ind); };
  while (r - l > 4) {
    long long m = (l + r) / 2;
    long long val1 = get(m);
    long long val2 = get(m + 1);
    ans = max({ans, val1, val2});
    if (val1 > val2) {
      r = m;
    } else {
      l = m;
    }
  }
  while (l <= r) {
    long long val = get(l++);
    ans = max(ans, val);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
}
