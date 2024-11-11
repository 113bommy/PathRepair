#include <bits/stdc++.h>
using namespace std;
const int maxn = 107;
inline void read(int &x) {
  int w = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= w;
}
int r, s, p;
double f[maxn][maxn][maxn][3];
int main() {
  scanf("%d%d%d", &r, &s, &p);
  for (int i = 0; i <= (int)(r); ++i)
    for (int j = 0; j <= (int)(s); ++j) f[i][j][0][0] = 1;
  for (int i = 0; i <= (int)(r); ++i)
    for (int j = 0; j <= (int)(p); ++j) f[i][0][j][2] = 1;
  for (int i = 0; i <= (int)(s); ++i)
    for (int j = 0; j <= (int)(p); ++j) f[0][i][j][1] = 1;
  for (int i = 1; i <= (int)(r); ++i)
    for (int j = 1; j <= (int)(s); ++j)
      for (int k = 1; k <= (int)(p); ++k) {
        double N = i * j + i * k + j * k;
        if (N == 0) continue;
        double a = (i * j) / N, b = (j * k) / N, c = (i * k) / N;
        f[i][j][k][0] = a * f[i - 1][j][k][0] + b * f[i][j - 1][k][0] +
                        c * f[i][j][k - 1][0];
        f[i][j][k][1] = a * f[i - 1][j][k][1] + b * f[i][j - 1][k][1] +
                        c * f[i][j][k - 1][1];
        f[i][j][k][2] = a * f[i - 1][j][k][2] + b * f[i][j - 1][k][2] +
                        c * f[i][j][k - 1][2];
      }
  printf("%.12lf %.12lf %.12lf\n", f[r][s][p][0], f[r][s][p][1], f[r][s][p][2]);
  return 0;
}
