#include <bits/stdc++.h>
using namespace std;
const int M = 105;
const int inf = 0x3f3f3f3f;
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
int n, m, a[M], b[M], c[M], d[M], dp[1 << 20];
char s[5];
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  m = read();
  sort(a + 1, a + 1 + n, greater<int>());
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    c[i] = read();
    if (s[0] == 'p')
      b[i] = 1;
    else
      b[i] = 2;
  }
  for (int i = 1; i < (1 << m); i++) {
    d[i] = d[i >> 1] + (i & 1);
    int j = m - d[i] + 1;
    if (c[j] == 1)
      dp[i] = -inf;
    else
      dp[i] = inf;
    for (int k = 0; k < m; k++) {
      if (!(i & (1 << k))) continue;
      int l = (b[j] == 1 ? a[k + 1] : 0);
      if (c[j] == 1)
        dp[i] = max(dp[i], dp[i ^ (1 << k)] + l);
      else
        dp[i] = min(dp[i], dp[i ^ (1 << k)] - l);
    }
  }
  printf("%d\n", dp[(1 << m) - 1]);
}
