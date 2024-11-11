#include <bits/stdc++.h>
using namespace std;
int n, m, s, k, a[2010], b[2010], nxt[2010], sum[2010], dp[2010][2010];
inline int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') w = -1;
  for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
  return s * w;
}
bool check(int mid) {
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (a[i] <= mid);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= s; ++i) {
    for (int j = 1; j <= n; ++j) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    for (int j = 1; j <= n; ++j)
      if (nxt[j])
        dp[i][nxt[j]] =
            max(dp[i][nxt[j]], dp[i - 1][j - 1] + sum[nxt[j]] - sum[j - 1]);
    for (int j = 1; j <= n; ++j) dp[i][j] = max(dp[i][j - 1], dp[i][j]);
  }
  return dp[s][n] >= k;
}
int main() {
  n = read(), m = read(), s = read(), k = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    for (int j = l; j <= r; ++j) nxt[j] = max(nxt[j], r);
  }
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = b[mid], r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
