#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = ((res % mod) * (x % mod)) % mod;
    y = y >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return res;
}
long long max(long long a, long long b) {
  long long ans = a > b ? a : b;
  return ans;
}
long long min(long long a, long long b) {
  long long ans = a < b ? a : b;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long> > v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].second;
    cin >> v[i].first;
  }
  sort(v.rbegin(), v.rend());
  long long len = 0;
  set<long long> s;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    len += v[i].second;
    ans = max(ans, v[i].first * len);
    s.insert(v[i].second);
    if (s.size() == k) {
      len -= *(s.begin());
      s.erase(*(s.begin()));
    }
  }
  cout << ans;
}
