#include <bits/stdc++.h>
int main(void) {
  char arr[8][8], temp[9];
  int pos[2][2];
  int i, n, j, k;
  scanf("%d\n", &n);
  while (n != 0) {
    k = 0;
    for (i = 0; i < 8; i++) {
      scanf("%s", temp);
      for (j = 0; j < 8; j++) {
        arr[i][j] = temp[j];
        if (arr[i][j] == 'K') {
          pos[k][0] = i + 1;
          pos[k][1] = j + 1;
          k++;
        }
      }
    }
    if ((pos[0][0] == pos[1][0] + 4 && pos[0][1] == pos[1][1] + 4) ||
        (pos[0][0] == pos[1][0] - 4 && pos[0][1] == pos[1][1] - 4) ||
        (pos[0][0] == pos[1][0] + 4 && pos[0][1] == pos[1][1] - 4) ||
        (pos[0][0] == pos[1][0] - 4 && pos[0][1] == pos[1][1] + 4) ||
        (pos[0][0] == pos[1][0] && pos[0][1] == pos[1][1] + 4) ||
        (pos[0][0] == pos[1][0] && pos[0][1] == pos[1][1] - 4) ||
        (pos[0][0] == pos[1][0] + 4 && pos[0][1] == pos[1][1]) ||
        (pos[0][0] == pos[1][0] - 4 && pos[0][1] == pos[1][1])) {
      printf("YES\n");
    } else {
      printf("NO");
    }
    n--;
  }
  return 0;
}
