#include <bits/stdc++.h>
using namespace std;
int dp[1010][110][2], n, m, mod;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int Dp() {
  if (n == 1) return 9 / m % mod;
  static int Power[1010];
  Power[0] = 1;
  for (int i = 1; i <= n; ++i) Power[i] = Power[i - 1] * 10 % m;
  int ans = 0;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k <= 1; ++k)
        if (dp[i][j][k])
          for (int s = 0; s <= 9; ++s) {
            int newp = (s * Power[i] + j) % m, news = k;
            if (newp == 0 && (s || j)) news = 1;
            add(dp[i + 1][newp][news], dp[i][j][k]);
            if (i == n - 1 && s != 0 && news) add(ans, dp[i][j][k]);
          }
  return ans;
}
int main() {
  cin >> n >> m >> mod;
  cout << Dp() << endl;
  return 0;
}
