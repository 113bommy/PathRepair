#include <bits/stdc++.h>
using namespace std;
int dp[155][55][55][55], n, m;
char s[155];
int nxt[155][3], ans;
const int md = 51123987;
inline void add(int& x, int y) {
  x += y;
  if (x >= md) x -= md;
}
inline bool ck(int a, int b, int c) {
  return max(a, max(b, c)) - min(a, min(b, c)) < 2;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int j = 0; j < 3; ++j) nxt[n + 1][j] = n + 1;
  for (int i = n; i; --i) {
    for (int j = 0; j < 3; ++j) nxt[i][j] = nxt[i + 1][j];
    nxt[i][s[i] - 'a'] = i;
  }
  m = (n + 2) / 3;
  dp[1][0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int a = 0; a <= m; ++a) {
      for (int b = 0; b <= m; ++b) {
        for (int c = 0; c <= m; ++c) {
          int t = dp[i][a][b][c];
          if (a + b + c == n and ck(a, b, c)) add(ans, t);
          add(dp[nxt[i][0]][a + 1][b][c], t);
          add(dp[nxt[i][1]][a][b + 1][c], t);
          add(dp[nxt[i][2]][a][b][c + 1], t);
        }
      }
    }
  }
  cout << ans << '\n';
}
