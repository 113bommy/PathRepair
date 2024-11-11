#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105, MAXK = 2005;
double dpo[MAXN][MAXN], dp[MAXN][MAXN], ap;
int n, k, a[MAXN], cn[MAXN];
int main() {
  for (int i = 0; i < MAXN; i++) cn[i] = i * (i - 1) / 2;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  k = min(k, 900);
  ap = n * (n - 1) / 2 + n;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] < a[j]) dpo[i][j] = 1;
  for (int l = 1; l <= k; l++) {
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = 0;
        int d = j - i;
        for (int lsl = 0; lsl < j; lsl++)
          dp[i][j] += min(min(i + 1, lsl + 1), j - max(i, lsl)) * dpo[lsl][j];
        for (int lsr = i + 1; lsr < n; lsr++)
          dp[i][j] += min(n - max(j, lsr), min(lsr, j) - i) * dpo[i][lsr];
        for (int lr = 0; lr <= i; lr++)
          dp[i][j] += min(lr + 1, n - j) * (1 - dpo[lr][lr + d]);
        for (int lr = i + 1; lr + d < n; lr++)
          dp[i][j] += min(n - lr - d, i + 1) * (1 - dpo[lr][lr + d]);
        dp[i][j] +=
            (cn[i] + cn[n - j - 1] + i + n - j - 1 + cn[d - 1] + d - 1) *
            dpo[i][j];
        dp[i][j] /= ap;
      }
    swap(dp, dpo);
  }
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) ans += (1 - dpo[i][j]);
  cout.precision(10);
  cout << fixed << ans;
}
