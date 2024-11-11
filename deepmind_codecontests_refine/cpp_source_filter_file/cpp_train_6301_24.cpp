#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
inline long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline long long mul(long long x, long long y) { return (x * 1ll * y) % mod; }
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline void io() {}
signed main() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<long long> v;
  long long res = n;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      v.push_back(i);
    }
  }
  if (k == 1) {
    for (long long i = 0; i < v.size() - 1; i++) {
      res = min(res, v[i + 1] - v[i]);
    }
    cout << res << endl;
    return 0;
  }
  for (long long i = 0; i < n - k; i++) {
    long long dis = v[i + k] - v[i];
    auto it = lower_bound(v.begin(), v.end(), v[i] + dis / 2);
    res = min(res, max(v[i + k] - (*it), (*it) - v[i]));
    --it;
    res = min(res, max(v[i + k] - (*it), (*it) - v[i]));
  }
  cout << res << endl;
  return 0;
}
