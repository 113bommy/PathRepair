#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
mt19937 rnd(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll b, q, l, m;
  cin >> b >> q >> l >> m;
  vector<ll> a(m);
  for (auto &i : a) {
    cin >> i;
  }
  if (abs(b) > l) {
    cout << 0;
    return 0;
  }
  sort(a.begin(), a.end());
  if (b == 0 || q == 0) {
    if (b == 0) {
      if (binary_search(a.begin(), a.end(), 0)) {
        cout << 0;
      } else {
        cout << "inf";
      }
      return 0;
    }
    if (binary_search(a.begin(), a.end(), 0)) {
      cout << !binary_search(a.begin(), a.end(), 0);
    } else {
      cout << "inf";
    }
    return 0;
  }
  if (abs(q) == 1) {
    if (q == 1) {
      if (binary_search(a.begin(), a.end(), b)) {
        cout << 0;
      } else {
        cout << "inf";
      }
    } else {
      if (binary_search(a.begin(), a.end(), b) +
              binary_search(a.begin(), a.end(), -b) ==
          2) {
        cout << 0;
      } else {
        cout << "inf";
      }
    }
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < 35; ++i) {
    if (binary_search(a.begin(), a.end(), b)) {
      if (abs(b) > l) {
        cout << cnt;
        break;
      }
    } else {
      if (abs(b) > l) {
        cout << cnt;
        break;
      }
      ++cnt;
    }
    b *= q;
  }
  return 0;
}
void solve() {}
