#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod;
int power(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int modinv(ll x) { return power(x, mod - 2); }
ll a, b, x;
int main() {
  cin >> a >> b >> mod >> x;
  ll ans = 0;
  for (int i = 1; i < mod; ++i) {
    ll curr = (b * modinv(power(a, i))) % mod;
    ll start = (mod - 1) * ((i - curr + mod) % mod) + i;
    if (start > x) continue;
    ans += (x - start) / (mod * (mod - 1)) + 1;
  }
  cout << ans << "\n";
  return 0;
}
