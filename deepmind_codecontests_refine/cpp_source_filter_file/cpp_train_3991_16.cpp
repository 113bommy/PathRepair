#include <bits/stdc++.h>
using namespace std;
const int maxn = 26 * 1000 + 200;
const int mod = 1000 * 1000 * 1000 + 7;
int dp[maxn][100];
void fix_it(int x, int y) {
  int ans = 0;
  for (int i = 0; i <= 25; i++)
    if (i <= x) ans += dp[x - i][y - 1] % mod, ans %= mod;
  dp[x][y] = ans % mod;
}
int main() {
  dp[0][0] = 1;
  for (int i = 0; i < maxn; i++)
    for (int j = 1; j <= 100; j++) fix_it(i, j);
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0; i < s.size(); i++) num += int(s[i] - 'a');
    cout << dp[num][s.size()] % mod - 1 << '\n';
  }
  return 0;
}
