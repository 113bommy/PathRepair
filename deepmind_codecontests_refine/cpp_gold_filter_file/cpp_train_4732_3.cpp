#include <bits/stdc++.h>
using namespace std;
int flag[100005];
int p[10005];
int num;
int a[55];
int c[1005];
int b[1005];
const int inf = (1 << 29);
int q[10005];
int dp[105][2100][9];
int f[105][2100][9];
int g[105][2100][9];
int sg[90];
int st[90];
int mp[5005];
int main() {
  num = 0;
  for (int i = 2; i <= 10000; i++) {
    if (flag[i] == 0) {
      p[++num] = i;
    }
    for (int j = 1; j <= num && i * p[j] <= 10000; j++) {
      flag[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  int m = 0;
  int i;
  for (i = 1; i <= num && p[i] <= 30; i++) {
    a[m++] = p[i];
  }
  int r = 0;
  for (; i <= num && p[i] <= 60; i++) {
    b[++r] = p[i];
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      for (int k = 0; k <= r; k++) {
        dp[i][j][k] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  int t = 0;
  for (int i = 2; i <= 59; i++) {
    int vis = 0;
    for (int j = 1; j <= r; j++) {
      if (i == b[j]) {
        vis = 1;
        break;
      }
    }
    if (vis) continue;
    int df = 0;
    for (int j = 0; j < m; j++) {
      if (i % a[j] == 0) df |= (1 << j);
    }
    sg[++t] = i;
    st[t] = df;
    mp[i] = t;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      for (int k = 0; k <= r; k++) {
        if (k < r)
          if (dp[i + 1][j][k + 1] > dp[i][j][k] + b[k + 1] - c[i + 1]) {
            dp[i + 1][j][k + 1] = dp[i][j][k] + b[k + 1] - c[i + 1];
            g[i + 1][j][k + 1] = -1;
          }
        if (dp[i][j][k] + c[i + 1] - 1 < dp[i + 1][j][k]) {
          dp[i + 1][j][k] = dp[i][j][k] + c[i + 1] - 1;
          g[i + 1][j][k] = 0;
        }
        for (int l = 1; l <= t; l++) {
          int x = sg[l];
          if (st[l] & j) continue;
          if (dp[i + 1][j | st[l]][k] > dp[i][j][k] + abs(c[i + 1] - x)) {
            dp[i + 1][j | st[l]][k] = dp[i][j][k] + abs(c[i + 1] - x);
            g[i + 1][j | st[l]][k] = l;
          }
        }
      }
    }
  }
  int mi = inf;
  int s, d;
  for (int i = 0; i < (1 << m); i++) {
    for (int j = 0; j <= r; j++) {
      if (dp[n][i][j] < mi) {
        mi = dp[n][i][j];
        s = i;
        d = j;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    if (g[i][s][d] == -1) {
      q[i] = b[d];
      d--;
    } else if (g[i][s][d] == 0) {
      q[i] = 1;
    } else {
      int x = g[i][s][d];
      q[i] = sg[x];
      s -= st[x];
    }
  }
  for (int i = 1; i <= n; i++) cout << q[i] << ' ';
  cout << endl;
  return 0;
}
