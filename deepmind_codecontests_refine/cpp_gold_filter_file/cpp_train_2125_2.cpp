#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int m, n, nv, p[N];
char s1[N], s2[N], virus[N];
bool maximize(int& a, int b) { return a < b ? (a = b, true) : false; }
int dp[N][N][N], trace[N][N][N];
int nxt[N][N];
char ans[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s1 + 1 >> s2 + 1 >> virus;
  m = strlen(s1 + 1), n = strlen(s2 + 1), nv = strlen(virus);
  nxt[0][virus[0]] = 1;
  for (int i = 1, j = 0; i < nv; ++i) {
    while (j && virus[i] != virus[j]) j = p[j - 1];
    if (virus[i] == virus[j]) ++j;
    p[i] = j;
    for (int j = 'A'; j <= 'Z'; ++j)
      nxt[i][j] = (virus[i] == j ? i + 1 : nxt[p[i - 1]][j]);
  }
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      fill(trace[i][j], trace[i][j] + nv, -1);
      for (int k = 0; k < nv; ++k) {
        if (maximize(dp[i][j][k], dp[i - 1][j][k])) trace[i][j][k] = -1;
        if (maximize(dp[i][j][k], dp[i][j - 1][k])) trace[i][j][k] = -1;
        if (s1[i] == s2[j]) {
          int x = nxt[k][s1[i]];
          if (x < nv && maximize(dp[i][j][x], dp[i - 1][j - 1][k] + 1))
            trace[i][j][x] = k;
        }
      }
    }
  int pos = max_element(dp[m][n], dp[m][n] + nv) - dp[m][n],
      len = dp[m][n][pos];
  if (len) {
    while (len) {
      if (~trace[m][n][pos]) {
        ans[--len] = s1[m];
        pos = trace[m--][n--][pos];
      } else if (dp[m][n][pos] == dp[m - 1][n][pos])
        --m;
      else
        --n;
    }
    cout << ans;
  } else
    cout << 0;
}
