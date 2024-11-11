#include <bits/stdc++.h>
using namespace std;
int n, m, k1, k2;
long long M = (long long)(1e8);
long long dp[109][109][2];
long long f(int x1, int x2, int bit) {
  if (x1 == 0 && x2 == 0) {
    return 1;
  }
  if (bit == 0 && x1 == 0) {
    return 0;
  }
  if (bit == 1 && x2 == 0) {
    return 0;
  }
  if (dp[x1][x2][bit] != -1) {
    return dp[x1][x2][bit];
  }
  long long res = 0;
  if (bit == 0) {
    for (int i = 1; i <= min(k1, x1); i++) {
      res = (res + f(x1 - i, x2, 1)) % M;
    }
  } else {
    for (int i = 1; i <= min(k2, x2); i++) {
      res = (res + f(x1, x2 - i, 0)) % M;
    }
  }
  dp[x1][x2][bit] = res;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k1 >> k2;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << (f(n, m, 0) + f(n, m, 1)) % M << endl;
}
