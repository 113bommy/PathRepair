#include <bits/stdc++.h>
using namespace std;
const int M = 105;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, ans, sum, cnt, a[M], b[M], C[M][M], dp[M][M * M];
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    b[a[i]]++;
  }
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    for (int k = i; k >= 1; k--)
      for (int j = sum; j >= a[i]; j--) dp[k][j] += dp[k - 1][j - a[i]];
  }
  for (int i = 1; i <= 100; i++) {
    if (b[i]) cnt++;
    for (int j = 1; j <= b[i]; j++) {
      if (dp[j][i * j] == C[b[i]][j]) ans = max(ans, j);
    }
  }
  if (cnt == 1 || cnt == 2) ans = n;
  printf("%d\n", ans);
}
