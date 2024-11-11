#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1010;
int N;
double K;
long long a[SIZE], able[SIZE];
long long c[20], ten[20];
double dp[SIZE][SIZE];
void init() {
  ten[1] = 1;
  c[1] = 1;
  for (int i = 2; i <= 19; i++) {
    ten[i] = (ten[i - 1] - 1) * 10 + 2;
    c[i] = c[i - 1] * 10;
  }
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    long long L, R;
    scanf("%I64d%I64d", &L, &R);
    able[i] = R - (L - 1);
    long long now1 = L, time1 = 0;
    while (!(1 <= now1 && now1 <= 9)) {
      now1 /= 10;
      time1++;
    }
    long long now2 = R, time2 = 0;
    while (!(1 <= now2 && now2 <= 9)) {
      now2 /= 10;
      time2++;
    }
    if (now1 != 1 && now2 != 1)
      a[i] = ten[time2 + 2] - ten[time1 + 2];
    else if (now1 == 1 && now2 != 1)
      a[i] = ten[time2 + 2] - ten[time1 + 1] - (L - c[time1 + 1]);
    else if (now1 != 1 && now2 == 1)
      a[i] = R - c[time2 + 1] + ten[time2 + 1] - ten[time1 + 2] + 1;
    else if (now1 == 1 && now2 == 1)
      a[i] = R - c[time2 + 1] + ten[time2 + 1] - ten[time1 + 1] -
             (L - c[time1 + 1]) + 1;
  }
  scanf("%lf", &K);
  K /= 100;
}
void solve() {
  dp[1][0] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j <= i - 1; j++) {
      double pro = double(a[i]) / double(able[i]);
      dp[i + 1][j + 1] += dp[i][j] * pro;
      dp[i + 1][j] += dp[i][j] * (1 - pro);
    }
  double ans = 0;
  for (int i = 0; i <= N; i++)
    if (double(i) >= ceil(N * K)) ans += dp[N + 1][i];
  printf("%.10lf\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
