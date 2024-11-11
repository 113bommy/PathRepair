#include <bits/stdc++.h>
using namespace std;
const int N = 200200, D = 26;
int i, j, k, n, m, x, y, ans;
int pp[N], p[N][D], a[D][N], sa[D][N], sa2[D][N], na[D], b[D][N], nb[D], Ans[N];
char S[N], T[N];
void W(int x) {
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  memset(p, -1, sizeof p);
  scanf("%d%d", &n, &m);
  scanf("%s", S + 1);
  scanf("%s", T + 1);
  for (i = 0; i < D; i++) {
    int t = 0;
    for (j = 1; j <= n; j++) {
      if (S[j] == 'a' + i) {
        a[i][++na[i]] = j - t - 1;
        t = j;
        sa2[i][j] = 1;
      }
      sa2[i][j] += sa2[i][j - 1];
    }
    a[i][++na[i]] = n - t;
    for (j = 1; j <= na[i]; j++) sa[i][j] = sa[i][j - 1] + a[i][j] + 1;
  }
  for (i = 0; i < D; i++) {
    int t = 0;
    for (j = 1; j <= n; j++)
      if (T[j] == 'a' + i) b[i][++nb[i]] = j - t - 1, t = j;
    b[i][++nb[i]] = m - t;
  }
  for (x = 0; x < D; x++)
    if (na[x] > 1) {
      for (y = 0; y < D; y++)
        if (nb[y] > 1) {
          j = 1;
          pp[1] = pp[2] = 1;
          for (i = 3; i < nb[y]; i++) {
            while (j > 1 && b[y][j + 1] != b[y][i]) j = pp[j];
            if (b[y][j + 1] == b[y][i])
              pp[i] = ++j;
            else
              pp[i] = j;
          }
          j = 1;
          for (i = 1; i <= na[x]; i++) {
            while (j > 1 && b[y][j + 1] != a[x][i]) j = pp[j];
            if (j + 1 < nb[y] && b[y][j + 1] == a[x][i]) j++;
            if (j == nb[y] - 1) {
              if (i + 1 <= na[x] && i - (nb[y] - 2) >= 1 &&
                  a[x][i + 1] >= b[y][nb[y]] &&
                  a[x][i - (nb[y] - 2)] >= b[y][1])
                p[sa[x][i] + b[y][nb[y]] - m + 1][x] = y;
              j = pp[j];
            }
          }
        }
    }
  for (i = 1; i + m - 1 <= n; i++) {
    int Fg = 1;
    for (j = 0; j < D; j++)
      if (p[i][j] != -1) {
        int &k = p[i][p[i][j]];
        if (k == -1) {
          if (sa2[k][i + m - 1] - sa2[k][i - 1] == 0 && nb[j] == 1)
            k = j;
          else
            Fg = 0;
        } else {
          if (k != j) Fg = 0;
        }
      }
    for (j = 0; j < D; j++)
      if (p[i][j] == -1) {
        if (sa2[j][i + m - 1] - sa2[j][i - 1] > 0 && nb[j] > 1) Fg = 0;
      }
    if (Fg) Ans[++ans] = i;
  }
  W(ans);
  puts("");
  for (i = 1; i <= ans; i++) W(Ans[i]), putchar(' ');
  puts("");
}
