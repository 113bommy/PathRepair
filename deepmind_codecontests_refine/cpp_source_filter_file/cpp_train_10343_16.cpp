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
    b >>= 1;
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
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  if (n == 3) {
    cout << "5";
    return 0;
  }
  for (long long i = 1; i < 100; i += 2) {
    long long val = (i + 1) * (i + 1) / 4 + (i * i) / 4;
    if (val >= n) {
      cout << i;
      return 0;
    }
  }
  cout << '\n';
  return 0;
}
