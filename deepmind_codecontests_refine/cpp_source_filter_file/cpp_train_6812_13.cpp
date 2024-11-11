#include <bits/stdc++.h>
using namespace std;
int a[111][111];
char s[111][111];
int f[111][111][11];
int path[111][111][11];
char st[111];
int n, m, k;
void print_path(int i, int j, int l) {
  if (i < n) {
    print_path(i + 1, path[i][j][l], ((l - a[i][j]) % k + k) % k);
    if (path[i][j][l] == j + 1)
      printf("L");
    else
      printf("R");
  } else {
    printf("%d\n", j);
  }
}
int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", st);
    for (int j = 1; j <= m; ++j) a[i][j] = st[j - 1] - '0';
  }
  k++;
  memset(f, 0x80, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    f[n][i][a[n][i] % k] = a[n][i];
  }
  for (int i = n - 1; i >= 1; --i)
    for (int j = 1; j <= m; ++j) {
      for (int l = 0; l < k; ++l) {
        int tmp = ((l - a[i][j]) % k + k) % k;
        if (f[i + 1][j - 1][tmp] > f[i + 1][j + 1][tmp]) {
          f[i][j][l] = f[i + 1][j - 1][tmp] + a[i][j];
          path[i][j][l] = j - 1;
        } else {
          f[i][j][l] = f[i + 1][j + 1][tmp] + a[i][j];
          path[i][j][l] = j + 1;
        }
      }
    }
  int p = 0;
  for (int i = 1; i <= n; ++i) {
    if (f[1][i][0] > f[1][p][0]) p = i;
  }
  if (f[1][p][0] >= 0) {
    printf("%d\n", f[1][p][0]);
    print_path(1, p, 0);
  } else
    puts("-1");
  return 0;
}
