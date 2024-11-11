#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const long long INF = 1e15;
int n;
int a[N], b[N];
long long dp[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= (i - 1);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++) dp[i][j] = INF;
  for (int i = 0; i <= n; i++) dp[0][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(a[i] - b[j]));
    }
  printf("%lld\n", dp[n][n]);
  return 0;
}
