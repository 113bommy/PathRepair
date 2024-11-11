#include <bits/stdc++.h>
using namespace std;
const int maxn = 152;
const int maxp = 51123987;
static int A[maxn], len;
static int opt[maxn][52][52][52], n, Ne[maxn][4];
char s[maxn];
static int idx[maxn * 10];
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) {
    s[++len] = getchar();
    if (s[len] == s[len - 1]) len--;
  }
  for (int i = len; i; i--) {
    int kd = s[i] == 'a';
    if (s[i] == 'b') kd = 2;
    if (s[i] == 'c') kd = 3;
    Ne[i][1] = Ne[i + 1][1];
    Ne[i][2] = Ne[i + 1][2];
    Ne[i][3] = Ne[i + 1][3];
    Ne[i][kd] = i;
  }
  int mxl = (n - 1) / 3 + 1;
  opt[Ne[1][1]][1][0][0] = 1;
  opt[Ne[1][2]][0][1][0] = 1;
  opt[Ne[1][3]][0][0][1] = 1;
  for (int i = 1; i <= len; i++)
    for (int j = 0; j <= mxl; j++)
      for (int k = 0; k <= mxl; k++)
        for (int l = 0; l <= mxl; l++) {
          opt[Ne[i][1]][j + 1][k][l] =
              opt[Ne[i][1]][j + 1][k][l] + opt[i][j][k][l];
          if (opt[Ne[i][1]][j + 1][k][l] >= maxp)
            opt[Ne[i][1]][j + 1][k][l] -= maxp;
          opt[Ne[i][2]][j][k + 1][l] =
              opt[Ne[i][2]][j][k + 1][l] + opt[i][j][k][l];
          if (opt[Ne[i][2]][j][k + 1][l] >= maxp)
            opt[Ne[i][2]][j + 1][k][l] -= maxp;
          opt[Ne[i][3]][j][k][l + 1] =
              opt[Ne[i][3]][j][k][l + 1] + opt[i][j][k][l];
          if (opt[Ne[i][3]][j][k][l + 1] >= maxp)
            opt[Ne[i][3]][j][k][l + 1] -= maxp;
        }
  int ans = 0;
  for (int i = 1; i <= len; i++) {
    if (n % 3 == 0) ans = (ans + opt[i][mxl][mxl][mxl]) % maxp;
    if (n % 3 == 1)
      ans = (ans + opt[i][mxl - 1][mxl - 1][mxl] +
             opt[i][mxl - 1][mxl][mxl - 1] + opt[i][mxl][mxl - 1][mxl - 1]) %
            maxp;
    if (n % 3 == 2)
      ans = (ans + opt[i][mxl][mxl - 1][mxl] + opt[i][mxl - 1][mxl][mxl] +
             opt[i][mxl][mxl][mxl - 1]) %
            maxp;
  }
  printf("%d\n", ans);
  return 0;
}
