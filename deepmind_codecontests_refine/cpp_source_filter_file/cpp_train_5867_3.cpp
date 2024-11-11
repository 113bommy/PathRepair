#include <bits/stdc++.h>
const int N = 500010, M = 20;
int s[M], x[N], y[N], now[N], prev[N][M];
int main() {
  int n, m, i, j, temp, top, l, r, mid;
  long long ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &temp);
    prev[i][0] = i - temp;
    if (prev[i][0] < 1) prev[i][0] = 1;
    prev[i + n][0] = i + n - temp;
    if (prev[i + n][0] < 1) prev[i + n][0] = 1;
  }
  s[0] = 1;
  m = 0;
  while (s[m] * 2 <= n) {
    m++;
    s[m] = s[m - 1] * 2;
  }
  for (i = 1; i <= m; i++) {
    top = 0;
    for (j = 1; j <= n * 2; j++) {
      while (top > 0 && x[top] >= prev[j][i - 1]) top--;
      top++;
      x[top] = prev[j][i - 1];
      y[top] = j;
      if (y[1] >= prev[j][i - 1]) {
        prev[j][i] = x[1];
      } else {
        l = 1;
        r = top;
        while (l + 1 < r) {
          mid = (l + r) / 2;
          if (y[mid] < prev[j][i - 1])
            l = mid;
          else
            r = mid;
        }
        prev[j][i] = x[r];
      }
    }
  }
  for (i = n + 1; i <= n * 2; i++) now[i] = i;
  for (i = m; i >= 0; i--) {
    top = 0;
    for (j = 1; j <= n * 2; j++) {
      while (top > 0 && x[top] >= prev[j][i]) top--;
      top++;
      x[top] = prev[j][i];
      y[top] = i;
      if (j > n) {
        if (y[1] >= now[j]) {
          if (x[1] > j - n + 1) {
            now[j] = x[1];
            ans += s[i];
          }
        } else {
          l = 1;
          r = top;
          while (l + 1 < r) {
            mid = (l + r) / 2;
            if (y[mid] < now[j])
              l = mid;
            else
              r = mid;
          }
          if (x[r] > j - n + 1) {
            now[j] = x[r];
            ans += s[i];
          }
        }
      }
    }
  }
  ans += n;
  printf("%I64d", ans);
  return (0);
}
