#include <bits/stdc++.h>
int main() {
  int k;
  while (scanf("%d", &k) == 1) {
    int G[250][250] = {};
    G[1][3] = 1;
    for (int i = 3; i < 75; i++) {
      if (i % 2 == 0) {
        G[i][i + 1] = 1;
        G[i][i + 2] = 1;
      } else {
        G[i][i + 2] = 1;
        G[i][i + 3] = 1;
      }
    }
    for (int i = 200; i < 233; i++) G[i][i + 1] = 1;
    G[233][2] = 1;
    for (int i = 0; i < 32; i++)
      if (k & (1 << i)) {
        G[(i + 2) * 2][200 + i] = 1;
      }
    printf("233\n");
    for (int i = 1; i <= 20; i++) {
      for (int j = 1; j <= 20; j++)
        printf("%c", (G[i][j] || G[j][i]) ? 'Y' : 'N');
      printf("\n");
    }
  }
  return 0;
}
