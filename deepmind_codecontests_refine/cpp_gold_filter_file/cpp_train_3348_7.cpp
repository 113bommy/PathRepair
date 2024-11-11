#include <bits/stdc++.h>
using namespace std;
int dp[300005][32];
int a[300005], last[30];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < 20; j++) {
      dp[i][j] = 1e9;
      if ((a[i] >> j) & 1)
        dp[i][j] = i;
      else {
        for (int k = 0; k < 20; k++) {
          if ((a[i] >> k) & 1 && last[k]) {
            dp[i][j] = min(dp[last[k]][j], dp[i][j]);
          }
        }
      }
    }
    for (int j = 0; j < 20; j++) {
      if ((a[i] >> j) & 1) last[j] = i;
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    int flag = 0;
    for (int i = 0; i < 20; i++) {
      if ((a[y] >> i) & 1 && dp[x][i] <= y) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "Shi" << '\n';
    else
      cout << "Fou" << '\n';
  }
  return 0;
}
