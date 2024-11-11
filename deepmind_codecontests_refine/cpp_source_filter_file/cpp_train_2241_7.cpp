#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n;
int x[55];
char mat[1550][1550];
int main() {
  for (int i = 0; i < 55; ++i)
    for (int j = 0; j < 55; ++j) mat[i][j] = '.';
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  int r, ar;
  if (a % 2 == 0)
    r = 0, ar = 1;
  else
    r = b - 1, ar = -1;
  int dx = 0;
  for (int i = 0; i < a + c; ++i) {
    int h;
    if (i < a)
      h = b;
    else
      h = d;
    while (r >= 0 && r < h) {
      while (dx < n && x[dx] == 0) dx++;
      x[dx]--;
      mat[r][i] = 'a' + dx;
      r += ar;
    }
    ar *= -1;
    r += ar;
  }
  if (dx == n || x[dx] != 0 || x[dx + 1] != 0)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < max(b, d); ++i) {
      for (int j = 0; j < a + c; ++j) printf("%c", mat[i][j]);
      printf("\n");
    }
  }
  return 0;
}
