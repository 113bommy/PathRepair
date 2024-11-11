#include <bits/stdc++.h>
using namespace std;
const int maxn = 4000 + 100;
const int mod = 1000000007;
long long dp[maxn];
long long C[maxn][maxn];
void init() {
  for (int i = 0; i < maxn; i++) C[0][i] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j < maxn; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  init();
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++)
      dp[i] = (dp[i] + dp[i - j - 1] * C[j][i - 1]) % mod;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) res = (res + dp[i] * C[i][n]);
  cout << res << endl;
  return 0;
}
