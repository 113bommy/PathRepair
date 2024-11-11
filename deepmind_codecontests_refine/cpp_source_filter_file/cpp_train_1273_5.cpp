#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
int a[200010], b[200010];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int x;
  for (int i = 1; i <= n; i++) cin >> x, b[i] = a[i] - x;
  sort(b + 1, b + n + 1);
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (b[i] > 0)
      ans += n - i;
    else {
      int j = upper_bound(b + 1, b + n + 1, -b[i]) - b;
      ans += max(0, n - j + 1);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
