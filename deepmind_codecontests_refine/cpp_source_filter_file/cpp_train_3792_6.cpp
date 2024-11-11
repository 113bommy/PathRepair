#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
inline int FIX(int a) { return (a % Mod + Mod) % Mod; }
const int N = 1024;
int n, a[N];
int dp[N][N * 10];
int main() {
  scanf("%d", &n);
  dp[0][10000] = 1;
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= 20000; j++) {
      if (j + a[i] <= 20000) (dp[i][j + a[i]] += dp[i - 1][j]) %= Mod;
      if (j - a[i] >= 0) (dp[i][j - a[i]] += dp[i - 1][j]) %= Mod;
    }
    (ret += dp[i][10000]) %= Mod;
    (dp[i][10000] += 1) %= Mod;
  }
  cout << ret << endl;
  return 0;
}
