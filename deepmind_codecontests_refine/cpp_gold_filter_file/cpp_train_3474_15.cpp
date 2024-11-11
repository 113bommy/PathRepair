#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 15;
int n, m, k;
int s1[maxn][maxn], s2[maxn][maxn];
int a[maxn][maxn];
long long ans1, sum, ss;
int ansx, ansy;
char ch;
int xx;
int getint() {
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    ;
  for (xx = 0; ch >= '0' && ch <= '9'; xx = xx * 10 + ch - '0', ch = getchar())
    ;
  return xx;
}
int main() {
  n = getint();
  m = getint();
  k = getint();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = getint();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s1[i][j] = a[i][j] + s1[i - 1][j - 1],
      s2[i][j] = a[i][j] + s2[i - 1][j + 1];
  int tj = 0;
  for (int i = k; i <= n - k + 1; i++)
    for (int j = k; j <= m - k + 1; j++) {
      int ux, dx, ly, ry;
      sum = a[i][j];
      ss = a[i][j];
      for (int l = 1; l < k; l++) {
        ux = i - l, dx = i + l, ly = j - l, ry = j + l;
        ss += s2[i][ly] - s2[ux - 1][j + 1] + s2[dx][j] - s2[i - 1][ry + 1] +
              s1[i - 1][ry - 1] - s1[ux][j] + s1[dx - 1][j - 1] - s1[i][ly];
        sum += ss;
      }
      if (sum >= ans1) ans1 = sum, ansx = i, ansy = j;
      tj += k;
      if (tj > 50000000) break;
    }
  printf("%d %d\n", ansx, ansy);
  return 0;
}
