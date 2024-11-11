#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110][110];
bool del[110][110];
bool need_del(int x, int y) {
  for (int i(0); i <= (n - 1); i++)
    if (a[x][i] == a[x][y] && i != y) return true;
  for (int i(0); i <= (m - 1); i++)
    if (a[i][y] == a[x][y] && i != x) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  getchar();
  for (int i(0); i <= (n - 1); i++) {
    for (int j(0); j <= (m - 1); j++) {
      a[i][j] = getchar();
    }
    getchar();
  }
  for (int i(0); i <= (n - 1); i++)
    for (int j(0); j <= (m - 1); j++)
      if (need_del(i, j)) del[i][j] = true;
  for (int i(0); i <= (n - 1); i++)
    for (int j(0); j <= (m - 1); j++)
      if (!del[i][j]) putchar(a[i][j]);
  printf("\n");
  return 0;
}
