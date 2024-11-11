#include <bits/stdc++.h>
using namespace std;
int d[100005], q[100005], t[100005];
long long dp[100005], g[100005], s[100005];
long long cal(int j, int i) {
  return dp[j] + s[j] + 1LL * t[i] * (i - j) - s[i];
}
int main() {
  int n, m, i, k, j, p;
  while (~scanf("%d%d%d", &n, &m, &p)) {
    d[1] = 0;
    for (i = 2; i <= n; i++) scanf("%d", &d[i]), d[i] += d[i - 1];
    for (i = 1; i <= m; i++) {
      scanf("%d%d", &j, &k);
      t[i] = k - d[j];
    }
    sort(t + 1, t + m + 1);
    s[0] = 0;
    t[0] = 0;
    for (i = 1; i <= m; i++) s[i] = s[i - 1] + t[i];
    for (i = 1; i <= m; i++) dp[i] = 1LL * i * t[i] - s[i];
    dp[0] = 0;
    int f, r;
    for (i = 2; i <= p; i++) {
      f = r = 0;
      q[f++] = 0;
      for (j = 1; j <= m; j++) {
        while (f - 2 >= r) {
          int x = q[f - 1], y = q[f - 2];
          if ((cal(j, j) - cal(x, j)) * (x - y) <=
              (cal(x, j) - cal(y, j)) * (j - x))
            f--;
          else
            break;
        }
        q[f++] = j;
        while (r + 1 <= f - 1) {
          int x = q[r + 1], y = q[r];
          if (cal(x, j) <= cal(y, j))
            r++;
          else
            break;
        }
        int x = q[r];
        g[j] = min(dp[j], cal(x, j));
      }
      for (j = 1; j <= m; j++) dp[j] = g[j];
    }
    printf("%I64d\n", dp[m]);
  }
  return 0;
}
