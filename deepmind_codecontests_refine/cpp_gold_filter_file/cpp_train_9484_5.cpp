#include <bits/stdc++.h>
using namespace std;
int n, k, c, b, dp[2005][2005], mux = 0, im, jm, kol, uc, sum;
bool mark[2005][2005];
string ans = "", smin = "*", s;
char a[2005][2005], mun;
pair<int, int> para, pars;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  if (a[1][1] == 'a')
    dp[1][1] = 1;
  else
    dp[1][1] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (a[i][j] == 'a');
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (k + dp[i][j] >= i + j - 1) mux = max(mux, (i + j - 1));
  for (int i = max(1, mux + 1 - n); i <= min(mux, n); i++) {
    jm = mux + 1 - i;
    if (k + dp[i][jm] == mux) {
      if (i < n) mark[i + 1][jm] = true;
      if (jm < n) mark[i][jm + 1] = true;
    }
  }
  if (k == 0) mark[1][1] = true;
  for (int i = 1; i <= mux; i++) cout << 'a';
  for (int pot = mux + 1; pot <= 2 * n - 1; pot++) {
    mun = 'z';
    for (int i = max(1, pot + 1 - n); i <= min(pot, n); i++)
      if (mark[i][pot - i + 1] == true) mun = min(mun, a[i][pot - i + 1]);
    cout << mun;
    for (int i = max(1, pot + 1 - n); i <= min(pot, n); i++) {
      jm = pot - i + 1;
      if ((mark[i][jm] == true) && (a[i][jm] == mun)) {
        if (i < n) mark[i + 1][jm] = true;
        if (jm < n) mark[i][jm + 1] = true;
      }
    }
  }
  return 0;
}
