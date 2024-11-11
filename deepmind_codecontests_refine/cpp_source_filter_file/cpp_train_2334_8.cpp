#include <bits/stdc++.h>
int main() {
  int a, b, c, w = 0, e[9], i, j;
  char d[999][999];
  scanf("%d", &a);
  b = a * 2;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) scanf(" %c", &d[i][j]);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) {
      if (d[i][j] == '1')
        e[1]++;
      else if (d[i][j] == '2')
        e[2]++;
      else if (d[i][j] == '3')
        e[3]++;
      else if (d[i][j] == '4')
        e[4]++;
      else if (d[i][j] == '5')
        e[5]++;
      else if (d[i][j] == '6')
        e[6]++;
      else if (d[i][j] == '7')
        e[7]++;
      else if (d[i][j] == '8')
        e[8]++;
      else if (d[i][j] == '9')
        e[9]++;
    }
  for (i = 1; i < 10; i++) {
    if (e[i] > b) w = -1;
  }
  if (w == -1)
    printf("NO");
  else
    printf("YES");
  return 0;
}
