#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e9 + 7;
long long int dp[300005][3];
long long int a[300005], b[300005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    dp[1][0] = 0;
    dp[1][1] = b[1];
    dp[1][2] = 2 * b[1];
    for (int pos = 2; pos <= n; pos++) {
      for (int i = 0; i < 3; i++) {
        dp[pos][i] = 5 * inf;
        for (int j = 0; j < 3; j++) {
          if (a[pos] + i != a[pos - 1] + j) {
            dp[pos][i] = min(dp[pos][i], dp[pos - 1][j] + i * b[pos]);
          }
        }
      }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
  }
}
