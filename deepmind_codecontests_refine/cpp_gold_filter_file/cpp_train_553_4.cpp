#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const int MAXM = 60;
const int INF = 1000 * 1000 * 1000;
int n, m, r;
int w[MAXN][MAXN][MAXM];
int ans[MAXN][MAXN][MAXN];
int main() {
  cin >> n >> m >> r;
  for (__typeof(m) p = (0); p < (m); ++p) {
    for (__typeof(n) i = (0); i < (n); ++i) {
      for (__typeof(n) j = (0); j < (n); ++j) {
        cin >> w[i][j][p];
      }
    }
  }
  for (__typeof(m) p = (0); p < (m); ++p) {
    for (__typeof(n) k = (0); k < (n); ++k) {
      for (__typeof(n) i = (0); i < (n); ++i) {
        for (__typeof(n) j = (0); j < (n); ++j) {
          w[i][j][p] = min(w[i][j][p], w[i][k][p] + w[k][j][p]);
        }
      }
    }
  }
  for (__typeof(n) i = (0); i < (n); ++i) {
    for (__typeof(n) j = (0); j < (n); ++j) {
      ans[0][i][j] = w[i][j][0];
      for (__typeof(m) p = (0); p < (m); ++p) {
        ans[0][i][j] = min(ans[0][i][j], w[i][j][p]);
      }
    }
  }
  for (__typeof(n) k = (1); k < (n); ++k) {
    for (__typeof(n) i = (0); i < (n); ++i) {
      for (__typeof(n) j = (0); j < (n); ++j) {
        ans[k][i][j] = INF;
        for (__typeof(n) p = (0); p < (n); ++p) {
          ans[k][i][j] = min(ans[k][i][j], ans[k - 1][i][p] + ans[0][p][j]);
        }
      }
    }
  }
  for (__typeof(r) i = (0); i < (r); ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    c = min(c, n - 1);
    --a;
    --b;
    cout << ans[c][a][b] << endl;
  }
  return 0;
}
