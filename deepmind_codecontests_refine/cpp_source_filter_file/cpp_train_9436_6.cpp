#include <bits/stdc++.h>
char cr[6][6];
int cost[6][6];
int main() {
  int base_cost = 5;
  for (int i = 0; i < 6; i++) {
    if (i % 2 == 0) base_cost--;
    for (int j = 0; j < 6; j++) {
      if (j == 2 || j == 3)
        cost[i][j] = base_cost;
      else
        cost[i][j] = base_cost - 1;
    }
  }
  int x = 0, y = 0, best = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      scanf("%c", &cr[i][j]);
      if (cr[i][j] == '.' && best < cost[i][j]) {
        x = i;
        y = j;
        best = cost[i][j];
      }
      char c;
      if (j == 1 || j == 3) scanf("%c", &c);
    }
    char c;
    if (i != 5) scanf("%c", &c);
  }
  cr[x][y] = 'P';
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      printf("%c", cr[i][j]);
      if (cr[i][j] == '.' && best < cost[i][j]) {
        x = i;
        y = j;
        best = cost[i][j];
      }
      char c;
      if (j == 1 || j == 3) printf("%c", '_');
    }
    printf("\n");
  }
}
