#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int dp[maxn][33];
int en[33];
int a[maxn];
int n, m;
int x, y;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 31; i++) {
    en[i] = n + 1;
    dp[n + 1][i] = n + 1;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 31; j++) {
      dp[i][j] = n + 1;
    }
    for (int j = 0; j < 31; j++) {
      if ((a[i] >> j) & 1) {
        for (int k = 0; k < 31; k++) {
          dp[i][k] = min(dp[i][k], dp[en[j]][k]);
        }
        en[j] = i;
        dp[i][j] = i;
      }
    }
  }
  int flag = 0;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    flag = 0;
    for (int j = 1; j < 31; j++) {
      if (((a[y] >> j) & 1) && dp[x][j] <= y) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << "Shi" << '\n';
    } else
      cout << "Fou" << '\n';
  }
}
