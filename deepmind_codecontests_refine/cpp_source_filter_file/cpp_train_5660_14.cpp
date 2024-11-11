#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long dp[101][100001];
long long comb[101][101];
void init() {
  comb[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j <= i; j++) {
      if (j - 1 >= 0)
        comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
      else
        comb[i][j] = comb[i - 1][j];
    }
  }
}
long long power(long long x, long long p) {
  long long ret = 1;
  long long base = x;
  while (p > 0) {
    if (p & 1) ret = ret * base % MOD;
    p >>= 1;
    base = base * base % MOD;
  }
  return ret;
}
int main() {
  long long r, c, n;
  cin >> r >> c >> n;
  init();
  dp[0][0] = 1;
  for (int i = 0; i < r; i++) {
    int cnt = c / r;
    if (c % r > i) cnt++;
    for (int j = 0; j <= r; j++) {
      long long ptr = power(comb[r][j], cnt);
      for (int k = j; k <= n; k++) {
        dp[i + 1][k] = (dp[i + 1][k] + dp[i][k - j] * ptr) % MOD;
      }
    }
  }
  cout << dp[r][n] << endl;
  return 0;
}
