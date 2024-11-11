#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 2005;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
int n, m, Ans;
char s[2][N], t[N];
int f[2][N][N], g[2][N][N];
int L1[2][N][N], L2[2][N][N];
int R1[2][N][N], R2[2][N][N];
bool U1[2][N][N], U2[2][N][N];
int mod(int x) { return x >= Mod ? x - Mod : x; }
void Prepare() {
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++)
        L1[i][j][k] = (s[i][j] == t[k] ? L1[i][j - 1][k - 1] + 1 : 0);
      for (int k = m; k >= 1; k--)
        L2[i][j][k] = (s[i][j] == t[k] ? L2[i][j - 1][k + 1] + 1 : 0);
    }
    for (int j = n; j >= 1; j--) {
      for (int k = 1; k <= m; k++)
        R1[i][j][k] = (s[i][j] == t[k] ? R1[i][j + 1][k - 1] + 1 : 0);
      for (int k = m; k >= 1; k--)
        R2[i][j][k] = (s[i][j] == t[k] ? R2[i][j + 1][k + 1] + 1 : 0);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= min(m / 2, j); k++)
        U1[i][j][k] = (L1[i][j][k * 2] >= k && R1[i ^ 1][j - k + 1][k] >= k);
      for (int k = 1; k <= min(m / 2, n - j + 1); k++)
        U2[i][j][k] = (R2[i][j][m - k * 2 + 1] >= k &&
                       L2[i ^ 1][j + k - 1][m - k + 1] >= k);
    }
  }
}
void Solve() {
  Prepare();
  if (!(m & 1)) {
    for (int j = 1; j <= n; j++) {
      Ans = mod(Ans + U1[0][j][m / 2] + U2[0][j][m / 2]);
      for (int i = 0; i < 2; i++) {
        for (int k = 2; k <= m / 2 - 2; k++) {
          Ans = mod(Ans + U1[i][j][k] * U2[i][j + 1][m / 2 - k]);
        }
      }
    }
  }
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < 2; i++) {
      if (s[i][j] == t[1]) f[i][j][1] = mod(f[i][j][1] + 1);
      for (int k = 2; k <= m / 2; k++) {
        if (U1[i][j - 1][k] && s[i][j] == t[k + k + 1])
          f[i][j][k + k + 1] = mod(f[i][j][k + k + 1] + 1);
      }
      for (int k = 1; k <= m; k++) {
        if (s[i][j] == t[k])
          f[i][j][k] =
              mod(f[i][j][k] + mod(f[i][j - 1][k - 1] + g[i][j - 1][k - 1]));
        if (s[i ^ 1][j] == t[k + 1])
          g[i ^ 1][j][k + 1] = mod(g[i ^ 1][j][k + 1] + f[i][j][k]);
      }
    }
    for (int i = 0; i < 2; i++) {
      Ans = mod(Ans + mod(f[i][j][m] + g[i][j][m]));
      for (int k = 2; k <= m / 2; k++) {
        if (U2[i][j + 1][k])
          Ans = mod(Ans + mod(f[i][j][m - k * 2] + g[i][j][m - k * 2]));
      }
    }
  }
}
int main() {
  scanf("%s%s%s", s[0] + 1, s[1] + 1, t + 1);
  n = strlen(s[0] + 1);
  m = strlen(t + 1);
  if (m == 1) {
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++) Ans += (s[i][j] == t[1]);
    printf("%d", Ans);
    return 0;
  }
  if (m == 2) {
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        Ans += (s[i][j] == t[1] && s[i ^ 1][j] == t[2]);
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        Ans += (s[i][j] == t[1] && s[i][j - 1] == t[2]);
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        Ans += (s[i][j] == t[1] && s[i][j + 1] == t[2]);
    printf("%d", Ans);
    return 0;
  }
  Solve();
  reverse(t + 1, t + m + 1);
  Solve();
  printf("%d", Ans);
  return 0;
}
