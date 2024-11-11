#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using PII = pair<int, int>;
const ll mod = 1e9 + 7;
ll pow(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 1e5 + 10;
void solve() {
  int n;
  cin >> n;
  vector<int> c = vector<int>(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int all = (1 << n) - 1;
  bool ok = false;
  for (int i = 0; i < all; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      if ((j << 1) & i) {
        s += c[j];
      } else
        s -= c[j];
    }
    if (s % 360 == 0) {
      ok = true;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}
int main() {
  fastio();
  solve();
}
