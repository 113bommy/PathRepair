#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 1e9 + 7;
const int N = 1e5 + 5;
const int logN = 22;
int i, j, k, n, m, dp[1 << logN + 1], x, a[N];
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    dp[((1 << logN + 1) - 1) ^ x] = i;
    a[i] = x;
  }
  for (int j = 0; j <= logN; j++)
    for (int i = 0; i <= (1 << logN + 1) - 1; i++)
      if (dp[i] != -1 && (i & (1 << j))) dp[i - (1 << j)] = dp[i];
  for (int i = 1; i <= n; i++)
    printf("%d ", (dp[a[i]] == -1) ? -1 : a[dp[a[i]]]);
  return 0;
}
