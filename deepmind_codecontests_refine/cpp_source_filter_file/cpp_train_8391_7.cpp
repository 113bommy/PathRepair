#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> v(m);
  for (long long i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
  vector<long long> a;
  for (long long d = 1; d <= 100; d++) {
    long long g = 1;
    for (long long i = 0; i < m; i++) {
      if (!(d * (v[i].second - 1) < v[i].first &&
            d * (v[i].second + 1) > v[i].first))
        g = 0;
    }
    if (g == 1) a.push_back(d);
  }
  long long ans = -1;
  for (auto d : a) {
    if (ans != -1 && ans != n / d + bool(n % d)) {
      cout << -1;
      return 0;
    } else
      ans = n / d + bool(n % d);
  }
  cout << ans;
}
