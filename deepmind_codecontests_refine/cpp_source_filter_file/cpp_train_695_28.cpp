#include <bits/stdc++.h>
int t1, t2, t3;
long long l1, l2;
int n;
struct task {
  int a, b;
};
bool tsort(task t1, task t2) {
  return t1.a > t2.a || (t1.a == t2.a && t1.b < t2.b);
}
task t[51];
long long dp1[26][5001];
long long dp2[26][5001];
double ans = 1e+100;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &t[i].a);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i].b);
  }
  std::sort(t, t + n, tsort);
  memset(dp1, 0x3f, sizeof dp1);
  memset(dp2, 0x3f, sizeof dp2);
  dp1[0][0] = 0;
  t1 = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i - 1].a == t[i].a) continue;
    for (int j = 0; j <= 25; j++) {
      for (int k = 0; k <= 5000; k++) {
        if (dp1[j][k] == 0x3f3f3f3f3f3f3f3f) continue;
        for (int l = 0; l <= j; l++) {
          if (l > i - t1) continue;
          t2 = k;
          for (int m = t1 + l; m < i; m++) t2 += t[m].b;
          l2 = dp1[j][k] + t[i - 1].a * (long long)(i - t1 - l);
          t3 = j - l + (i - t1 - l);
          if (t3 > 25) t3 = 25;
          if (dp2[t3][t2] > l2) {
            dp2[t3][t2] = l2;
          }
        }
      }
    }
    memcpy(dp1, dp2, sizeof dp1);
    memset(dp2, 0x3f, sizeof dp2);
    t1 = i;
  }
  for (int i = 0; i <= 25; i++) {
    for (int j = 1; j <= 5000; j++) {
      if (ans > dp1[i][j] / (double)j) {
        ans = dp1[i][j] / (double)j;
      }
    }
  }
  printf("%.0f\n", ans * 1000 * (1 + 1e-15));
}
