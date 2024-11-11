#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int f(int i, int j) {
  if (j < 0 || i < 0 || j > i) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (j == i)
    dp[i][j] =
        (((long long)i - 1) * (f(i - 1, i - 1) + (long long)f(i - 2, i - 2))) %
        1000000007;
  else
    dp[i][j] =
        (f(i - 1, j - 1) * ((long long)j) + ((long long)i - j) * f(i - 1, j)) %
        1000000007;
  return dp[i][j];
}
int used[2001] = {};
int a[2001];
int main() {
  int x, n, bound = 0, total = 0, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == -1)
      total++;
    else
      used[x] = 1;
  }
  for (i = 0; i < n; i++) {
    if (used[i + 1] == 0 && a[i] == -1) bound++;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[1][1] = 0;
  printf("%d\n", f(total, bound));
  return 0;
}
