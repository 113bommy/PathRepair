#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2 + 2, MAX_K = 800;
int n, k;
int Arr[MAX_N];
double ans;
double dp[MAX_K][MAX_N][MAX_N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  k = min(k, MAX_K - 1);
  for (int i = 1; i <= n; i++) cin >> Arr[i];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) dp[0][i][j] = (Arr[i] > Arr[j]);
  for (int p = 1; p <= k; p++)
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        for (int q = 1; q <= i; q++) {
          dp[p][i][j] += dp[p - 1][q][j] * min(q, j - i);
          if (1 <= q - (j - i))
            dp[p][i][j] +=
                (1.0 - dp[p - 1][q - (j - i)][q]) * min(q - (j - i), n - j + 1);
        }
        for (int q = i + 1; q < j; q++) {
          dp[p][i][j] += dp[p - 1][q][j] * min(i, j - q);
          if (1 <= i - (j - q))
            dp[p][i][j] +=
                (1.0 - dp[p - 1][i - (j - q)][q]) * min(i - (j - q), n - j + 1);
        }
        for (int q = j; q <= n; q++)
          dp[p][i][j] += (1.0 - dp[p - 1][i + (q - j)][q]) * min(i, n - q + 1);
        for (int q = i + 1; q <= j; q++)
          dp[p][i][j] += dp[p - 1][i][q] * min(q - i, n - j + 1);
        for (int q = j + 1; q <= n; q++)
          dp[p][i][j] += dp[p - 1][i][q] * min(j - i, n - q + 1);
        dp[p][i][j] +=
            dp[p - 1][i][j] * ((i - 1) * i / 2 + (j - i - 1) * (j - i) / 2 +
                               (n - j) * (n - j + 1) / 2);
        dp[p][i][j] /= n * (n + 1) / 2.0;
      }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ans += dp[k][i][j];
  cout << fixed << setprecision(90) << ans << "\n";
}
