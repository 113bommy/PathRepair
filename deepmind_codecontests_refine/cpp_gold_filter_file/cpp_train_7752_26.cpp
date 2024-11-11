#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
double dp[MAXN][MAXN];
double p[MAXN];
double d[MAXN];
double sp;
int X0, Y0;
int K, N;
int cnt = 0, lis[MAXN];
bool check(double mid) {
  int ret = 0;
  cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (d[i] <= mid)
      ret++;
    else
      lis[++cnt] = i;
  }
  if (ret >= K) return true;
  int k = K - ret;
  for (int i = 0; i <= cnt; i++)
    for (int j = 0; j <= cnt; j++) dp[i][j] = 0.0;
  dp[0][0] = 1.0;
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j + 1] +=
          dp[i][j] * exp(1 - d[lis[i + 1]] / mid * d[lis[i + 1]] / mid);
      dp[i + 1][j] +=
          dp[i][j] * (1 - exp(1 - d[lis[i + 1]] / mid * d[lis[i + 1]] / mid));
    }
  }
  double tot = 0.0;
  for (int i = k; i <= cnt; i++) tot += dp[cnt][i];
  return (tot >= sp);
}
int main() {
  scanf("%d", &N);
  scanf("%d%lf", &K, &sp);
  sp = 1000.0 - sp;
  sp /= 1000.0;
  scanf("%d%d", &X0, &Y0);
  for (int i = 1; i <= N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    d[i] = sqrt((x - X0) * (x - X0) + (y - Y0) * (y - Y0));
  }
  double left = 0, right = 1e4, ans;
  for (int i = 0; i < 200; i++) {
    double mid = (left + right) / 2.0;
    if (check(mid)) {
      ans = mid;
      right = mid;
    } else
      left = mid;
  }
  printf("%.12f\n", ans);
  return 0;
}
