#include <bits/stdc++.h>
using namespace std;
int n, m, c[1001][1001];
char h[1010][1010], l[1010][1010], s1[1010][1010], s2[1010][1010];
bool check() {
  int i, j, sum = 0;
  for (i = 1; i <= n; i++)
    for (j = 0; j < m - 1; j++)
      if (h[i][j] == 'E') sum++;
  for (i = 1; i < n; i++)
    for (j = 0; j < m; j++)
      if (l[i][j] == 'E') sum++;
  int t = (n * (m - 1) + m * (n - 1)) * 3 - 1;
  if (sum <= t / 4) return false;
  return true;
}
void rd() {
  int i, j;
  for (i = 1; i <= m; i++) {
    for (j = 1; j < n; j++) s1[i][j - 1] = l[j][i - 1];
    s1[i][n - 1] = 0;
  }
  for (i = 1; i < m; i++) {
    for (j = 1; j <= n; j++) s2[i][j - 1] = h[j][i - 1];
    s2[i][n] = 0;
  }
  memmove(h, s1, sizeof(h));
  memmove(l, s2, sizeof(l));
}
int main() {
  int i, j, k, t;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i < n + n; i++)
    if (i & 1)
      scanf(" %s", h[i / 2 + 1]);
    else
      scanf(" %s", l[i / 2]);
  if (k == 1) {
    if (check()) {
      puts("YES");
      for (i = 1; i <= n; i++) {
        for (j = 1; j < m; j++) printf("1 ");
        puts("1");
      }
    } else
      puts("NO");
  } else {
    bool bo = false;
    if (n > m) {
      rd();
      swap(n, m);
      bo = true;
    }
    c[1][1] = 1;
    for (i = 2; i <= m; i++)
      if (h[1][i - 2] == 'E')
        c[1][i] = c[1][i - 1];
      else
        c[1][i] = 3 - c[1][i - 1];
    for (i = 2; i <= n; i++) {
      c[i][1] = 1;
      for (j = 2; j <= m; j++)
        if (h[i][j - 2] == 'E')
          c[i][j] = c[i][j - 1];
        else
          c[i][j] = 3 - c[i][j - 1];
      int sum = 0;
      for (j = 1; j <= m; j++)
        if (l[i - 1][j - 1] == 'E') {
          if (c[i][j] != c[i - 1][j]) sum++;
        } else if (c[i][j] == c[i - 1][j])
          sum++;
      if (sum > m / 2)
        for (j = 1; j <= m; j++) c[i][j] = 3 - c[i][j];
    }
    puts("YES");
    if (!bo) {
      for (i = 1; i <= n; i++) {
        for (j = 1; j < m; j++) printf("%d ", c[i][j]);
        printf("%d\n", c[i][m]);
      }
    } else {
      for (i = 1; i <= m; i++) {
        for (j = 1; j < n; j++) printf("%d ", c[j][i]);
        printf("%d\n", c[n][i]);
      }
    }
  }
}
