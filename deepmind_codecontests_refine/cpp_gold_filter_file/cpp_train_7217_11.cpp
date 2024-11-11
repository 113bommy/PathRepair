#include <bits/stdc++.h>
using namespace std;
int n;
double a[25][25];
double dp[1 << 20];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  int MAX = (1 << n) - 1;
  dp[MAX] = 1;
  for (int i = MAX; i; i--) {
    int cnt = 0, tmp = i;
    while (tmp) {
      cnt += (tmp & 1);
      tmp >>= 1;
    }
    for (int j = 1; j <= n; j++) {
      if ((1 << j - 1) & i) continue;
      for (int k = 1; k <= n; k++) {
        if (!((1 << k - 1) & i)) continue;
        dp[i] += (double)dp[i | (1 << j - 1)] * a[k][j] / (cnt * (cnt + 1) / 2);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%.6lf ", dp[1 << i - 1]);
  return 0;
}
