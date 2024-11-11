#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lg(long long x) { return __builtin_clzll(1ll) - __builtin_clzll(x); }
void google() {
  static long long _gtest_ = 1;
  cout << "Case #" << _gtest_++ << ": ";
}
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  vector<long long> v3 = v;
  sort((v3).begin(), (v3).end());
  vector<pair<pair<long long, long long>, long long>> ans;
  for (long long i = n - 1; i >= 0; i--) {
    long long id = i;
    for (long long j = 0; j < n; j++) {
      if (v[j] == v3[i]) {
        id = j;
        break;
      }
    }
    vector<long long> v2 = v;
    if (id != i) {
      for (long long k = id; k < i; k++) {
        v2[k] = v[k + 1];
      }
      v2[i] = v3[i];
      ans.push_back({{id, i}, i - id});
    }
    v = v2;
  }
  cout << (long long)((ans).size()) << '\n';
  for (auto i : ans) {
    cout << i.first.first + 1 << ' ' << i.first.second + 1 << ' ' << i.second
         << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
