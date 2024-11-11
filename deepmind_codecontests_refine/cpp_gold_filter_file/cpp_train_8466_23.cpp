#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
long long n, c, cnt = 0;
vector<pair<long long, long long>> vec;
bool func(long long k) {
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += (vec[i].first * k / vec[i].second);
  if (sum <= c)
    return true;
  else
    return false;
}
bool func2(long long k) {
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += (vec[i].first * k / vec[i].second);
  if (sum == c)
    return true;
  else
    return false;
}
long long solve() {
  cin >> n >> c;
  c -= n;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    vec.push_back({a, b});
  }
  if (c < 0) {
    cout << 0;
    return 0;
  }
  long long l = 0, r = 1e16;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (func(mid))
      l = mid;
    else
      r = mid;
  }
  if (!func2(l) || (l == 0)) {
    cout << 0;
    return 0;
  }
  long long ans = l;
  r = l;
  l = 0;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (func2(mid))
      r = mid;
    else
      l = mid;
  }
  r--;
  cout << ans - r;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long t = 1;
  while (t--) solve();
}
