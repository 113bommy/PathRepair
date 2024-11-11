#include <bits/stdc++.h>
int n, m;
char mat[510][510];
char check(int i, int j) {
  if (mat[i][j] != 'W') return 0;
  if (mat[i + 1][j] == 'S') return 1;
  if (mat[i - 1][j] == 'S') return 1;
  if (mat[i][j + 1] == 'S') return 1;
  if (mat[i][j - 1] == 'S') return 1;
  return 0;
}
int main() {
  int i, j;
  char ok = true, aux[10];
  scanf("%i%i", &n, &m);
  fgets(aux, 10, stdin);
  for (i = 1; i <= n; ++i) {
    fgets(&mat[i][1], 508, stdin);
  }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (mat[i][j] != 'D' && mat[i][j] != 'S' && mat[i][j] != 'W')
        mat[i][j] = 'D';
  for (i = 1; i <= n && ok; ++i)
    for (j = 1; j <= m && ok; ++j)
      if (check(i, j)) ok = false;
  if (ok) {
    printf("Yes\n");
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) printf("%c", mat[i][j]);
      printf("\n");
    }
  } else
    printf("No\n");
  return 0;
}
