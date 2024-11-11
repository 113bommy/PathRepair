#include <bits/stdc++.h>
using namespace std;
const int MAXN = 700 + 10, MOD = 1e9 + 7;
stack<long long> lb, rb;
string sa;
long long ltr[MAXN], arr[MAXN], dp[MAXN][MAXN][3][3], col[MAXN], ans;
vector<long long> bl[MAXN];
int main() {
  cin >> sa;
  for (int i = 0; i < sa.size(); i++) {
    if (sa[i] == '(')
      lb.push(i + 1);
    else {
      ltr[lb.top()] = i + 1, bl[i + 1 - lb.top()].push_back(lb.top());
      if (i + 1 - lb.top() == 1)
        for (int j = 1; j < 3; j++)
          dp[lb.top()][i + 1][j][0] = dp[lb.top()][i + 1][0][j] = 1;
      lb.pop();
    }
  }
  ltr[0] = sa.size() + 1, bl[sa.size() + 1].push_back(0);
  for (int i = 1; i <= sa.size() + 1; i += 2) {
    for (int j = 0; j < bl[i].size(); j++) {
      long long now = bl[i][j], cnt = 0, b[MAXN];
      for (int k = now + 1; k < ltr[now]; k = ltr[k] + 1) b[++cnt] = k;
      for (int k = 1; k < cnt; k++) {
        for (int l = 1; l + k <= cnt; l++) {
          for (int n = 0; n < 3; n++) {
            for (int o = 0; o < 3; o++) {
              for (int m = 0; m < 3; m++) {
                long long *x = &dp[b[l]][ltr[b[l + k]]][n][o],
                          res = dp[b[l]][ltr[b[l + k - 1]]][n][m], res1 = 0;
                if (!o)
                  for (int p = 1; p < 3; p++)
                    if (p != m)
                      res1 = (res1 + dp[b[l + k]][ltr[b[l + k]]][p][0]) % MOD;
                    else
                      res1 = (res1 + dp[b[l + k]][ltr[b[l + k]]][0][o]) % MOD;
                (*x) = ((*x) + res * res1 % MOD) % MOD;
              }
            }
          }
        }
      }
      for (int k = 1; k < 3; k++)
        for (int l = 0; l < 3; l++)
          for (int m = 0; m < 3; m++)
            if (l != k)
              dp[now][ltr[now]][k][0] =
                  (dp[now][ltr[now]][k][0] + dp[now + 1][ltr[now] - 1][l][m]) %
                  MOD;
      for (int k = 1; k < 3; k++)
        for (int l = 0; l < 3; l++)
          for (int m = 0; m < 3; m++)
            if (m != k)
              dp[now][ltr[now]][0][k] =
                  (dp[now][ltr[now]][0][k] + dp[now + 1][ltr[now] - 1][l][m]) %
                  MOD;
    }
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) ans = (ans + dp[1][sa.size()][i][j]) % MOD;
  cout << ans << endl;
  return 0;
}
