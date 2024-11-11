#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M = 1000000007;
const ll N = 998244353;
ll power(ll x, ll y, ll p) {
  ll res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
ll inv(ll x, ll m) { return power(x, m - 2, m); }
ll nCr(ll n, ll r) {
  if (r == 0) return 1;
  vector<ll> fac(n);
  return (fac[n] * inv(fac[r], M) % M * inv(fac[n - r], M) % M) % M;
}
struct comp {
  template <typename T>
  bool operator()(const T &a, const T &b) {
    if (a.first == b.first)
      return (a.second < b.second);
    else
      return (a.first < b.first);
  }
};
bool mod(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second > b.second);
}
void sieve() {
  vector<bool> pr(1000000 + 1, 1);
  for (ll i = 2; i * i <= 1000000; i++)
    if (pr[i] == 1)
      for (ll j = i * i; j <= 1000000; j += i) pr[j] = 0;
}
bool isValid(ll i, ll j, ll n, ll m) {
  if (i >= 0 && i < n && j >= 0 && j < m) {
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m, i, j, k, num, num1, num2, flag = 0;
  ll q, x;
  cin >> q >> x;
  ll mex = 0;
  vector<ll> v(x);
  for (i = 0; i < q; i++) {
    cin >> num;
    v[num % x]++;
    ll prevMex = -1;
    while (mex != prevMex) {
      prevMex = mex;
      if (mex % x == 0) {
        if (v[mex % x] == mex / x + 1) {
          mex++;
        }
      } else {
        if (v[mex % x] == (mex + x - 1) / x) {
          mex++;
        }
      }
    }
    cout << mex << "\n";
  }
  return 0;
}
