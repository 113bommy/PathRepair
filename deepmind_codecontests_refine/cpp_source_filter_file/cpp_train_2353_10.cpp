#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int n, k, q;
int dp[2][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> q;
  int aa[n + 5], bb[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> aa[i] >> bb[i];
  }
  sort(aa, aa + n);
  sort(bb, bb + n);
  for (int i = 1; i <= N; i++) {
    int l = int(upper_bound(aa, aa + n, i) - aa);
    int r = int(lower_bound(bb, bb + n, i) - bb);
    dp[0][i] = l - r;
  }
  for (int i = 1; i <= N; i++) {
    dp[1][i] += dp[1][i - 1] + (dp[0][i] >= k);
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << dp[1][b] - dp[1][a - 1] << '\n';
  }
  return 0;
}
