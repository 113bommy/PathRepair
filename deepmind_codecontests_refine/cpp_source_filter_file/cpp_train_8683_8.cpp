#include <bits/stdc++.h>
using namespace std;
int a[301], t[301];
int dp[301][150001];
int sp[18][150001];
int n, m, d, ans = 1e9, tt;
long long vv = 0;
int rr[150001];
void build(int x) {
  for (int i = 1; i <= n; i++) sp[0][i] = dp[x][i];
  int temp = log(n + 0.0) / log(2.0);
  for (int i = 1; i <= temp; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
}
int f2(int x, int y) {
  int temp = rr[y - x + 1];
  return min(sp[temp][x], sp[temp][y - (1 << temp) + 1]);
}
int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 1; i <= m; i++)
    scanf("%d %I64d %d", &a[i], &tt, &t[i]), vv += tt;
  for (int i = 0; i <= 17; i++) rr[1 << i] = 1;
  rr[0] = -1;
  for (int i = 1; i <= n; i++) rr[i] += rr[i - 1];
  for (int i = 1; i <= n; i++) dp[1][i] = abs(a[1] - i);
  for (int i = 2; i <= m; i++) {
    build(i - 1);
    for (int j = 1; j <= n; j++)
      dp[i][j] = f2(max((long long)1, j - (long long)d * (t[i] - t[i - 1])),
                    min((long long)n, j + (long long)d * (t[i] - t[i - 1]))) +
                 abs(a[i] - j);
  }
  for (int i = 1; i <= n; i++) ans = min(ans, dp[m][i]);
  printf("%I64d\n", vv - ans);
  return 0;
}
