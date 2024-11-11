#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 500 + 5;
const int K = 26;
char f[N][N];
bool read() {
  if (!(cin >> n >> m)) return false;
  for (int i = 0; i < int(n); ++i) cin >> f[i];
  return true;
}
pair<int, pair<int, int> > mn[4][K][K], dp[N][K][K];
int cnt[2][K];
void solve() {
  int cb = m / 2;
  int ca = m - cb;
  for (int i = 0; i < int(K); ++i)
    for (int j = 0; j < int(K); ++j) dp[0][i][j].first = (i == j ? N * N : 0);
  for (int i = 0; i < int(n); ++i) {
    for (int t = 0; t < int(4); ++t)
      for (int j = 0; j < int(K); ++j)
        for (int k = 0; k < int(K); ++k) mn[t][j][k].first = N * N;
    for (int a = 0; a < int(K); ++a)
      for (int b = 0; b < int(K); ++b) {
        int c = K - a - 1;
        int d = K - b - 1;
        for (int t = 0; t < int(4); ++t) {
          int rx = ((t >> 1) & 1);
          int ry = (t & 1);
          int x = rx ? c : a;
          int y = ry ? d : b;
          int nx = x + (rx ? +1 : -1);
          int ny = y + (ry ? +1 : -1);
          mn[t][x][y] = make_pair(dp[i][x][y].first, make_pair(x, y));
          if (0 <= nx && nx < K) mn[t][x][y] = min(mn[t][x][y], mn[t][nx][y]);
          if (0 <= ny && ny < K) mn[t][x][y] = min(mn[t][x][y], mn[t][n][ny]);
        }
      }
    for (int j = 0; j < int(2); ++j)
      for (int k = 0; k < int(K); ++k) cnt[j][k] = 0;
    for (int j = 0; j < int(m); ++j) cnt[j & 1][f[i][j] - 'a']++;
    for (int a = 0; a < int(K); ++a) {
      for (int b = 0; b < int(K); ++b) {
        dp[i + 1][a][b].first = N * N;
        if (a != b) {
          for (int t = 0; t < int(4); ++t) {
            int dx = ((t >> 1) & 1) ? +1 : -1;
            int dy = (t & 1) ? +1 : -1;
            int na = a + dx;
            int nb = b + dy;
            if ((0 <= na && na < K) && (0 <= nb && nb < K))
              dp[i + 1][a][b] = min(dp[i + 1][a][b], mn[t][na][nb]);
          }
          dp[i + 1][a][b].first += (ca - cnt[0][a]) + (cb - cnt[1][b]);
        }
      }
    }
  }
  int a = 0, b = 0;
  for (int i = 0; i < int(K); ++i)
    for (int j = 0; j < int(K); ++j)
      if (dp[n][i][j] < dp[n][a][b]) a = i, b = j;
  printf("%d\n", dp[n][a][b].first);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < int(m); ++j) f[i][j] = ((j & 1) ? b : a) + 'a';
    pair<int, int> p = dp[i + 1][a][b].second;
    a = p.first, b = p.second;
  }
  for (int i = 0; i < int(n); ++i) puts(f[i]);
}
int main() {
  while (read()) solve();
  return 0;
}
