#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MD = 1000000007;
ll md = 998244353;
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
ll pow_2(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
bool isPrime(ll a) {
  for (ll i = 3; (i * i) <= a; i += 2) {
    if ((a % i) == 0) return false;
  }
  if ((a != 2) && ((a % 2) == 0)) return false;
  if (a == 1) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll arr[n];
    ll sum = 0;
    ll x = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      x ^= arr[i];
    }
    cout << "2" << endl;
    cout << x << " " << x + sum << endl;
  }
  return 0;
}
