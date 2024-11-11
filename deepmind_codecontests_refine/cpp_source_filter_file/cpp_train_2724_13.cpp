#include <bits/stdc++.h>
using namespace std;
int limit_f, limit_h;
long long int dp[101][101][11][11];
int getAns(int f, int h, int k1, int k2) {
  if ((f + h) == 0) return 1;
  if (dp[f][h][k1][k2] != -1) return dp[f][h][k1][k2];
  int x = 0;
  if (f > 0 && k1 > 0) x = getAns(f - 1, h, k1 - 1, limit_h);
  int y = 0;
  if (h > 0 && k2 > 0) y = getAns(f, h - 1, limit_f, k2 - 1);
  return dp[f][h][k1][k2] = (x + y) % 100000000;
}
int main() {
  int t, n1, n2;
  cin >> t;
  while (t--) {
    cin >> n1 >> n2 >> limit_f >> limit_h;
    memset(dp, -1, sizeof(dp));
    int ans = getAns(n1, n2, limit_f, limit_h);
    cout << ans << endl;
  }
  return 0;
}
