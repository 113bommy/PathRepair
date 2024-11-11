#include <bits/stdc++.h>
using namespace std;
char grid[5][5];
int firstStep, secondStep;
bool judge(char c) {
  int i;
  bool flag = false;
  for (i = 0; i < 3 && !flag; ++i) {
    if (grid[i][0] == c && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
      flag = true;
    if (grid[0][i] == c && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
      flag = true;
  }
  if (grid[0][0] == c && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    flag = true;
  if (grid[0][2] == c && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    flag = true;
  return flag;
}
void RUN() {
  bool firstWin = judge('X');
  bool secondWin = judge('0');
  int i, j;
  firstStep = secondStep = 0;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      if (grid[i][j] == 'X')
        firstStep++;
      else if (grid[i][j] == '0')
        secondStep++;
    }
  }
  if (firstWin && secondWin) {
    printf("illegal\n");
  } else if (firstStep - secondStep == 0) {
    if (firstWin)
      printf("illegal\n");
    else if (secondWin)
      printf("the second player won\n");
    else
      printf("first\n");
  } else if (firstStep - secondStep == 1) {
    if (firstWin)
      printf("the first player won\n");
    else if (secondWin)
      printf("illegal\n");
    else if (firstStep + secondStep == 9)
      printf("illegal\n");
    else
      printf("second\n");
  } else {
    printf("illegal\n");
  }
}
void READ() {
  int i;
  for (i = 0; i < 3; ++i) {
    gets(grid[i]);
  }
}
int main() {
  READ();
  RUN();
  return 0;
}
