#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, SQRT = 320;
int n, a[N], dp[SQRT][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int k = 1; k < SQRT && k <= n; k++) {
    for (int i = n; i >= 1; i--) {
      int j = i + a[i] + k;
      if (j > n)
        dp[k][i] = 1;
      else
        dp[k][i] = 1 + dp[k][j];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k < SQRT)
      cout << dp[k][p] << "\n";
    else {
      int ans = 0;
      while (p <= n) {
        ans++;
        p += a[p] + k;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
