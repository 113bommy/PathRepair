#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
const int oo = 1e9 + 7;
const int maxBit = (1 << 16) + 1;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int n, a[maxN], bit[65];
int dp[maxN][maxBit], pre[maxN][maxBit], value[maxN][maxBit];
void Print(int i, int mask) {
  if (i > 0) {
    Print(i - 1, pre[i][mask]);
    printf("%d ", value[i][mask]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d\n", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i <= maxN - 1; ++i)
    for (int j = 0; j <= maxBit - 1; ++j) dp[i][j] = oo;
  dp[0][0] = 0;
  for (int i = 1; i <= 60; ++i)
    for (int j = 0; j <= 15; ++j)
      if (i % prime[j] == 0) bit[i] |= (1 << j);
  int cnt = (1 << n) - 1;
  for (int i = 0; i <= n - 1; ++i)
    for (int mask = 0; mask <= cnt; ++mask)
      for (int x = 1; x <= 59; ++x) {
        if (mask & bit[x]) continue;
        int newmask = mask | bit[x];
        if (dp[i][mask] + abs(x - a[i + 1]) < dp[i + 1][newmask]) {
          dp[i + 1][newmask] = dp[i][mask] + abs(x - a[i + 1]);
          pre[i + 1][newmask] = mask;
          value[i + 1][newmask] = x;
        }
      }
  int mask = 0, va = oo;
  for (int i = 0; i <= cnt; ++i)
    if (dp[n][i] < va) {
      va = dp[n][i];
      mask = i;
    }
  Print(n, mask);
  return 0;
}
