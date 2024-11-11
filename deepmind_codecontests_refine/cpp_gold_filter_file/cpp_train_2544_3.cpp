#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
char s[N];
int a[N][N];
int res[N][N];
int c[5] = {1, 2, 3, 4};
void out() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%d", res[i][j]);
    puts("");
  }
  exit(0);
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i) {
    gets(s);
    for (int j = 0; j < m; ++j) a[i][j] = s[j] - '0';
  }
  do {
    bool ok;
    for (int i = 0; i < n; ++i) {
      ok = true;
      for (int j = 0; j < m; ++j) {
        if (a[i][j] && a[i][j] != c[j % 2 + (i & 1 ? 2 : 0)]) ok = false;
        res[i][j] = c[j % 2 + (i & 1 ? 2 : 0)];
      }
      if (!ok) {
        ok = true;
        for (int j = 0; j < m; ++j) {
          if (a[i][j] && a[i][j] != c[(j + 1) % 2 + (i & 1 ? 2 : 0)]) goto end;
          res[i][j] = c[(j + 1) % 2 + (i & 1 ? 2 : 0)];
        }
      }
    }
    out();
  end:;
    for (int i = 0; i < m; ++i) {
      ok = true;
      for (int j = 0; j < n; ++j) {
        if (a[j][i] && a[j][i] != c[j % 2 + (i & 1 ? 2 : 0)]) ok = false;
        res[j][i] = c[j % 2 + (i & 1 ? 2 : 0)];
      }
      if (!ok) {
        ok = true;
        for (int j = 0; j < n; ++j) {
          if (a[j][i] && a[j][i] != c[(j + 1) % 2 + (i & 1 ? 2 : 0)]) goto end2;
          res[j][i] = c[(j + 1) % 2 + (i & 1 ? 2 : 0)];
        }
      }
    }
    out();
  end2:;
  } while (next_permutation(c, c + 4));
  puts("0");
  return 0;
}
