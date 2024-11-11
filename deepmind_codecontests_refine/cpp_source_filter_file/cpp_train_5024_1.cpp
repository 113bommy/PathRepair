#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll sumXor = 0;
  for (auto i : a) {
    sumXor ^= i;
  }
  if (sumXor == 0) {
    cout << "DRAW"
         << "\n";
    return;
  }
  ll cnt0 = 0, cnt1 = 0;
  for (ll bit = 32; bit >= 0; bit--) {
    if ((sumXor >> bit) & 1) {
      for (auto i : a) {
        if ((i >> bit) & 1) {
          cnt1++;
        } else {
          cnt0++;
        }
      }
      break;
    }
  }
  if (cnt1 == 1 || cnt0 % 2 == 1) {
    cout << "WIN"
         << "\n";
  } else {
    cout << "LOSE"
         << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20),
      cout.setf(ios::fixed);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
