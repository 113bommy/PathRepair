#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 200005;
long long a[M];
long long dp[M], dpp[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    memset((dp), 0, sizeof(dp));
    memset((dpp), 0, sizeof(dpp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[i] = a[i];
    }
    int sq = sqrt(n * 2);
    for (int k = 2; k <= sq + 2; k++) {
      long long mx = -1e18, sum = 0;
      int ptr = n;
      bool flg = 0;
      for (int i = n; i >= 1; i--) {
        sum += a[i];
        if ((ptr - i + 1) > k) {
          mx = max(mx, dp[ptr]);
          sum -= a[ptr];
          ptr--;
        }
        dpp[i] = -1e18;
        if (sum < mx) {
          dpp[i] = sum;
          flg = 1;
        }
      }
      if (!flg) {
        cout << k - 1 << "\n";
        break;
      }
      for (int i = 1; i <= n; i++) {
        dp[i] = dpp[i];
      }
    }
  }
  return 0;
}
