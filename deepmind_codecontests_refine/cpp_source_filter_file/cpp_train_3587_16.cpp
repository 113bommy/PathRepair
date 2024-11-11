#include <bits/stdc++.h>
using namespace std;
const int N = 1500 + 7;
const int M = 70000;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
long long dp[N][N];
long long d[N][N];
long long mx[N];
int a[N][N];
int n, m;
int main() {
  cin >> n >> m;
  int u;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      scanf("%d", &u);
      dp[i][j] = dp[i][j - 1] + u;
    }
    if (i > 1) {
      if ((i & 1)) {
        mx[0] = (long long)-inf * 10000;
        for (int j = 1; j < n + 1; j++) {
          mx[j] = max(mx[j - 1], dp[i - 1][j]);
          if (j < n) dp[i][j + 1] = dp[i][j + 1] + mx[j];
        }
        dp[i][1] = -(long long)inf * 10000;
      } else {
        mx[n + 1] = (long long)-inf * 10000;
        for (int j = n; j > 0; j--) {
          mx[j] = max(mx[j + 1], dp[i - 1][j]);
          if (j > 1) dp[i][j - 1] += mx[j];
        }
        dp[i][n] = -(long long)inf * 10000;
      }
    }
  }
  long long ans = -(long long)inf * 10000;
  for (int i = 1; i < m + 1; i++) ans = max(ans, dp[n][i]);
  cout << ans << endl;
}
