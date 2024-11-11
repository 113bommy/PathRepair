#include <bits/stdc++.h>
using namespace std;
char maps[15][15];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
int abs(int a) {
  if (a < 0)
    return 0 - a;
  else
    return a;
}
int main(void) {
  for (int i = 0; i < 10; i++) scanf("%s", maps[i]);
  int tag = 0;
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (maps[i][j] == 'O') continue;
      for (int k = 0; k < 5; k++) {
        if (i + 5 > 10) break;
        if (maps[i + k][j] == 'X')
          count1++;
        else if (maps[i + k][j] == '.')
          count2++;
      }
      if (count1 == 4 && count2 == 1) tag = 1;
      count1 = 0;
      count2 = 0;
      for (int k = 0; k < 5; k++) {
        if (j + 5 > 10) break;
        if (maps[i][j + k] == 'X')
          count1++;
        else if (maps[i][j + k] == '.')
          count2++;
      }
      if (count1 == 4 && count2 == 1) tag = 1;
      count1 = 0;
      count2 = 0;
      for (int k = 0; k < 5; k++) {
        if (i + 5 > 10 || j + 5 > 10) break;
        if (maps[i + k][j + k] == 'X')
          count1++;
        else if (maps[i + k][j + k] == '.')
          count2++;
      }
      if (count1 == 4 && count2 == 1) tag = 1;
      count1 = 0;
      count2 = 0;
      for (int k = 0; k < 5; k++) {
        if (i + 5 > 10 || j - 4 < 0) break;
        if (maps[i + k][j - k] == 'X')
          count1++;
        else if (maps[i + k][j - k] == '.')
          count2++;
      }
      if (count1 == 4 && count2 == 1) tag = 1;
      count1 = 0;
      count2 = 0;
    }
  }
  if (tag)
    printf("YES\n");
  else
    printf("NO\n");
}
