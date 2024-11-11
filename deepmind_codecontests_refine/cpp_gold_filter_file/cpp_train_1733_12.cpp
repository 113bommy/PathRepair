#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int T;
vector<int> vec;
vector<pii> vv;
inline ll get(int p, ll limit) {
  ll ans = 0;
  for (pii tmp : vv) {
    ans += limit / tmp.second * tmp.first;
  }
  return ans;
}
inline ll calc(int p, int x, ll mid) { return get(p, mid) - get(p, x); }
inline void build_vec(int p) {
  for (int d = 2; d * d <= p; d++) {
    if (p % d) continue;
    vec.push_back(d);
    while (p % d == 0) p /= d;
  }
  if (p > 1) vec.push_back(p);
  int n = (int)vec.size();
  for (int mask = 0; mask < (1 << n); mask++) {
    int t = 1;
    for (int i = 0; i < n; i++)
      if (mask >> i & 1) t *= vec[i];
    int z = (__builtin_popcount(mask) & 1 ? -1 : +1);
    vv.push_back({z, t});
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    int x, p, k;
    cin >> x >> p >> k;
    vec.clear();
    vv.clear();
    build_vec(p);
    ll low = x, high = 3e18;
    while (high - low > 1) {
      ll mid = (low + high) >> 1;
      if (calc(p, x, mid) >= k)
        high = mid;
      else
        low = mid;
    }
    cout << high << '\n';
  }
}
