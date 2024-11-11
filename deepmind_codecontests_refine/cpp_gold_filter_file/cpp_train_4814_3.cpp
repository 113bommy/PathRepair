#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e9 + 7;
ll bpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll modinv(ll n, ll p) { return bpow(n, p - 2, p); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    ll x;
    cin >> n >> x;
    ll temp;
    vector<ll> poor;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      if (temp - x < 0)
        poor.push_back(temp);
      else
        sum += temp;
    }
    sort(poor.rbegin(), poor.rend());
    ll check;
    int rich = n - poor.size();
    ll ans = n - (ll)poor.size(), psum = 0;
    for (int i = 0; i < poor.size(); i++) {
      psum += poor[i];
      check = sum + psum;
      if (check >= (rich + i + 1) * x)
        ans++;
      else
        break;
    }
    cout << ans << '\n';
  }
  return 0;
}
