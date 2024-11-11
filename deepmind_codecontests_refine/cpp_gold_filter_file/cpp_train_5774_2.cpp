#include <bits/stdc++.h>
int main(void) {
  int tiles;
  scanf("%d\n", &tiles);
  char board[10001] = {};
  for (int i = 0; i < tiles * tiles; i += tiles) scanf("\n%s", &board[i]);
  int xindent[] = {1, 0, -1, 0};
  int yindent[] = {0, 1, 0, -1};
  for (int i = 0; i < tiles; i++) {
    for (int b = 0; b < tiles; b++) {
      int ctr = 0;
      for (int c = 0; c < 4; c++) {
        if (i + xindent[c] >= 0 && i + xindent[c] < tiles &&
            b + yindent[c] >= 0 && b + yindent[c] < tiles &&
            *(board + (i + xindent[c]) * tiles + (b + yindent[c])) == 'o')
          ctr++;
      }
      if (ctr % 2 == 1) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
}
