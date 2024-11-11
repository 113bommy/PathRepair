#include <bits/stdc++.h>
using namespace std;
int def[4], atk[4], win[2][2];
int main() {
  for (int i = 0; i < 4; i++) scanf("%d %d", &def[i], &atk[i]);
  for (int i = 0; i < 2; i++) {
    int first_atk = atk[i];
    int first_def = def[i ^ 1];
    int cnt = 0;
    for (int j = 0; j < 2; j++) {
      int second_atk = atk[2 + j];
      int second_def = def[2 + (j ^ 1)];
      if (first_atk > second_def && first_def > second_atk)
        win[i][j] = 0;
      else if (second_atk > first_def && second_def > first_atk)
        win[i][j] = 1;
      else
        win[i][j] = -1;
    }
  }
  if ((win[0][0] == 0 && win[0][1] == 0) || (win[1][0] == 0 && win[1][1] == 0))
    printf("Team 1\n");
  else if ((win[0][0] == 1 || win[0][1] == 1) &&
           (win[1][0] == 1 || win[1][1] == 1))
    printf("Team 2\n");
  else
    printf("Draw\n");
  return 0;
}
