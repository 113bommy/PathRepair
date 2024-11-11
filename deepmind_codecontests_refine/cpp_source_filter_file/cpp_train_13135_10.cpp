#include <bits/stdc++.h>
using namespace std;
int dp[1 << 22];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  function<void(int, int, bool)> update = [&](int num, int k, bool flag) {
    if (k > 21 || dp[num] >= 2) return;
    if (flag) dp[num]++;
    update(num, k + 1, false);
    if ((num >> k) & 1) update(num ^ (1 << k), k + 1, true);
  };
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int res = 0, t = 0;
    for (int j = 21; j >= 0; j--) {
      if ((a[i] >> j) & 1)
        res |= (1 << j);
      else if (dp[t | (1 << j)] >= 2)
        res |= (1 << j), t |= (1 << j);
    }
    update(a[i], 0, true);
    if (i < n - 2) ans = max(ans, res);
  }
  cout << ans << "\n";
  return 0;
}
