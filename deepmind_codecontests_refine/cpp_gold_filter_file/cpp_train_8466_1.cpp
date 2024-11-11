#include <bits/stdc++.h>
using namespace std;
const unsigned long long maxn = 1e6 + 5;
unsigned long long n, c, cnt = 0;
vector<pair<unsigned long long, unsigned long long>> vec;
unsigned long long func(unsigned long long k) {
  unsigned long long sum = 0;
  for (unsigned long long i = 0; i < n; i++)
    sum += vec[i].first * k / vec[i].second;
  if (sum <= c) return true;
  return false;
}
unsigned long long func2(unsigned long long k) {
  unsigned long long sum = 0;
  for (unsigned long long i = 0; i < n; i++)
    sum += vec[i].first * k / vec[i].second;
  if (sum == c) return true;
  return false;
}
unsigned long long solve() {
  cin >> n >> c;
  for (unsigned long long i = 0; i < n; i++) {
    unsigned long long a, b;
    cin >> a >> b;
    vec.push_back({a, b});
  }
  c = c - n;
  if (c < 0) {
    cout << 0;
    return 0;
  }
  unsigned long long l = 0, r = 1e16;
  while (l + 1 < r) {
    unsigned long long mid = (l + r) / 2;
    if (func(mid))
      l = mid;
    else
      r = mid;
  }
  if ((!func2(l)) || (l == 0)) {
    cout << 0;
    return 0;
  }
  unsigned long long ans = l;
  r = l, l = 1;
  while (l < r) {
    unsigned long long mid = (l + r) / 2;
    if (func2(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << ans - r + 1;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  unsigned long long t = 1;
  while (t--) solve();
}
