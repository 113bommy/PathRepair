#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const int maxn = 1e6 + 5;
ll pw(ll x, ll y, ll mod) {
  ll res = 1;
  while (y) {
    if (y % 2) res = res * x % mod;
    x = x * x % mod;
    y = y / 2;
  }
  return ((res % mod) + mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, m, a, Q;
  cin >> n >> m >> a >> Q;
  ll phi = 1;
  {
    ll cur = a;
    while (cur != 1) {
      phi++;
      cur = cur * a % Q;
    }
  }
  vector<ll> powers = {1};
  ll C = 1;
  for (int i = 1; i < n; i++) {
    C = C * (m - i + 1) % phi * pw(i, phi - 2, phi) % phi;
    powers.push_back(C + powers.back() % phi);
  }
  reverse(powers.begin(), powers.end());
  for (ll p : powers) {
    cout << pw(a, p, Q) << " ";
  }
  cout << endl;
  return 0;
}
