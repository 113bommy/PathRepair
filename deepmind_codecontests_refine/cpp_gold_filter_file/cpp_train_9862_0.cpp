#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const int32_t M = 998244353;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < (long long)n; ++i) cin >> a[i];
  for (long long i = 0; i < (long long)n; ++i) cin >> b[i];
  vector<array<long long, 2>> v(n);
  long long pref[N];
  for (long long i = 0; i < (long long)n; ++i) {
    v[i][0] = a[i];
    v[i][1] = b[i];
  }
  sort((v).begin(), (v).end());
  long long cur = 0;
  multiset<long long> s;
  map<long long, long long> mp;
  for (long long i = 0; i < (long long)n; ++i) {
    cur += v[i][1];
    if (i > k) {
      long long val = *s.begin();
      s.erase(s.begin());
      s.insert(v[i][1]);
      cur -= val;
      mp[v[i][0]] = cur;
    } else {
      mp[v[i][0]] = cur;
      s.insert(v[i][1]);
    }
  }
  for (long long i = 0; i < (long long)n; ++i) cout << mp[a[i]] << " ";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  long long a = 1;
  while (t--) {
    solve();
    a += 1;
  }
}
