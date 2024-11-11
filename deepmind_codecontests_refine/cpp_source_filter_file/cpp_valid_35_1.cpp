#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int ri() {
  int x;
  cin >> x;
  return x;
}
ll rl() {
  ll x;
  cin >> x;
  return x;
}
string rs() {
  string x;
  cin >> x;
  return x;
}
const ll mod = 1e9 + 7;
void solve() {
  int n = ri(), m = ri();
  bitset<32> a(n), b(m);
  int ans = 0;
  for (int i = 31; i >= 0; i--) {
    if (a[i] && !b[i]) break;
    ans += (1 << i) * (a[i] ^ b[i]);
  }
  cout << ans;
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  cin >> q;
  while (q--) solve();
}
