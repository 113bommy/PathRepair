#include <bits/stdc++.h>
using namespace std;
int s[10005];
int c[150][150];
void work() {
  s[3] = 3;
  s[4] = 3;
  s[5] = 3;
  c[1][1] = 1;
  c[1][2] = 2;
  c[2][1] = 1;
  c[2][2] = 3;
  c[3][1] = 2;
  c[3][2] = 3;
  s[6] = 4;
  int m = s[6];
  int x = 5;
  while (x <= 10000) {
    int t = x + 1;
    for (int i = m - 1; i >= 1; i--) c[i][m - 1] = t--;
    for (int i = 1; i < m; i++) c[m][i] = ++t;
    for (int i = 1; i <= m; i++) s[++x] = m;
    m++;
  }
}
int main() {
  work();
  int n, j, i;
  while (scanf("%d", &n) != EOF) {
    cout << s[n] << endl;
    for (int i = 1; i <= s[n]; i++)
      for (int j = 1; j <= s[n] - 1; j++) {
        if (j == s[n] - 1)
          printf("%d\n", c[i][j]);
        else
          printf("%d ", c[i][j]);
      }
  }
  return 0;
}
