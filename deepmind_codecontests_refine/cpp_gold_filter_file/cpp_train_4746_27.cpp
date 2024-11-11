#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
const int BUFSIZE = (1 << 12) + 17;
char BUF[BUFSIZE + 1], *inp = BUF;
const int MN = 1011;
const int MOD = (int)(1e9 + 7);
int m, n;
char s[MN][MN];
int a[MN][MN];
long long f[MN], cnt[MN][MN];
void solve() {
  memset(cnt, 0, sizeof cnt);
  memset(f, 0, sizeof f);
  f[0] = 1;
  for (int j = (1), _b = (n); j <= _b; j++) {
    bool check = m % 2 == 0;
    for (int i = (1), _b = (m); i <= _b; i++)
      if (a[i][j] == 2) check = false;
    if (check)
      f[j] = f[j - 1];
    else
      f[j] = 0;
    if (j >= 2) {
      cnt[m + 1][j] = 1;
      for (int i = (m), _b = (1); i >= _b; i--) {
        cnt[i][j] = 0;
        if (a[i][j] != 1 && a[i][j - 1] != 1) {
          cnt[i][j] = (cnt[i][j] + cnt[i + 1][j]) % MOD;
        }
        if (i <= m - 1 && a[i][j] != 2 && a[i][j - 1] != 2 &&
            a[i + 1][j] != 2 && a[i + 1][j - 1] != 2) {
          cnt[i][j] = (cnt[i][j] + cnt[i + 2][j]) % MOD;
        }
      }
      for (int i = (1), _b = (m); i <= _b; i++) {
        if ((i - 1) % 2 == 0 && a[i][j] != 1 && a[i][j - 1] != 1) {
          f[j] = (f[j] + f[j - 2] * cnt[i + 1][j]) % MOD;
        }
        if (a[i][j] == 2 || a[i][j - 1] == 2) break;
      }
    }
  }
}
int main() {
  while (scanf("%d%d\n", &m, &n) == 2) {
    for (int i = (1), _b = (4 * m + 1); i <= _b; i++) {
      scanf("%s\n", &s[i][1]);
    }
    for (int i = 1, r = 2; i <= m; ++i, r += 4) {
      for (int j = 1, c = 2; j <= n; ++j, c += 4) {
        int cnt = 0;
        for (int u = (r), _b = (r + 2); u <= _b; u++)
          for (int v = (c), _b = (c + 2); v <= _b; v++)
            if (s[u][v] == 'O') ++cnt;
        if (cnt == 0 || cnt == 1 || cnt == 4 || cnt == 5) {
          a[i][j] = 3;
        } else if (cnt == 2 || cnt == 3) {
          if (s[r][c] == 'O')
            a[i][j] = 2;
          else
            a[i][j] = 1;
        } else {
          if (s[r + 1][c] == 'O')
            a[i][j] = 1;
          else
            a[i][j] = 2;
        }
      }
    }
    solve();
    cout << f[n] << endl;
  }
  return 0;
}
