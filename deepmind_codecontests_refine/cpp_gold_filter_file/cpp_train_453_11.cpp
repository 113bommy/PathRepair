#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
int n, m;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int slowsolve() {
  int res = 0;
  vector<vector<int> > dp(n + 1, vector<int>(m, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = 1;
      for (int k = 1; k <= j; k++) {
        add(dp[i][j], 1LL * dp[i - 1][k] * (j - k + 1) % mod);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      int cur = 1;
      for (int k = 1; k < j; k++) {
        add(cur, 1LL * dp[n - i][k] * (j - k + 1) % mod);
      }
      add(res, 1LL * dp[i][j] * cur % mod * (m - j) % mod);
    }
  }
  return res;
}
int fastsolve() {
  int res = 0;
  vector<vector<int> > dp(n + 1, vector<int>(m, 0));
  vector<vector<int> > sum1(n + 1, vector<int>(m, 0));
  vector<vector<int> > sum2(n + 1, vector<int>(m, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = 1;
      add(dp[i][j], 1LL * (j + 1) * sum1[i - 1][j] % mod);
      add(dp[i][j], mod - sum2[i - 1][j]);
      sum1[i][j] = sum1[i][j - 1];
      add(sum1[i][j], dp[i][j]);
      sum2[i][j] = sum2[i][j - 1];
      add(sum2[i][j], 1LL * j * dp[i][j] % mod);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      int cur = 1;
      add(cur, 1LL * (j + 1) * sum1[n - i][j] % mod);
      add(cur, mod - sum2[n - i][j]);
      add(cur, mod - dp[n - i][j]);
      add(res, 1LL * dp[i][j] * cur % mod * (m - j) % mod);
    }
  }
  return res;
}
int main() {
  while (cin >> n >> m) cout << fastsolve() << endl;
  return 0;
}
