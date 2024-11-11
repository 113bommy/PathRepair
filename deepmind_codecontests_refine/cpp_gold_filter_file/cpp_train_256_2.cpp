#include <bits/stdc++.h>
using namespace std;
const int N = 330000;
int a[N], m;
long long dp[5500][5500];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  m = n / k;
  int b = k - n % k, c = n % k;
  for (int i = 0; i < 66; i++)
    for (int j = 0; j < 66; j++) dp[i][j] = LLONG_MIN;
  long long tot = 0;
  for (int i = 1; i < n; i++) tot += abs(a[i + 1] - a[i]);
  for (int i = 0; i <= b; i++) {
    for (int j = 0; j <= c; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (i == 1 && j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (i == 0 && j == 1) {
        dp[i][j] = 0;
        continue;
      }
      if (i)
        dp[i][j] =
            max(dp[i][j], dp[i - 1][j] + abs(a[m * (i - 1) + (m + 1) * j] -
                                             a[m * (i - 1) + (m + 1) * j + 1]));
      if (j)
        dp[i][j] =
            max(dp[i][j], dp[i][j - 1] + abs(a[m * i + (m + 1) * (j - 1)] -
                                             a[m * i + (m + 1) * (j - 1) + 1]));
    }
  }
  cout << tot - dp[b][c] << endl;
  return 0;
}
