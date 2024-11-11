#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MOD = 1000000007;
int k, curr;
int dp[MAXN][MAXN];
int f(int x, int y) {
  if (y == 0) return 1;
  if (x <= 0) return 0;
  if (dp[x][y] != -1) return dp[x][y];
  int ret = 0;
  for (int i = 0; i <= y; i++) {
    ret += f(x - 1, y - i);
    ret %= MOD;
  }
  return dp[x][y] = ret;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin >> k >> curr;
  int num = curr;
  int sol = 1;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < k - 1; i++) {
    cin >> curr;
    sol = (long long)(sol * f(num + 1, curr - 1)) % MOD;
    num += curr;
  }
  cout << sol << endl;
  return 0;
}
