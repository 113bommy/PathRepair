#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005, MAXM = 23;
int n, m;
int a[MAXN];
int s[MAXN];
int dp[MAXN], best[MAXM][MAXN];
inline int w(int p, int q) {
  for (int i = m; i >= 1; i--) {
    if ((a[p] & ((1 << i) - 1)) == (a[q] >> (m - i))) return m - i;
  }
  return m;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char t[MAXM];
    scanf("%s", t);
    if (!m) m = strlen(t);
    for (int j = 0; j < m; j++) a[i] = a[i] * 2 + (t[j] - '0');
  }
  s[1] = m;
  for (int i = 2; i <= n; i++) s[i] = w(i - 1, i);
  for (int i = 2; i <= n; i++) s[i] += s[i - 1];
  memset(best, 20, sizeof(best));
  for (int i = 2; i <= n; i++) {
    dp[i] = m + s[i - 1];
    for (int j = 0; j <= m; j++)
      if (best[j][a[i] >> (m - j)] + m - j + s[i - 1] < dp[i])
        dp[i] = best[j][a[i] >> (m - j)] + m - j + s[i - 1];
    for (int j = 0; j <= m; j++)
      if (dp[i] - s[i] < best[j][a[i - 1] & ((1 << j) - 1)])
        best[j][a[i - 1] & ((1 << j) - 1)] = dp[i] - s[i];
  }
  int ans = s[n];
  for (int i = 2; i <= n; i++) {
    if (dp[i] + s[n] - s[i] < ans) ans = dp[i] + s[n] - s[i];
  }
  printf("%d\n", ans);
  return 0;
}
