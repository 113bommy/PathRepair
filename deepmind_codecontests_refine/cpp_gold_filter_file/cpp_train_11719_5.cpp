#include <bits/stdc++.h>
using namespace std;
const int c = 256;
const int inf = 1000000000;
char s[c];
int n, m, p;
int a[c][c];
int r[c][c][c];
char h, g;
int main() {
  scanf("%s", s);
  m = strlen(s);
  scanf("%d", &n);
  scanf("%d", &p);
  int i;
  for (i = 1; i <= p; ++i) {
    do h = getchar();
    while (!isalpha(h));
    do g = getchar();
    while (!isalpha(g));
    scanf("%d", &a[h][g]);
  }
  int j, k, l;
  for (i = 0; i < c; ++i)
    for (j = 0; j < c; ++j)
      for (k = 0; k < c; ++k) r[i][j][k] = -inf;
  r[0][0][0] = 0;
  for (i = 1; i <= m; ++i) {
    if (i == 1) {
      if (n > 0)
        for (k = 'a'; k <= 'z'; ++k) r[i][1][k] = 0;
      r[i][0][s[0]] = 0;
    } else
      for (j = 0; j <= n; ++j)
        for (k = 'a'; k <= 'z'; ++k)
          if (r[i - 1][j][k] > -inf) {
            if (j < n)
              for (l = 'a'; l <= 'z'; ++l)
                if (r[i][j + 1][l] < r[i - 1][j][k] + a[k][l])
                  r[i][j + 1][l] = r[i - 1][j][k] + a[k][l];
            if (r[i][j][s[i - 1]] < r[i - 1][j][k] + a[k][s[i - 1]])
              r[i][j][s[i - 1]] = r[i - 1][j][k] + a[k][s[i - 1]];
          }
  }
  int ans = -inf;
  for (j = 0; j <= n; ++j)
    for (k = 'a'; k <= 'z'; ++k)
      if (ans < r[m][j][k]) ans = r[m][j][k];
  printf("%d\n", ans);
  return 0;
}
