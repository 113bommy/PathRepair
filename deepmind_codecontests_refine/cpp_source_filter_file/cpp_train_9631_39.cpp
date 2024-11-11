#include <bits/stdc++.h>
using namespace std;
char a[2][4010], b[4010];
int hs[3][4010][2], pw[4010], iv[4010], n, m;
inline int Pow(int x, int y) {
  int rs = 1;
  for (; y; y /= 2, x = x * 1ll * x % 1000000007)
    if (y & 1) rs = rs * 1ll * x % 1000000007;
  return (rs);
}
inline void Prepare() {
  pw[0] = 1;
  for (int i = 1; i <= max(n, m); i++)
    pw[i] = pw[i - 1] * 1ll * 233 % 1000000007;
  for (int i = 0; i <= max(n, m); i++) iv[i] = Pow(pw[i], 1000000007 - 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++)
      hs[i][j][0] =
          (hs[i][j - 1][0] + (a[i][j] - 'a') * 1ll * pw[j] % 1000000007) %
          1000000007;
    for (int j = 1; j <= n; j++)
      hs[i][j][1] = (hs[i][j - 1][1] +
                     (a[i][n - j + 1] - 'a') * 1ll * pw[j] % 1000000007) %
                    1000000007;
  }
  for (int i = 1; i <= m; i++)
    hs[2][i][0] = (hs[2][i - 1][0] + (b[i] - 'a') * 1ll * pw[i] % 1000000007) %
                  1000000007;
}
int s[2][4010][4010], f[2][4010][4010], ans;
inline int Hash(int x, int l, int r, int d) {
  return ((hs[x][r][d] - hs[x][l - 1][d] + 1000000007) % 1000000007 * 1ll *
          iv[l] % 1000000007);
}
inline void Add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
inline void Get_lef(int op) {
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] == b[1]) {
        for (int k = 1; k <= j; k++) {
          int l = j - k + 1;
          int nm0 = Hash(i, n - j + 1, n - k + 1, 1), nm1 = Hash(2, 1, l, 0);
          int nm2 = Hash(i ^ 1, k, j, 0), nm3 = Hash(2, l + 1, l * 2, 0);
          if (Hash(i, n - j + 1, n - k + 1, 1) == Hash(2, 1, l, 0) &&
              Hash(i ^ 1, k, j, 0) == Hash(2, l + 1, l * 2, 0))
            s[i ^ 1][j][l * 2]++;
        }
      }
  if (op) {
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++) Add(ans, s[i][j][m]);
  }
}
inline void Get_mid() {
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == b[1]) Add(f[i][j][1], 1);
      for (int k = 1; k <= m; k++)
        if (a[i][j + 1] == b[k + 1]) f[i][j + 1][k + 1] = s[i][j][k];
    }
  for (int j = 1; j <= n; j++)
    for (int i = 0; i < 2; i++)
      for (int k = 1; k < m; k++)
        if (f[i][j][k]) {
          if (a[i][j + 1] == b[k + 1]) Add(f[i][j + 1][k + 1], f[i][j][k]);
          if (a[i ^ 1][j] == b[k + 1] && k + 2 <= m && k != 1)
            if (a[i ^ 1][j + 1] == b[k + 2])
              Add(f[i ^ 1][j + 1][k + 2], f[i][j][k]);
        }
}
inline void Get_rgt(int op) {
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        if (f[i][j][k]) {
          int res = m - k + 1, l = res / 2;
          if (res == 1) {
            Add(ans, f[i][j][k]);
            continue;
          }
          if (!op && res == m) continue;
          if (res % 2 == 1 || j + l - 1 > n) continue;
          int nm0 = Hash(i, j, j + l - 1, 0), nm1 = Hash(2, k, k + l - 1, 0);
          int nm2 = Hash(i ^ 1, n - (j + l) + 2, n - j + 1, 1),
              nm3 = Hash(2, k + l, k + l * 2 - 1, 0);
          if (Hash(i, j, j + l - 1, 0) == Hash(2, k, k + l - 1, 0) &&
              Hash(i ^ 1, n - (j + l) + 2, n - j + 1, 1) ==
                  Hash(2, k + l, k + l * 2 - 1, 0))
            Add(ans, f[i][j][k]);
        }
}
inline void Solve(int op) {
  Prepare();
  memset(f, 0, sizeof(f));
  memset(s, 0, sizeof(s));
  Get_lef(op);
  Get_mid();
  Get_rgt(op);
}
int main() {
  scanf("%s%s\n", a[0] + 1, a[1] + 1);
  scanf("%s", b + 1);
  n = strlen(a[0] + 1), m = strlen(b + 1);
  if (m == 1) {
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        if (a[i][j] == b[1]) ans++;
    printf("%d\n", ans);
    return (0);
  }
  if (m == 2) {
    int go[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        if (a[i][j] == b[1]) {
          for (int d = 0; i < 4; i++) {
            int ii = i + go[d][0], jj = j + go[d][1];
            if (ii < 0 || ii > 1 || jj < 1 || jj > n) continue;
            if (a[ii][jj] == b[2]) ans++;
          }
        }
    printf("%d\n", ans);
    return (0);
  }
  Solve(1);
  for (int i = 0; i < 2; i++)
    for (int j = 1; j + j <= n; j++) swap(a[i][j], a[i][n - j + 1]);
  Solve(0);
  printf("%d\n", ans);
}
