#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
long long power(long long a, long long b = mod - 2) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long p, k;
  cin >> p >> k;
  if (k == 0) {
    cout << power(p - 1, p) << '\n';
    return 0;
  }
  if (k == 1) {
    cout << power(p, p) << '\n';
    return 0;
  }
  long long ans = 1;
  set<long long> s;
  for (long long i = (1); i <= (p - 1); i++) s.insert(i);
  while (!s.empty()) {
    long long x = *s.begin();
    ans = ans * p % mod;
    while (s.find(x) != s.end()) {
      s.erase(x);
      x = x * k % p;
    }
  }
  cout << ans;
}
