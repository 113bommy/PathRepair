#include <bits/stdc++.h>
using namespace std;
void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int read() {
  int d = 0, w = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') w = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) d = (d << 1) + (d << 3) + c - 48;
  return d * w;
}
void wln(int x) {
  write(x);
  putchar('\n');
}
void wrs(int x) {
  write(x);
  putchar(' ');
}
int n, k, like[510], mst[20], a[510 * 20], dp[510 * 20], last[510 * 20];
signed main() {
  n = read();
  k = read();
  for (int i = 1; i <= n * k; a[i++] = read())
    ;
  sort(a + 1, a + n * k + 1);
  for (int i = 1; i <= n; like[i++] = read())
    ;
  sort(like + 1, like + n + 1);
  for (int i = 1; i <= k; mst[i++] = read())
    ;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n * k; j++) {
      dp[j] = max(dp[j], dp[j - 1]);
      for (int kk = 0; kk <= min(k, j); kk++) {
        int cnt = 0;
        for (int l = j - kk; l <= j; l++) cnt += (like[i] == a[i]);
        dp[j] = max(dp[j], last[j - kk] + mst[cnt]);
      }
    }
    for (int j = 0; j <= n * k; j++) last[j] = dp[j];
    memset(dp, 0, sizeof dp);
  }
  write(last[n * k]);
  return 0;
}
