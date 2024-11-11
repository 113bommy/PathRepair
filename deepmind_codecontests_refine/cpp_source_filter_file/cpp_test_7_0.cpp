#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[510], b[510], c[510];
int dp[2][510][510];
int nxt[510][2], nxtm;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%1d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%1d", &b[i]);
  }
  if (b[1] == 0)
    nxt[0][0] = 1;
  else
    nxt[0][1] = 1;
  for (int j = 2; j <= m; ++j) {
    bool flag = 0;
    for (int k = j; k <= m; ++k) {
      if (b[k] != b[k - j + 1]) {
        flag = 1;
      }
    }
    if (!flag) {
      nxtm = m - j + 1;
      break;
    }
  }
  for (int i = 1; i < m; ++i) {
    c[i] = b[i];
    if (b[i + 1] == 0) {
      nxt[i][0] = i + 1;
      c[i + 1] = 1;
      for (int j = 1; j <= i + 1; ++j) {
        bool flag = 0;
        for (int k = j; k <= i + 1; ++k) {
          if (c[k] != b[k - j + 1]) {
            flag = 1;
          }
        }
        if (!flag) {
          nxt[i][1] = i + 2 - j;
          break;
        }
      }
    } else {
      nxt[i][1] = i + 1;
      c[i + 1] = 0;
      for (int j = 1; j <= i + 1; ++j) {
        bool flag = 0;
        for (int k = j; k <= i + 1; ++k) {
          if (c[k] != b[k - j + 1]) {
            flag = 1;
          }
        }
        if (!flag) {
          nxt[i][1] = i + 2 - j;
          break;
        }
      }
    }
  }
  int now = 0, per = 1;
  for (int j = 0; j <= n; ++j) {
    for (int k = 0; k < m; ++k) {
      dp[now][j][k] = dp[per][j][k] = 0x3f3f3f3f;
    }
  }
  dp[per][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < m; ++k) {
        dp[now][j][k] = 0x3f3f3f3f;
      }
    }
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (dp[per][j][k] != 0x3f3f3f3f) {
          int nxtk = nxt[k][a[i]];
          int nxtj = j;
          if (nxtk == m) {
            nxtj++;
            nxtk = nxtm;
          }
          dp[now][nxtj][nxtk] = min(dp[now][nxtj][nxtk], dp[per][j][k]);
          nxtk = nxt[k][!a[i]];
          nxtj = j;
          if (nxtk == m) {
            nxtj++;
            nxtk = nxtm;
          }
          dp[now][nxtj][nxtk] = min(dp[now][nxtj][nxtk], dp[per][j][k] + 1);
        }
      }
    }
    per++;
    now++;
    per %= 2;
    now %= 2;
  }
  for (int i = 0; i <= n - m + 1; ++i) {
    int minn = 0x3f3f3f3f;
    for (int j = 0; j < m; ++j) {
      minn = min(minn, dp[per][i][j]);
    }
    if (minn == 0x3f3f3f3f) {
      printf("-1 ");
    } else
      printf("%d ", minn);
  }
  return 0;
}
