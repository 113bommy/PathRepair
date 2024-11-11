#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
int mod;
ll pw(ll a, int b) {
  if (!b) {
    return 1;
  }
  ll v = pw(a, b / 2);
  v = (v * v) % mod;
  if (b & 1) {
    v = (v * a) % mod;
  }
  return v;
}
ll ans = 0;
ll norm(ll x) {
  x %= mod;
  if (x < 0) {
    x += mod;
  }
  return x;
}
const int N = 300228;
ll invs[N];
void go(ll mul, int a, int b) {
  mul %= mod;
  ll cans = 0;
  for (int i = 2; i <= a + b; ++i) {
    int al = max(1, i - b);
    int ar = min(a, i - 1);
    if (al <= ar) {
      ll c = ar - al + 1;
      cans += c * invs[i];
      cans %= mod;
    }
  }
  ans = (ans + cans * mul) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  int n, k;
  cin >> n >> k >> mod;
  for (int i = 1; i <= n; ++i) {
    invs[i] = pw(i, mod - 2);
  }
  int c = 1;
  for (int i = 1; i < k; ++i) {
    c *= 2;
    if (c >= n) {
      cout << 0 << "\n";
      return 0;
    }
  }
  int sz = n / c;
  ll bc = n % c;
  go(bc * (bc - 1), sz + 1, sz + 1);
  go((c - bc) * (c - bc - 1), sz, sz);
  go(2ll * bc * (c - bc), sz, sz + 1);
  ll all = ll(n) * ll(n - 1) / 2;
  cout << norm((all - ans) * invs[2]) << "\n";
}
