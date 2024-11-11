#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long long mod2 = 998244353;
const long long N = 1000 * 1000 + 10;
const long double pi = 3.141592653589793;
long long power(long long x, long long y, long long p = LLONG_MAX) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long ncr(long long n, long long r, long long m) {
  if (r > n) return 0;
  long long a = 1, b = 1, i;
  for (i = 0; i < r; i++) {
    a = (a * n) % m;
    --n;
  }
  while (r) {
    b = (b * r) % m;
    --r;
  }
  return (a * power(b, m - 2, m)) % m;
}
long long cond = 2 * 1e9;
void solve() {
  long long n;
  cin >> n;
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
  }
  set<long long> ans;
  for (auto i : s) {
    for (long long j = 2; j <= cond; j *= 2) {
      set<long long> s2;
      s2.insert(i);
      if (s.find(i + j) != s.end()) {
        s2.insert(i + j);
        if (s.find(i + j * 2) != s.end()) {
          s2.insert(i + j * 2);
        }
      }
      if (ans.size() < s2.size()) ans = s2;
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
