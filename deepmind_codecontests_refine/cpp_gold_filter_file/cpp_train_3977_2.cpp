#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const long long inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 1ll * 1;
int mark[N], n, m, prt[N], mn[N];
long long dp[N][N], sum, k;
long long getNum() {
  memset(dp, 0, sizeof(dp));
  dp[m + n - 1][0] = 1;
  for (int i = m + n - 2; i >= 0; i--) {
    for (int j = 0; j < m + n; j++) {
      if (mark[i] == 1) dp[i][j] = dp[i + 1][j + 1];
      if (mark[i] == 0)
        if (j != 0)
          dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j - 1];
        else
          dp[i][j] = dp[i + 1][j + 1];
      if (mark[i] == 2)
        if (j != 0) dp[i][j] = dp[i + 1][j - 1];
      if (dp[i][j] >= inf) dp[i][j] = inf;
    }
  }
  return dp[0][0];
}
int main() {
  memset(mn, 127, sizeof(mn));
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      mn[i + j] = min(mn[i + j], x);
    }
  iota(prt, prt + n + m - 1, 0);
  sort(prt, prt + n + m - 1, [](int x, int y) { return mn[x] < mn[y]; });
  mark[0] = 1, mark[m + n - 2] = 2;
  for (int i = 0; i < m + n - 1; i++) {
    if (prt[i] == 0 || prt[i] == m + n - 2) continue;
    mark[prt[i]] = 1;
    long long lv = getNum();
    mark[prt[i]] = 2;
    long long val = getNum();
    if (k > lv + sum && val > 0 || lv == 0) {
      mark[prt[i]] = 2;
      sum += lv;
    } else {
      mark[prt[i]] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (mark[i + j] == 1)
        cout << '(';
      else
        cout << ')';
    cout << endl;
  }
  return 0;
}
