#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int sum[n + 1];
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int ans = INT_MIN;
  int total = sum[n];
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int range = j - i + 1;
      int ones = (sum[j] - sum[i - 1]);
      int zero = range - ones;
      ans = max(ans, total - (ones) + max(zero, ones));
    }
  }
  if (ans == n) ans--;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  for (int i = 1; i <= t; i++) solve();
}
