#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;
using ll = long long;
using ld = long double;
using itn = int;
using dd = double;
mt19937 gen(41);
const dd eps = 1e-7;
const ll MAXN = 2097152;
const ll INF = 1e9;
const dd pi = acos(dd(-1));
ll gcd(ll a, ll b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
ll binpow(ll a, ll n) {
  ll binpow_mod = 1e9 + 7;
  ll res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
    a %= binpow_mod;
    res %= binpow_mod;
  }
  return res;
}
struct Point {
  ll x, y;
  bool z;
  void scan() { cin >> x >> y; }
  Point(ll X = 0, ll Y = 0, bool Z = 0) {
    x = X;
    y = Y;
    z = Z;
  }
  ll operator*(Point &a) { return x * a.y - y * a.x; }
  bool operator==(Point &a) { return x == a.x && y == a.y; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int q;
  cin >> q;
  while (q--) {
    int n, x;
    cin >> n >> x;
    cout << x * 2 << '\n';
  }
  return 0;
}
