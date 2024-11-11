#include <bits/stdc++.h>
using namespace std;
long long dp[5005][5005];
bool ispal[5005][5005];
string s;
int main() {
  long q, i, j, len, start, a, b, c, n;
  cin >> s;
  n = (long)s.size();
  for (i = 0; i <= n + 1; i++) dp[i][i] = ispal[i][i] = ispal[i + 1][i] = 1;
  for (len = 2; len <= n; len++) {
    for (start = 0; start <= n - len; start++) {
      ispal[start][start + len - 1] =
          ispal[start + 1][start + len - 2] & s[start] == s[start + len - 1];
      dp[start][start + len - 1] =
          dp[start][start + len - 2] + dp[start + 1][start + len - 1] -
          dp[start + 1][start + len - 2] + ispal[start][start + len - 1];
    }
  }
  cin >> q;
  for (i = 1; i <= q; i++) {
    scanf("%ld %ld", &a, &b);
    a--;
    b--;
    cout << dp[a][b] << "\n";
  }
  return 0;
}
