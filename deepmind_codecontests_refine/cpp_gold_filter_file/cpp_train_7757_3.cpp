#include <bits/stdc++.h>
using namespace std;
const int maxn = 2100;
const long long inf = (1LL << 60 - 1);
long long dp1[maxn][maxn];
int main() {
  int n, m;
  cin >> n >> m;
  int dn = n - m;
  string s;
  int dx = 0, tx = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      dx++;
    else
      dx--;
    tx = min(tx, dx);
  }
  memset(dp1, 0, sizeof(dp1));
  dp1[0][0] = 1;
  for (int i = 1; i <= dn; i++) {
    for (int j = 0; j <= i; j++) {
      if (j < i - j) continue;
      if (j <= i - 1 && j >= i - 1 - j) dp1[i][j] = dp1[i - 1][j];
      if (j - 1 >= i - j && j) dp1[i][j] += dp1[i - 1][j - 1];
      if (dp1[i][j] >= 1000000007) dp1[i][j] %= 1000000007;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= dn; i++) {
    for (int j = 0; j <= i; j++) {
      if (j < i - j) continue;
      if (j + dx < i - j) continue;
      if (j + tx < i - j) continue;
      int ii = j - i + (dx + dn) / 2;
      if (2 * ii < dn - i || ii < 0 || ii > dn - i) continue;
      ans += dp1[i][j] * dp1[dn - i][ii];
      if (ans >= 1000000007) ans %= 1000000007;
    }
  }
  if (n % 2) ans = 0;
  cout << ans % 1000000007 << endl;
  return 0;
}
