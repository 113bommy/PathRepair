#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 2;
const int maxm = (1 << 18) + 2;
int n;
double dp[maxm];
double a[maxn][maxn];
void DP() {
  dp[(1 << n) - 1] = 1;
  for (int i = (1 << n) - 1; ~i; i--) {
    int cnt = __builtin_popcount(i);
    for (int j = 0; j < n; j++)
      if ((1 << j) & i)
        for (int k = 0; k < n; k++)
          if (k != j && (1 << k) & i)
            dp[i - (1 << k)] += dp[i] * a[j][k] * 2 / cnt / (cnt - 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%lf", &a[i][j]);
  DP();
  for (int i = 0; i < n; i++) printf("%lf ", dp[1 << i]);
  return 0;
}
