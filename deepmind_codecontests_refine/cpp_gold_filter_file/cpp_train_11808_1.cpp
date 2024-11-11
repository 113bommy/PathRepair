#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n, k, p[3111];
int dp[3111][3111];
bool someG0[3111];
bool allL100[3111];
int res;
bool allDead;
void doit() {
  memset(allL100, true, sizeof(allL100));
  for (int i = n - 1; i >= 0; i--) {
    allL100[i] = allL100[i + 1] && (p[i] < 100);
  }
  memset(someG0, false, sizeof(someG0));
  for (int i = n - 1; i >= 0; i--) {
    someG0[i] = someG0[i + 1] | (p[i] > 0);
  }
}
void doDP() {
  for (int i = 0; i < (int)3111; i++)
    for (int j = 0; j < (int)3111; j++) dp[i][j] = 100000;
  dp[0][0] = 0;
  for (int i = 0; i < (int)n + 1; i++) {
    for (int j = 0; j < (int)n + 1; j++) {
      if (i + j + 1 < 3050 && someG0[i + j + 1] && p[i] < 100)
        dp[i + j + 1][0] = min(dp[i + j + 1][0], dp[i][j] + 1);
      if (i + j + 2 < 3050 && someG0[i + j + 1] && p[i] > 0)
        dp[i + j + 2][0] = min(dp[i + j + 2][0], dp[i][j] + 1);
      if (i + j + 1 < 3050 && allL100[i + j + 1] && p[i] > 0)
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[i][0] <= k) {
      res++;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j + i + 1 <= n; j++) {
      if (dp[i][j] <= k) {
        res++;
      }
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < (int)n; i++) cin >> p[i];
  res = 0;
  doit();
  doDP();
  cout << res << endl;
  return 0;
}
