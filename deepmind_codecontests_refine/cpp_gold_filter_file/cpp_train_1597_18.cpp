#include <bits/stdc++.h>
using namespace std;
double dp[210][210][210];
double a[210];
int b[210];
int sc[210];
int n, l, kkk, mx;
int main() {
  cin >> n >> l >> kkk;
  for (int i = 1; i <= n; i++) sc[i] = i, cin >> a[i], a[i] /= 100;
  for (int i = 1; i <= n; i++) cin >> b[i], mx += (b[i] == -1);
  dp[0][0][min(mx, kkk)] = 1;
  sort(sc + 1, sc + n + 1,
       [=](const int& x, const int& y) { return b[x] > b[y]; });
  for (int i = 1; i <= n; i++) {
    int x = sc[i];
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= mx; k++)
        if (dp[i - 1][j][k]) {
          dp[i][j][k] += dp[i - 1][j][k] * (1 - a[x]);
          int nxt = k + b[x];
          if (nxt > mx) nxt = mx;
          if (nxt < 0) continue;
          dp[i][j + 1][nxt] += dp[i - 1][j][k] * a[x];
        }
    }
  }
  double ans = 0;
  for (int i = l; i <= n; i++)
    for (int j = 0; j <= mx; j++) ans += dp[n][i][j];
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
