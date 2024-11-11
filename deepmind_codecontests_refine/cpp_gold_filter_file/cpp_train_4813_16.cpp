#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll md = 1000000007;
ll exp(ll a, ll b) {
  ll r = 1ll;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % md);
      r = (r + md) % md;
    }
    b /= 2;
    a = (a % md) * (a % md);
    a = (a + md) % md;
  }
  return (r + md) % md;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll Min(ll a, ll b) {
  if (a < b) return a;
  return b;
}
ll Max(ll a, ll b) {
  if (a > b) return a;
  return b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, i, j, k, A, B, C;
    cin >> a >> b >> c;
    ll ans = 0xffffffff;
    for (i = 1; i <= 1e5; ++i) {
      for (j = i; j <= 1e5; j += i) {
        ll x = c % j;
        if (x < (j - x))
          k = c - x;
        else
          k = c + (j - x);
        x = abs(a - i) + abs(b - j) + abs(c - k);
        if (x < ans) {
          ans = x;
          A = i;
          B = j;
          C = k;
        }
      }
    }
    cout << ans << endl << A << " " << B << " " << C << " ";
    cout << '\n';
  }
  return 0;
}
