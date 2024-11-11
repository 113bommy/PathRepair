#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int bin[25];
int n, L, delta;
char a[200005][25];
int b[200005][25], S[200005];
int dp[25][1048576];
int F(int x, int y) {
  int t1 = S[x], t2 = S[y];
  for (int i = L; i; i--) {
    if (t1 == t2) return i;
    t2 >>= 1;
    t1 -= b[x][L - i + 1] * bin[i - 1];
  }
  return 0;
}
int main() {
  bin[0] = 1;
  for (int i = 1; i <= 20; i++) bin[i] = bin[i - 1] << 1;
  memset(dp, 127 / 3, sizeof(dp));
  n = read();
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  L = strlen(a[1] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= L; j++) {
      b[i][j] = a[i][j] - '0';
      S[i] += b[i][j] * bin[L - j];
    }
  dp[0][0] = 0;
  delta = L;
  for (int i = 1; i < n; i++) {
    int tmp = L - F(i, i + 1), mn = 1000000000, now = 0;
    delta += tmp;
    for (int j = 0; j <= L; j++) {
      now = (now << 1) + b[i + 1][j];
      mn = min(mn, dp[j][now] + L - j);
    }
    now = 0;
    for (int j = 0; j <= L; j++) {
      dp[j][now] = min(dp[j][now], mn - tmp);
      now += b[i][L - j] * bin[j];
    }
  }
  int ans = 0;
  for (int i = 0; i <= L; i++)
    for (int j = 0; j < bin[i]; j++) ans = min(ans, dp[i][j]);
  printf("%d\n", ans + delta);
  return 0;
}
