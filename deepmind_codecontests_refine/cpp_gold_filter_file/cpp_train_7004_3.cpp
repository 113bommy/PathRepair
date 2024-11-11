#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2), b(k), pos(n + 1), used(n + 1, 1);
  used[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
    used[b[i]] = 0;
  }
  int ans = 1;
  for (int it : b) {
    int j = pos[it];
    int cnt = used[a[j - 1]] + used[a[j + 1]];
    used[it] = 1;
    if (cnt == 2) {
      ans += ans;
      if (ans >= mod) ans -= mod;
    } else if (cnt == 0) {
      cout << "0\n";
      return;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
