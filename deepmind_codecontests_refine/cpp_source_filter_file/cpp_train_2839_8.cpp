#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
std::ifstream ___in("input.in");
using namespace std;
using ll = long long;
static const bool tc = 0;
static const ll mod = LLONG_MAX - 24;
void solve() {
  ll n, q, a[100005], d[100005], s = 0, fs;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) d[i] = a[i + 1] - a[i], s += max(0ll, d[i]);
  fs = a[1];
  cout << ceil((a[1] + s) / 2.0) << "\n";
  cin >> q;
  while (q--) {
    ll l, r, x;
    cin >> l >> r >> x;
    if (l == 1) fs += x;
    if (l > 1) {
      s -= max(0ll, d[l - 1]);
      d[l - 1] += x;
      s += max(0ll, d[l - 1]);
    }
    if (r < n) {
      s -= max(0ll, d[r]);
      d[r] -= x;
      s += max(0ll, d[r]);
    }
    cout << (ll)ceil((fs + s) / 2.0) << "\n";
  }
}
int main() {
  srand(time(0));
  int T = 1;
  if (tc) cin >> T;
  for (int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
