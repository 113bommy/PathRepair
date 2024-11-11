#include <bits/stdc++.h>
using namespace std;
long long dp[2003][2003][3];
long long a[100005];
long long b[2003];
long long l[2003];
long long r[2003];
long long p[2003];
int flag[200005];
const long long inf = (1 << 30);
int main() {
  int n, m;
  while (~scanf("%d %d", &n, &m)) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++) {
      flag[a[i]] = 1;
    }
    int i = 1;
    while (i <= n) {
      int j;
      for (j = i; flag[a[j] + 1]; j++)
        ;
      for (int k = i; k < j; k++) p[k] = j;
      i = j + 1;
    }
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++)
        for (int k = 0; k <= 2; k++) dp[i][j][k] = inf;
    }
    int s = 0;
    a[0] = -inf;
    for (int i = 1; i <= m; i++) {
      for (s; s <= n && a[s] <= b[i]; s++)
        ;
      s--;
      l[i] = s;
    }
    a[n + 1] = inf;
    s = n + 1;
    for (int i = m; i >= 1; i--) {
      for (s; s >= 1 && a[s] >= b[i]; s--)
        ;
      s++;
      r[i] = s;
    }
    dp[0][0][2] = 0;
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= i; j++) {
        if (dp[i][j][0] > n || a[dp[i][j][0]] < b[i]) dp[i][j][0] = inf;
        if (dp[i][j][1] > n || a[dp[i][j][1]] >= b[i]) dp[i][j][1] = inf;
        if (dp[i][j][2] > n) dp[i][j][2] = inf;
        if (dp[i][j][0] <= n) {
          long long x = dp[i][j][0];
          dp[i + 1][j][2] = min(dp[i + 1][j][2], p[x]);
          dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], x + b[i + 1] - b[i]);
          if (l[i + 1] > x)
            dp[i + 1][j + 1][0] =
                min(dp[i + 1][j + 1][0], b[i + 1] - a[l[i + 1]] + l[i + 1]);
          dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], p[x] + 1);
        }
        if (dp[i][j][1] <= n) {
          long long x = dp[i][j][1];
          if (r[i] - x >= a[r[i]] - b[i]) {
            dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], p[r[i]] + 1);
          }
          if (b[i + 1] - b[i] + x <= l[i + 1]) {
            dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], b[i + 1] - b[i] + x);
          }
          if (r[i] - x >= a[r[i]] - b[i] && l[i + 1] >= r[i])
            dp[i + 1][j + 1][0] =
                min(dp[i + 1][j + 1][0], l[i + 1] + b[i + 1] - a[l[i + 1]]);
          if (r[i] - x >= a[r[i]] - b[i]) {
            dp[i + 1][j][2] = min(dp[i + 1][j][2], p[r[i]]);
          }
        }
        if (dp[i][j][2] <= n) {
          long long x = dp[i][j][2];
          if (x < l[i + 1])
            dp[i + 1][j + 1][0] =
                min(dp[i + 1][j + 1][0], l[i + 1] + b[i + 1] - a[l[i + 1]]);
          dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], x + 1);
          dp[i + 1][j][2] = min(dp[i + 1][j][2], x);
        }
      }
    }
    int ma = 0;
    for (int i = m; i >= 0; i--) {
      if (dp[m][i][0] <= n || dp[m][i][2] <= n ||
          (dp[m][i][1] <= n && r[m] - dp[m][i][1] >= a[r[m]] - b[m]))
        ma = max(ma, i);
    }
    cout << ma << endl;
  }
  return 0;
}
