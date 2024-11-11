#include <bits/stdc++.h>
using namespace std;
char pan[100][100];
int n, m;
int main() {
  int i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(pan, '#', sizeof(pan));
    for (i = 2; i <= n; i += 2) {
      for (j = 1; j <= m; j++) pan[i][j] = '.';
      if (i / 2 % 2)
        pan[i][m] = '#';
      else
        pan[i][1] = '#';
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) printf("%c", pan[i][j]);
      printf("\n");
    }
  }
  return 0;
}
