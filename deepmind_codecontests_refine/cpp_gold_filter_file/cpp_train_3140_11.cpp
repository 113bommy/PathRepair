#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, mod = 1e6 + 3, dp[2005][2005], sta[2005], x[2005],
                         y[2005], num[2005], cnt, l1, l2;
string st;
int main() {
  cin >> st;
  n = st.length();
  st = " " + st;
  for (i = 1; i <= n; i++) {
    if (st[i] == '*' || st[i] == '/') {
      if ((!i) || (st[i - 1] > '9') || st[i - 1] < '0') {
        cout << 0;
        return 0;
      }
    }
  }
  if (st[n] > '9' || st[n] < '0') {
    cout << 0;
    return 0;
  }
  cnt = 0;
  for (i = 1; i <= n; i++) {
    if (st[i] < '0' || st[i] > '9') {
      cnt++;
      continue;
    }
    if (cnt || i == 1) {
      num[++l1] = cnt;
      cnt = 0;
    }
  }
  num[1]++;
  for (i = 1; i <= l1; i++) {
    sta[i] = l2 + 1;
    for (j = num[i]; j; j--) {
      y[++l2] = j;
      x[l2] = i;
    }
  }
  for (i = l2; i; i--) {
    dp[i][x[i]] = 1;
    for (j = x[i] + 1; j <= l1; j++) {
      if (y[i] > 1) {
        dp[i][j] += dp[i + 1][j];
      } else
        dp[i][j] = 0;
      for (k = x[i]; k < j; k++) {
        dp[i][j] += dp[i][k] * dp[sta[k + 1]][j];
      }
      dp[i][j] %= mod;
    }
  }
  cerr << l1 << ' ' << l2 << endl;
  cout << dp[1][l1];
  return 0;
}
