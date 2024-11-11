#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e6 + 6;
ll inv(ll a, ll m) { return a == 1 ? 1 : m - m * inv(m % a, a) / a; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p;
  ll a, b, x;
  cin >> a >> b >> p >> x;
  ll per = p * (p - 1LL);
  ll pa = 1, ans = 0;
  for (int i = 0; i < p - 1; ++i) {
    ll n = b * inv(pa, p) % p;
    ll d = ((i - n) % p + p) % p;
    ll y = i + (p - 1) * d;
    ll k = x < y ? 0 : (x - y) / per + 1;
    ans += k;
    pa = pa * a % p;
  }
  cout << ans << endl;
  return 0;
}
