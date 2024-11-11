#include <bits/stdc++.h>
int rug[1005][1005];
int cond[1005][1005][4];
int k, h, w, cost, tot;
int main() {
  int i, j;
  scanf("%d %d %d", &h, &w, &k);
  for (i = 1; i <= h; i++)
    for (j = 1; j <= w; j++)
      cond[i][j][0] = cond[i][j][1] = cond[i][j][2] = cond[i][j][3] = -1;
  char ch;
  for (j = 1; j <= w - 1; j++) {
    scanf(" %c", &ch);
    cond[1][j][1] = ch == 'E';
    cond[1][j + 1][0] = ch == 'E';
    tot++;
  }
  for (i = 2; i <= h; i++) {
    for (j = 1; j <= w; j++) {
      tot++;
      scanf(" %c", &ch);
      cond[i][j][2] = ch == 'E';
      cond[i - 1][j][3] = ch == 'E';
    }
    for (j = 1; j <= w - 1; j++) {
      tot++;
      scanf(" %c", &ch);
      cond[i][j][1] = ch == 'E';
      cond[i][j + 1][0] = ch == 'E';
    }
  }
  if (k == 1) {
    int sum = 0;
    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
        sum += (cond[i][j][0] == 1) + (cond[i][j][2] == 1);
    if (sum * 4 >= tot * 3) {
      printf("YES\n");
      for (i = 1; i <= h; i++) {
        printf("%d", 1);
        for (j = 2; j <= w; j++) printf(" %d", 1);
        printf("\n");
      }
    } else
      printf("NO\n");
  } else {
    if (w < h) {
      rug[1][1] = 0;
      for (j = 2; j <= h; j++) rug[j][1] = rug[j - 1][1] ^ (!cond[j][1][2]);
      for (i = 2; i <= w; i++) {
        rug[1][i] = 0;
        for (j = 2; j <= h; j++) rug[j][i] = rug[j - 1][i] ^ (!cond[j][i][2]);
        int sm = 0;
        for (j = 1; j <= h; j++)
          sm += (rug[j][i] != rug[j][i - 1] && cond[j][i][0]) ||
                (rug[j][i] == rug[j][i - 1] && !cond[j][i][0]);
        if (h - sm < sm) {
          for (j = 1; j <= h; j++) rug[j][i] = 1 - rug[j][i];
        }
      }
      printf("YES\n");
      for (i = 1; i <= h; i++) {
        printf("%d", rug[1][j] + 1);
        for (j = 2; j <= w; j++) printf(" %d", rug[j][i] + 1);
        printf("\n");
      }
    } else {
      rug[1][1] = 0;
      for (j = 2; j <= w; j++) rug[1][j] = rug[1][j - 1] ^ (!cond[1][j][0]);
      for (i = 2; i <= h; i++) {
        rug[i][1] = 0;
        for (j = 2; j <= w; j++) rug[i][j] = rug[i][j - 1] ^ (!cond[i][j][0]);
        int sm = 0;
        for (j = 1; j <= w; j++)
          sm += (rug[i][j] != rug[i - 1][j] && cond[i][j][2]) ||
                (rug[i][j] == rug[i - 1][j] && !cond[i][j][2]);
        if (w - sm < sm) {
          for (j = 1; j <= w; j++) rug[i][j] = 1 - rug[i][j];
        }
      }
      printf("YES\n");
      for (i = 1; i <= h; i++) {
        printf("%d", rug[i][1] + 1);
        for (j = 2; j <= w; j++) printf(" %d", rug[i][j] + 1);
        printf("\n");
      }
    }
  }
  return 0;
}
