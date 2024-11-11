#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[15000];
int n, l;
int output[15000];
int ans[15000];
int pre[15000];
double dp[15000];
int Slove(double L) {
  dp[0] = 0;
  for (int i = 1; i <= n; i++) dp[i] = 1000000000000;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j] + sqrt(fabs(a[i].x - a[j].x - l)) - L * a[i].y < dp[i]) {
        dp[i] = dp[j] + sqrt(fabs(a[i].x - a[j].x - l)) - L * a[i].y;
        pre[i] = j;
      }
    }
  }
  if (dp[n] < 0)
    return 1;
  else
    return 0;
}
int main() {
  while (~scanf("%d%d", &n, &l)) {
    a[0].x = 0, a[0].y = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
    }
    double LL = -1;
    double l = 0;
    double r = 10000000000;
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < 80; i++) {
      double mid = (l + r) / 2;
      if (Slove(mid) == 1) {
        LL = mid;
        memset(ans, -1, sizeof(ans));
        for (int j = 1; j <= n; j++) {
          ans[j] = pre[j];
        }
        r = mid;
      } else {
        l = mid;
      }
    }
    int cnt = 0;
    int now = n;
    while (now > 0) {
      output[cnt++] = now;
      now = ans[now];
    }
    for (int i = cnt - 1; i >= 0; i--) {
      printf("%d ", output[i]);
    }
    printf("\n");
  }
}
