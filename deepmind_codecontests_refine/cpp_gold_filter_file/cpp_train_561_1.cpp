#include <bits/stdc++.h>
using namespace std;
char a[506][506];
int w;
void f(int x, int y) {
  if (!w) return;
  a[x][y] = '.';
  w++;
  if (a[x][y + 1] == 'X') f(x, y + 1);
  if (a[x + 1][y] == 'X') f(x + 1, y);
  if (a[x][y - 1] == 'X') f(x, y - 1);
  if (a[x - 1][y] == 'X') f(x - 1, y);
}
int main() {
  int n, m, x, y;
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        a[i][j] = 'X';
        x = i, y = j, w--;
      }
    }
  }
  f(x, y);
  for (int i = 0; i < n; i++) {
    printf("%s\n", a[i]);
  }
}
