#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef map<char, ll> mpc;
typedef map<ll, ll> mpl;
typedef unordered_map<char, ll> umpc;
typedef unordered_map<ll, ll> umpl;
typedef set<ll> stl;
typedef set<char> stc;
typedef unordered_set<ll> ustl;
typedef unordered_set<char> ustc;
typedef deque<ll> dql;
ll fact[1000001];
ll ssbgcd(ll a, ll b) {
  if (!b) return a;
  return ssbgcd(b, a % b);
}
ll ssbpow(ll x, ll n, ll m = 1000000007) {
  if (!n) return 1 % m;
  ll u = ssbpow(x, n / 2, m);
  u = (u * u) % m;
  if (n & 1) u = (u * x) % m;
  return u;
}
ll ssbmmi(ll x, ll m) {
  if (ssbgcd(x, m) != 1) return 0;
  return ssbpow(x, m - 2, m);
}
ll ssbcoeff(ll n, ll k, ll m = 1000000007) {
  if (n < k) return 0;
  ll i, r;
  for (fact[0] = fact[1] = 1, i = 2; i <= n;
       fact[i] = (fact[i - 1] * i) % m, ++i)
    ;
  r = fact[n];
  r = (r * ssbmmi(fact[k], m)) % m;
  r = (r * ssbmmi(fact[n - k], m)) % m;
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    cout << n / 2;
    cout << "\n";
  }
  return 0;
}
