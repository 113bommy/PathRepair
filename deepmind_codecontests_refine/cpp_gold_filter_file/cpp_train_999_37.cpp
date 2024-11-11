#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 300000;
int n;
int a[MAXN];
int dp[MAXN + 1][31];
void upd(int &a, int b) {
  if (a == -1 || b > a) a = b;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  int sum = 0;
  for (int i = (0); i < (n); ++i) sum += a[i];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j <= (30); ++j)
      if (dp[i][j] != -1) {
        int x = a[i] / 1000;
        if (j + x <= 30) upd(dp[i + 1][j + x], dp[i][j]);
        int d = min(10 * x, j);
        upd(dp[i + 1][j - d], dp[i][j] + d);
      }
  int mx = -1;
  for (int j = (0); j <= (30); ++j) upd(mx, dp[n][j]);
  int ret = sum - 100 * mx;
  printf("%d\n", ret);
}
int main() {
  run();
  return 0;
}
