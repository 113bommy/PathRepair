#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
long long dp[510][510];
int n;
int a[510];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) dp[i][i] = 1;
  for (int j = 2; j <= n; j++)
    for (int i = j - 1; i >= 1; i--) {
      dp[i][j] = 0;
      for (int k = i + 1; k <= j; k++)
        if (a[i + 1] < a[k + 1] || k == j)
          (dp[i][j] += (dp[i + 1][k] * dp[k][j]) % MOD) %= MOD;
    }
  cout << dp[1][n];
  return 0;
}
