#include <bits/stdc++.h>
using namespace std;
char maze[10][10];
int main() {
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) scanf("%c", &maze[i][j]);
    getchar();
  }
  int minW = 9999;
  int maxB = -1;
  bool haveB = false, haveW = false;
  for (int j = 1; j <= 8; j++) {
    haveB = haveW = false;
    for (int i = 1; i <= 8; i++) {
      if (maze[i][j] == 'B') haveB = true;
      if (maze[i][j] == 'W' && !haveB) minW = min(minW, i);
    }
    for (int i = 8; i >= 1; i--) {
      if (maze[i][j] == 'W') haveW = true;
      if (maze[i][j] == 'B' && !haveW) maxB = max(maxB, i);
    }
  }
  if (minW < 9 - maxB)
    printf("A\n");
  else
    printf("B\n");
  return 0;
}
