#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
bool f(ll a, ll b) {
  if (a == 0) return false;
  if (!f(b % a, a)) return true;
  ll x = b / a, mod = b + 1;
  return ((x % mod) % 2) == 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (f(a, b) ? "First" : "Second") << '\n';
  }
  return 0;
}
