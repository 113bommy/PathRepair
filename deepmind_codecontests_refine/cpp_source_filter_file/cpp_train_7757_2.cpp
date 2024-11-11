#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, M = 1e9 + 7;
long long dp[N][N], ans, n, l, cnto, cntc, musto;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> l >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      cnto++;
    else {
      if (cnto == 0)
        musto++;
      else
        cnto--;
    }
  }
  if (cnto + musto + n > l && l & 1 == 1) return (cout << 0), 0;
  dp[0][0] = 1;
  for (int i = 1; i <= l - n; i++)
    for (int j = 0; 2 * j <= i; j++)
      dp[i][j] = ((j > 0 ? dp[i - 1][j - 1] : 0) + dp[i - 1][j]) % M;
  for (int i = musto; i <= l - n - cnto; i++)
    for (int j = 0; i - 2 * j >= musto; j++) {
      long long crnt = l - n - i - (i - 2 * j - musto + cnto);
      if (crnt >= 0 && l - n - i >= 0)
        ans = (ans + (dp[i][j] * dp[l - n - i][crnt / 2]) % M) % M;
    }
  cout << ans;
  return 0;
}
