#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9 + 7;
int a[35];
double dp[35][35][205];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int t = 0; t < n; t++) {
      if (i == t) continue;
      if (i < t)
        dp[i][t][0] = 0;
      else
        dp[i][t][0] = 1;
    }
  double con = 1.0 / (n * (n + 1) / 2);
  for (int t = 0; t < k; t++)
    for (int i1 = 0; i1 < n; i1++)
      for (int i2 = 0; i2 < n; i2++)
        for (int l = 0; l < n; l++)
          for (int r = l; r < n; r++) {
            int ind1, ind2;
            ind1 = ((i1 >= l && i1 <= r) ? l + r - i1 : i1);
            ind2 = ((i2 >= l && i2 <= r) ? l + r - i2 : i2);
            dp[ind1][ind2][t + 1] += con * dp[i1][i2][t];
          }
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int t = i + 1; t < n; t++) {
      if (a[i] < a[t])
        ans += dp[i][t][k];
      else
        ans += dp[t][i][k];
    }
  cout << fixed << setprecision(10) << ans << "\n";
}
