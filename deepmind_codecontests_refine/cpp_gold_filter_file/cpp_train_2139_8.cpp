#include <bits/stdc++.h>
using namespace std;
const int maxN = 4005;
int ti, td, tr, te, n, m;
int f[maxN][maxN], g1[maxN][30], g2[maxN][30];
char s1[maxN], s2[maxN];
void init() {
  scanf("%d%d%d%d", &ti, &td, &tr, &te);
  scanf("%s%s", s1 + 1, s2 + 1);
  n = strlen(s1 + 1);
  m = strlen(s2 + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 26; ++j) g1[i][j] = g1[i - 1][j];
    if (i > 1) g1[i][s1[i - 1] - 96] = i - 1;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= 26; ++j) g2[i][j] = g2[i - 1][j];
    if (i > 1) g2[i][s2[i - 1] - 96] = i - 1;
  }
}
void work() {
  int a, b;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      if (i == 0)
        f[i][j] = ti * j;
      else if (j == 0)
        f[i][j] = td * i;
      else {
        f[i][j] =
            ((f[i - 1][j] + td) < (f[i][j - 1] + ti) ? (f[i - 1][j] + td)
                                                     : (f[i][j - 1] + ti));
        if (s1[i] == s2[j])
          f[i][j] =
              ((f[i][j]) < (f[i - 1][j - 1]) ? (f[i][j]) : (f[i - 1][j - 1]));
        else
          f[i][j] =
              ((f[i][j]) < (f[i - 1][j - 1] + tr) ? (f[i][j])
                                                  : (f[i - 1][j - 1] + tr));
        a = g1[i][s2[j] - 96];
        b = g2[j][s1[i] - 96];
        if (a == 0 || b == 0) continue;
        f[i][j] = ((f[i][j]) < (f[a - 1][b - 1] + td * (i - a - 1) + te +
                                ti * (j - b - 1))
                       ? (f[i][j])
                       : (f[a - 1][b - 1] + td * (i - a - 1) + te +
                          ti * (j - b - 1)));
      }
    }
  printf("%d\n", f[n][m]);
}
int main() {
  init();
  work();
  return 0;
}
