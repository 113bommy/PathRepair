#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e1 + 7;
const long long maxm = 26;
const long long mod = 1e9 + 7;
const long long INF = 1e9 + 7;
const long long mlog = 20;
const long long SQ = 400;
long long n[2];
long long dp[maxn][maxn];
bool mark[2][maxm][maxn][maxn];
string st[2];
vector<pair<long long, long long> > vec[maxm];
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(), cout.tie();
  ;
  cin >> st[0] >> st[1];
  n[0] = st[0].size(), n[1] = st[1].size();
  long long q;
  cin >> q;
  while (q--) {
    string sub;
    cin >> sub;
    vec[sub[0] - 'a'].push_back({sub[3] - 'a', sub[4] - 'a'});
  }
  for (long long s = 0; s <= 1; s++) {
    for (long long len = 1; len <= n[s]; len++) {
      for (long long l = 0, r = len; r <= n[s]; l++, r++) {
        for (long long c = 0; c < maxm; c++) {
          if (len == 1)
            mark[s][c][l][r] = (st[s][l] == c + 'a');
          else {
            for (auto X : vec[c])
              for (long long ptr = l + 1; ptr < r; ptr++) {
                if (mark[s][X.first][l][ptr] && mark[s][X.second][ptr][r])
                  mark[s][c][l][r] = true;
              }
          }
        }
      }
    }
  }
  memset(dp, 63, sizeof(dp));
  dp[0][0] = 0;
  for (long long i = 1; i <= n[0]; i++)
    for (long long j = 1; j <= n[1]; j++)
      for (long long c = 0; c < maxm; c++)
        for (long long l = 0; l < i; l++)
          for (long long r = 0; r < j; r++)
            if (mark[0][c][l][i] && mark[0][c][r][j])
              dp[i][j] = min(dp[i][j], dp[l][r] + 1);
  if (dp[n[0]][n[1]] > maxn) return cout << -1 << "\n", 0;
  cout << dp[n[0]][n[1]] << "\n";
  return 0;
}
