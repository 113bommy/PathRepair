#include <bits/stdc++.h>
using namespace std;
int n, m, pos, a[2010], b[2010], dp[2010][2010];
inline int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') w = -1;
  for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
  return s * w;
}
int calc(int i, int j) { return abs(a[i] - b[j]) + abs(b[j] - pos); }
int main() {
  n = read(), m = read(), pos = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= m; ++i) b[i] = read();
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= n; ++i) {
    dp[i][i - 1] = 2e9;
    for (int j = i; j <= m; ++j)
      dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], calc(i, j)));
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
