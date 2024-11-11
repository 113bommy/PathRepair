#include <bits/stdc++.h>
using namespace std;
int n, x;
char g[110][110];
int main() {
  cin >> n >> x;
  if (n == 100) {
    for (int i = 1; i < 100; i++) {
      g[i][0] = '^';
    }
    for (int i = 1; i < 100; i++) {
      g[99][i] = '<';
    }
    g[0][0] = '>';
    for (int i = 0; i < 99; i++) {
      if (i % 2 == 0) {
        for (int j = 1; j < 50; j++) {
          g[i][j] = '>';
        }
        for (int j = 50; j < 99; j += 2) {
          g[i][j] = '>';
        }
        for (int j = 51; j < 99; j += 2) {
          g[i][j] = '.';
        }
        g[i][99] = 'v';
      } else {
        for (int j = 51; j < 100; j++) {
          g[i][j] = '<';
        }
        for (int j = 2; j < 51; j += 2) {
          g[i][j] = '<';
        }
        for (int j = 3; j < 51; j += 2) {
          g[i][j] = '.';
        }
        g[i][1] = 'v';
      }
    }
  } else if (n == 5) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) g[i][j] = '.';
    g[0][0] = '>';
    g[0][4] = 'v';
    g[1][0] = 'v';
    g[1][2] = '<';
    g[2][2] = '^';
    g[3][0] = '>';
    g[4][2] = '^';
    g[4][4] = '<';
  } else {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) g[i][j] = '.';
    g[0][0] = '>';
    g[0][1] = 'v';
    g[0][2] = 'v';
    g[1][0] = '^';
    g[1][1] = '<';
    g[2][0] = '^';
    g[2][2] = '<';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%c", g[i][j]);
    printf("\n");
  }
  if (n != 3)
    printf("1 1\n");
  else
    printf("1 3\n");
}
