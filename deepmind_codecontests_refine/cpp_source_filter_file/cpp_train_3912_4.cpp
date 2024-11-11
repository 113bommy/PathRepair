#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int n, c[N], a[N], b[N], dp[1 << N][2][N * N + 10];
int main() {
  scanf("%d", &n);
  int R = 0, B = 0;
  for (int i = 0; i < n; i++) {
    char s[2];
    scanf("%s", s);
    scanf("%d %d", &a[i], &b[i]);
    R += max(0, a[i] - n), B += max(0, b[i] - n);
    a[i] = min(a[i], n), b[i] = min(b[i], n);
    c[i] = (s[0] == 'R');
  }
  int tot = 1 << n, up = n * n;
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  if (R > B)
    dp[0][0][min(up, R - B)] = 0;
  else
    dp[0][1][min(up, B - R)] = 0;
  for (int i = 1; i < tot; i++) {
    int red = 0, blue = 0;
    for (int j = 0; j < n; j++) {
      if ((1 << j) & i) {
        if (c[j])
          red++;
        else
          blue++;
      }
    }
    for (int j = 0; j < n; j++) {
      if (!((1 << j) & i)) continue;
      int p = i ^ (1 << j), pred = red, pblue = blue;
      if (c[j])
        pred--;
      else
        pblue--;
      int r_re = max(0, a[j] - pred), b_re = max(0, b[j] - pblue);
      for (int k = 0; k <= up; k++) {
        if (dp[p][1][k] < 0x3f3f3f3f) {
          int add = max(0, max(r_re - k, b_re)), ar = k + add - r_re,
              br = add - b_re;
          ar = min(ar, up), br = min(br, up);
          if (!ar) dp[i][0][ar] = min(dp[i][0][br], dp[p][1][k] + add + 1);
          if (!br) dp[i][1][ar] = min(dp[i][1][ar], dp[p][1][k] + add + 1);
        }
        if (dp[p][0][k] < 0x3f3f3f3f) {
          int add = max(0, max(r_re, b_re - k)), ar = add - r_re,
              br = k + add - b_re;
          ar = min(ar, up), br = min(br, up);
          if (!ar) dp[i][0][br] = min(dp[i][0][br], dp[p][0][k] + add + 1);
          if (!br) dp[i][1][ar] = min(dp[i][1][ar], dp[p][0][k] + add + 1);
        }
      }
    }
  }
  int ans = 0x3f3f3f3f;
  R = max(R, B);
  for (int i = 0; i <= up; i++) {
    for (int w = 0; w < 2; w++) {
      ans = min(ans, dp[tot - 1][w][i] + R);
    }
  }
  printf("%d\n", ans);
  return 0;
}
