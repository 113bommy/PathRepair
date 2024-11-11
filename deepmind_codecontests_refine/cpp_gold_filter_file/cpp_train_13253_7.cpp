#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
template <typename T>
void DEBUG(string label, T value) {
  cerr << "[" << label << " = " << value << "]\n";
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  const int MOD = 1e9 + 7;
  if (k == 1 || k > n) {
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
      ans = ans * m % MOD;
    }
    cout << ans << '\n';
  } else if (k == n) {
    if (n % 2 == 0) {
      ll ans = 1;
      for (int i = 0; i < n / 2; ++i) {
        ans = ans * m % MOD;
      }
      cout << ans << '\n';
    } else {
      ll ans = m;
      for (int i = 0; i < (n - 1) / 2; ++i) {
        ans = ans * m % MOD;
      }
      cout << ans << '\n';
    }
  } else if (k % 2 == 0) {
    cout << m << '\n';
  } else {
    ll ans = (1LL * m * m) % MOD;
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
