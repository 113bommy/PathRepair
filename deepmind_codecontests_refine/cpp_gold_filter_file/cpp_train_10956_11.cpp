#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll modpow(ll a, ll b) {
  if (b == 0) return 1;
  if (b % 2) return a * modpow(a, b - 1);
  ll p = modpow(a, b / 2);
  return p * p;
}
string binary(ll x, int m) {
  string res;
  while (x) {
    res.push_back('0' + (x % 2));
    x /= 2;
  }
  while (res.size() < m) res.push_back('0');
  reverse((res).begin(), (res).end());
  return res;
}
signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    ll n, m;
    cin >> n >> m;
    ll x = modpow(2, m);
    set<ll> A;
    for (int i = 0; i < (int)(n); ++i) {
      string s;
      cin >> s;
      ll x = 0;
      for (int i = 0; i < (int)(m); ++i)
        if (s[i] == '1') x += (1LL << (m - i - 1));
      A.insert(x);
    }
    ll key = (x - n - 1) / 2;
    ll left = 0, right = x;
    while (right - left > 1) {
      ll mid = (right + left) / 2;
      ll v = mid - distance(A.begin(), A.lower_bound(mid));
      if (v > key)
        right = mid;
      else
        left = mid;
    }
    cout << binary(left, m) << endl;
  }
}
