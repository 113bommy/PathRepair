#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long double eps = 1e-6;
const long long maxn = 1e5;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
  long long ans = 0;
  for (long long t = 0; t <= maxn; ++t) {
    long long cnt = 0;
    for (long long i = 0; i < n; ++i) {
      if (t < v[i].second)
        cnt += (s[i] == '1');
      else if (((t - v[i].second) / v[i].first) % 2 == (long long)(s[i] - '0'))
        ++cnt;
    }
    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}
