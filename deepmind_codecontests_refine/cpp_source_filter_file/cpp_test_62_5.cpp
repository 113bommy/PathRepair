#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long n, m, q, ans;
bool vizitat[N][N];
long long dp[N][N][2];
bool verifica(long long i, long long j) {
  if (i < 1 || j < 1 || i > n || j > m) return false;
  return true;
}
long long cnt(long long i, long long j) {
  long long answer = 0;
  for (long long it = 0; it <= 1; it++) {
    long long up = 0;
    long long lin = i;
    long long col = j;
    while (verifica(lin, col) && vizitat[lin][col] == false) {
      if (up % 2 == it) {
        lin--;
      } else {
        col--;
      }
      up++;
    }
    long long down = 0;
    lin = i;
    col = j;
    while (verifica(lin, col) && vizitat[lin][col] == false) {
      if (down % 2 == it) {
        lin++;
      } else {
        col++;
      }
      down++;
    }
    answer += up * down;
  }
  answer--;
  return answer;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      dp[i][j][1] = dp[i][j - 1][0] + 1;
      dp[i][j][0] = dp[i - 1][j][1] + 1;
      ans += dp[i][j][1];
      ans += dp[i][j][0];
    }
  }
  ans -= n * m;
  while (q--) {
    long long lin, col;
    cin >> lin >> col;
    if (vizitat[lin][col] == true) {
      vizitat[lin][col] = false;
      ans += cnt(lin, col);
    } else {
      ans -= cnt(lin, col);
      vizitat[lin][col] = true;
    }
    cout << ans << '\n';
  }
  return 0;
}
