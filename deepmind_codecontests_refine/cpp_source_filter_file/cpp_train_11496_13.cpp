#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 5e5 + 3;
long long row[50][50], dp[50][50][50][50];
int main() {
  ios::sync_with_stdio(false);
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      char c;
      cin >> c;
      (c == '0') ? row[i][j] += row[i][j - 1] + 1 : 0;
    }
  }
  for (long long a = 1; a <= n; a++)
    for (long long b = 1; b <= m; b++)
      for (long long c = a + 1; c <= n; c++)
        for (long long d = b + 1; d <= m; d++) {
          dp[a][b][c][d] =
              dp[a][b][c - 1][d] + dp[a][b][c][d - 1] - dp[a][b][c - 1][d - 1];
          long long len = d - b + 1;
          for (long long i = c; i >= a; i--) {
            if (len > row[i][d]) len = row[c][d];
            dp[a][b][c][d] += len;
          }
        }
  for (long long i = 1; i <= q; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c][d] << endl;
  }
}
