#include <bits/stdc++.h>
using namespace std;
vector<int> odd;
vector<int> eve;
int f[2010][1010][11], g[2010][2010][11];
int T, n, cnt[2010], m;
char s[20];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    odd.clear();
    eve.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);
      int L = strlen(s);
      reverse(s, s + L);
      cnt[i] = 0;
      for (int j = 0; j < L; ++j)
        (cnt[i] += j & 1 ? 11 - (s[j] - '0') : s[j] - '0') %= 11;
      if (L & 1)
        odd.push_back(cnt[i]);
      else
        eve.push_back(cnt[i]);
    }
    n = odd.size();
    m = eve.size();
    memset(f[0], 0, sizeof(f[0]));
    f[0][n / 2][0] = 1;
    for (int i = 0; i < n; ++i) {
      memset(f[i + 1], 0, sizeof(f[i + 1]));
      for (int j = 0; j <= n / 2; ++j)
        for (int k = 0; k < 11; ++k)
          if (f[i][j][k]) {
            if (j)
              (f[i + 1][j - 1][(k + 11 - odd[i]) % 11] +=
               (long long)f[i][j][k] * j % 998244353) %= 998244353;
            if (n - i - j > 0)
              (f[i + 1][j][(k + odd[i]) % 11] +=
               (long long)f[i][j][k] * (n - i - j) % 998244353) %= 998244353;
          }
    }
    memset(g[0], 0, sizeof(g[0]));
    for (int i = 0; i < 11; ++i) (g[0][0][i] += f[n][0][i]) %= 998244353;
    for (int i = 0; i < m; ++i) {
      memset(g[i + 1], 0, sizeof(g[i + 1]));
      for (int j = 0; j <= i; ++j)
        for (int k = 0; k < 11; ++k)
          if (g[i][j][k]) {
            (g[i + 1][j + 1][(k + eve[i]) % 11] +=
             (long long)g[i][j][k] * (n / 2 + 1 + j) % 998244353) %= 998244353;
            (g[i + 1][j][(k + 11 - eve[i]) % 11] +=
             (long long)g[i][j][k] * ((n + 1) / 2 + (i - j)) % 998244353) %=
                998244353;
          }
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i) (ans += g[m][i][0]) %= 998244353;
    printf("%d\n", ans);
  }
  return 0;
}
