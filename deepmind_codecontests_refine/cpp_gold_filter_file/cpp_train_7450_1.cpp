#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;
const int INF = 2e9 + 3;
const double EPS = 1e-7;
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  long long l = 1, r = (1ll << n) - 1;
  int ans = n;
  while (r >= l) {
    auto m = (l + r) >> 1;
    if (m == k) {
      cout << ans;
      return;
    }
    if (k < m)
      r = m - 1;
    else
      l = m + 1;
    ans--;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) solve();
}
