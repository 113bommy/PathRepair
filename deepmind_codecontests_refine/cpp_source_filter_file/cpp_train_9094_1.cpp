#include <bits/stdc++.h>
using namespace std;
const int MAXN = 45;
long long dp[MAXN][MAXN];
int main() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  int i, j, p;
  for (i = 1; i < MAXN; i++) {
    dp[i][0] += dp[i - 1][0];
    for (j = 1; j <= i; j++) {
      dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  long long n, t;
  while (cin >> n >> t) {
    long long lans = 0, one = 1;
    for (i = 0; i < MAXN; i++)
      if (t == (one << i)) break;
    if (i == MAXN) {
      puts("0");
      continue;
    }
    t = i;
    p = 0;
    while (n >= (one << p)) {
      lans += dp[p][t];
      n -= (one << p++);
    }
    for (i = MAXN - 1; i >= 0 && t >= 0; i--) {
      if (n & (one << i)) lans += dp[i][t--];
    }
    cout << lans << endl;
  }
  return 0;
}
