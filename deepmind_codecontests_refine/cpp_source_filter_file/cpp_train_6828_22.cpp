#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long mxx = 1e5 + 7;
int dp[mxx][501];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (auto &x : a) cin >> x;
  for (int k = 1; k <= min(500, n); k++) {
    for (int i = n - 1; i >= 0; i--) {
      dp[i][k] = 1;
      if (i + a[i] + k < n) dp[i][k] += dp[i + a[i] + k][k];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    --p;
    if (p <= 500)
      cout << dp[p][k] << "\n";
    else {
      int ans = 0;
      while (p < n) {
        ans++;
        p = p + a[p] + k;
      }
      cout << ans << "\n";
    }
  }
}
