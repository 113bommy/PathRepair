#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
int n, m;
ll fastpow(ll a, ll n, ll m) {
  ll res = 1;
  while (n) {
    if (n & 1) res = (res * a) % m;
    n >>= 1;
    a = (a * a) % m;
  }
  return res;
}
ll add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll sub(ll a, ll b, ll m) { return ((a - b) % m + m) % m; }
ll mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll div(ll a, ll b, ll m) { return mul(a, fastpow(b, m - 2, m), m); }
void code() {
  cin >> n >> m;
  cout << fastpow(2, m + n, mod) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t-- > 0) {
    code();
  }
}
