#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 1005;
int n, K;
long long f[20];
double p[maxn], dp[maxn][maxn];
long long Solve(long long N) {
  if (!N) return 0;
  int a[100], res = 0;
  while (N) a[res++] = N % 10, N /= 10;
  long long ans = 0;
  if (a[res - 1] > 1)
    ans += f[res - 1];
  else {
    for (int i = 0; i < res - 1; i++) ans += f[i] * a[i];
    ans++;
  }
  for (int i = 0; i < res - 1; i++) ans += f[i];
  return ans;
}
int main() {
  f[0] = 1;
  for (int i = 1; i <= 18; i++) f[i] = 10ll * f[i - 1];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long L, R;
    scanf("%I64d%I64d", &L, &R);
    p[i] = 1.0 * (Solve(R) - Solve(L - 1)) / (R - L + 1);
  }
  scanf("%d", &K);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        dp[i][j] = (1.0 - p[i]) * dp[i - 1][j];
      else
        dp[i][j] = p[i] * dp[i - 1][j - 1] + (1.0 - p[i]) * dp[i - 1][j];
    }
  double ans = 0;
  for (int i = n; i >= 0; i--)
    if (i * 100 >= K * n)
      ans += dp[n][i];
    else
      break;
  printf("%.12f\n", ans);
  return 0;
}
