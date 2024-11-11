#include <bits/stdc++.h>
using namespace std;
const int N = 3333;
long long a[N], b[N];
long long dp[N][N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] = i - 1;
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  memset(dp, 127, sizeof(dp));
  int bn = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= bn; i++) {
    dp[1][i] = min(dp[1][i - 1], abs(a[1] - b[i]));
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= bn; j++) {
      dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(a[i] - b[j]));
    }
  }
  cout << dp[n][bn] << endl;
  return 0;
}
