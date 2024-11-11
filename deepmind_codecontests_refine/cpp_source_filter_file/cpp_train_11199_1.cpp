#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
char S[N][N];
int a1[N * N], b1[N * N], a2[N * N], b2[N * N];
char ch[N * N];
int n, m, k;
long long minn, ans[N][N], g[N][N], s[27][N][N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", S[i] + 1);
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d%d%d", &a1[i], &b1[i], &a2[i], &b2[i]);
    cin >> ch[i];
    s[ch[i] - 'a'][a1[i]][b1[i]]++;
    s[ch[i] - 'a'][a1[i]][b2[i] + 1]--;
    s[ch[i] - 'a'][a2[i] + 1][b1[i]]--;
    s[ch[i] - 'a'][a2[i] + 1][b2[i] + 1]++;
    g[a1[i]][b1[i]]++;
    g[a1[i]][b2[i] + 1]--;
    g[a2[i] + 1][b1[i]]--;
    g[a2[i] + 1][b2[i] + 1]++;
  }
  for (int i = 0; i < 26; ++i)
    for (int x = 1; x <= n; ++x)
      for (int y = 1; y <= m; ++y)
        s[i][x][y] += s[i][x - 1][y] + s[i][x][y - 1] - s[i][x - 1][y - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) s[S[i][j] - 'a'][i][j] += k - g[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int q = 0; q < 26; ++q) {
        int x = abs(S[i][j] - 'a' - q);
        ans[i][j] += x * s[q][i][j];
      }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
  minn = 1000000000LL;
  for (int i = 0; i < 26; ++i)
    for (int x = 1; x <= n; ++x)
      for (int y = 1; y <= m; ++y)
        s[i][x][y] += s[i][x - 1][y] + s[i][x][y - 1] - s[i][x - 1][y - 1];
  for (int i = 1; i <= k; ++i) {
    long long tot = ans[n][m] - ans[a2[i]][b2[i]] + ans[a1[i] - 1][b2[i]] +
                    ans[a2[i]][b1[i] - 1] - ans[a1[i] - 1][b1[i] - 1];
    for (int q = 0; q < 26; ++q) {
      int x = abs(ch[i] - 'a' - q);
      tot += x * (s[q][a2[i]][b2[i]] - s[q][a1[i] - 1][b2[i]] -
                  s[q][a2[i]][b1[i] - 1] + s[q][a1[i] - 1][b1[i] - 1]);
    }
    minn = min(tot, minn);
  }
  printf("%lld\n", minn);
}
