#include <bits/stdc++.h>
using namespace std;
int a[2000];
char b[5000][5000];
int main() {
  for (int i = 0; i < 5000; i++)
    for (int j = 0; j < 5000; j++) b[i][j] = ' ';
  int n;
  int x = 0;
  int y = 2500;
  scanf("%d", &n);
  int miin = 500000;
  int maax = -1;
  int X = 0;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    if (i % 2 == 0) {
      for (int j = 0; j < m; j++) {
        x++;
        y--;
        if (j == 0) y++;
        b[y][x] = '/';
      }
      if (y < miin) miin = y;
    } else {
      for (int j = 0; j < m; j++) {
        x++;
        y++;
        if (j == 0) y--;
        b[y][x] = '\\';
      }
      if (y > maax) maax = y;
    }
    X += m;
  }
  for (int i = miin; i <= maax; i++) {
    for (int j = 1; j <= X; j++) printf("%c", b[i][j]);
    printf("\n");
  }
}
