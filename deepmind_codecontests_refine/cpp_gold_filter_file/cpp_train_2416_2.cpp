#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &&i : v) {
      cin >> i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int ok = 0;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (v[i] == v[j]) ok++;
      }
      if (ok) {
        for (int j = 0; j < 10; ++j) {
          v[i][0] = '0' + j;
          int okk = 0;
          for (int k = 0; k < n; ++k) {
            if (i == k) continue;
            if (v[i] == v[k]) okk++;
          }
          if (!okk) {
            ans++;
            break;
          }
        }
      }
    }
    cout << ans << "\n";
    for (auto &&i : v) {
      cout << i << "\n";
    }
  }
  return 0;
}
