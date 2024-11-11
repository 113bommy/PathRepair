#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, w, lo, hi, a[100005], C[15][15];
double p[100005][110], buf[110], A, B, t, pr, ret;
int main() {
  for (int i = (0); i < (10); i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = (1); j < (i); j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) {
    scanf("%d", &a[i]);
    p[i][a[i]] = 1;
    ret += p[i][0];
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &x, &y, &w), --x, --y;
    ret -= p[x][0];
    for (int i = (0); i <= (100); i++) buf[i] = p[x][i], p[x][i] = 0;
    for (int i = (0); i <= (100); i++) {
      if (i > a[x]) break;
      A = i, B = a[x] - i, t = 1;
      lo = min(w, w - a[x] + i);
      hi = min(w, i);
      for (int j = (0); j < (lo); j++) t = t * A / (A + B), --A;
      for (int j = (0); j < (w - lo); j++) t = t * B / (A + B), --B;
      for (int j = (lo); j <= (hi); j++) {
        p[x][i - j] += t * buf[i] * C[w][j];
        t = t * A / (B + 1), --A, ++B;
      }
    }
    ret += p[x][0];
    a[x] -= w;
    a[y] += w;
    printf("%.12f\n", ret);
  }
  return 0;
}
