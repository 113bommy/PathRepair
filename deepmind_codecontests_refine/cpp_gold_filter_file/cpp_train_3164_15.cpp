#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1011][1011];
char hor[1011][1011], ver[1011][1011];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < (2 * n - 1); ++i) {
    if (i % 2)
      scanf("%s", ver[i / 2]);
    else
      scanf("%s", hor[i / 2]);
  }
  if (k == 1) {
    int cn = 0, ce = 0;
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (m - 1); ++j)
        if (hor[i][j] == 'N')
          cn++;
        else
          ce++;
    for (int i = 0; i < (n - 1); ++i)
      for (int j = 0; j < (m); ++j)
        if (ver[i][j] == 'N')
          cn++;
        else
          ce++;
    if (ce * 4 < (cn + ce) * 3)
      puts("NO");
    else {
      puts("YES");
      for (int i = 0; i < (n); ++i) {
        for (int j = 0; j < (m); ++j) printf("1 ");
        puts("");
      }
    }
    return 0;
  }
  if (n < m) {
    for (int i = 0; i < (n); ++i) {
      a[i][0] = 1;
      for (int j = 0; j < (m - 1); ++j) {
        if (hor[i][j] == 'E')
          a[i][j + 1] = a[i][j];
        else
          a[i][j + 1] = 3 - a[i][j];
      }
      if (i == 0) continue;
      int un = 0;
      for (int j = 0; j < (m); ++j)
        if ((a[i][j] == a[i - 1][j] && ver[i - 1][j] == 'N') ||
            (a[i][j] != a[i - 1][j] && ver[i - 1][j] == 'E'))
          un++;
      if (un > m - un) {
        for (int j = 0; j < (m); ++j) a[i][j] = 3 - a[i][j];
      }
    }
  } else {
    for (int i = 0; i < (m); ++i) {
      a[0][i] = 1;
      for (int j = 0; j < (n - 1); ++j) {
        if (ver[j][i] == 'E')
          a[j + 1][i] = a[j][i];
        else
          a[j + 1][i] = 3 - a[j][i];
      }
      if (i == 0) continue;
      int un = 0;
      for (int j = 0; j < (n); ++j)
        if ((a[j][i] == a[j][i - 1] && hor[j][i - 1] == 'N') ||
            (a[j][i] != a[j][i - 1] && hor[j][i - 1] == 'E'))
          un++;
      if (un > n - un) {
        for (int j = 0; j < (n); ++j) a[j][i] = 3 - a[j][i];
      }
    }
  }
  puts("YES");
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) printf("%d ", a[i][j]);
    puts("");
  }
  return 0;
}
