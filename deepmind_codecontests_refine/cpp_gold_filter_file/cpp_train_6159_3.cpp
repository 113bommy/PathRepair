#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void OFAST() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
const short N = 1011;
short dp[N][55][55], d1[55], d2[55], n, s1, s2;
bool vis[N][55][55];
char s[N], a[55], b[55];
int main() {
  scanf("%s%s%s", s + 1, a + 1, b + 1);
  n = strlen(s + 1), s1 = strlen(a + 1), s2 = strlen(b + 1);
  for (short i = 2, j = 0; i <= s1; ++i) {
    while (j && a[j + 1] != a[i]) j = d1[j];
    if (a[j + 1] == a[i]) ++j;
    d1[i] = j;
  }
  for (short i = 2, j = 0; i <= s2; ++i) {
    while (j && b[j + 1] != b[i]) j = d2[j];
    if (b[j + 1] == b[i]) ++j;
    d2[i] = j;
  }
  vis[0][0][0] = true;
  char cc;
  short u, v, tmp;
  for (short i = 0; i < n; ++i)
    for (short j = 0; j <= s1; ++j)
      for (short z = 0; z <= s2; ++z)
        if (vis[i][j][z]) {
          if (s[i + 1] != '*') {
            cc = s[i + 1];
            u = j, v = z;
            while (u && a[u + 1] != cc) u = d1[u];
            while (v && b[v + 1] != cc) v = d2[v];
            if (a[u + 1] == cc) ++u;
            if (b[v + 1] == cc) ++v;
            tmp = 0;
            if (u == s1) ++tmp;
            if (v == s2) --tmp;
            if (!vis[i + 1][u][v] ||
                (vis[i + 1][u][v] && dp[i + 1][u][v] < dp[i][j][z] + tmp)) {
              vis[i + 1][u][v] = true;
              dp[i + 1][u][v] = dp[i][j][z] + tmp;
            }
          } else {
            for (cc = 'a'; cc <= 'z'; ++cc) {
              u = j, v = z;
              while (u && a[u + 1] != cc) u = d1[u];
              while (v && b[v + 1] != cc) v = d2[v];
              if (a[u + 1] == cc) ++u;
              if (b[v + 1] == cc) ++v;
              tmp = 0;
              if (u == s1) ++tmp;
              if (v == s2) --tmp;
              if (!vis[i + 1][u][v] ||
                  (vis[i + 1][u][v] && dp[i + 1][u][v] < dp[i][j][z] + tmp)) {
                vis[i + 1][u][v] = true;
                dp[i + 1][u][v] = dp[i][j][z] + tmp;
              }
            }
          }
        }
  short ans = -1000;
  for (short i = 0; i <= s1; ++i)
    for (short j = 0; j <= s2; ++j)
      if (vis[n][i][j]) ans = max(ans, dp[n][i][j]);
  printf("%hd", ans);
}
