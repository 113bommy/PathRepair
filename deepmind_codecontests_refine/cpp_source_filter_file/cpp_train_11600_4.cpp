#include <bits/stdc++.h>
int x[100010] = {0}, y[100010] = {0}, z[100010] = {0};
int main() {
  int n, p, q, i, tmp;
  char str[100010];
  scanf("%s", str);
  int len = strlen(str);
  if (str[0] == 'x')
    x[1] = 1;
  else if (str[0] == 'y')
    y[1] = 1;
  else
    z[1] = 1;
  for (i = 1; i < len; i++) {
    x[i + 1] = x[i];
    y[i + 1] = y[i];
    z[i + 1] = z[i];
    if (str[i] == 'x')
      x[i + 1]++;
    else if (str[i] == 'y')
      y[i + 1]++;
    else
      z[i + 1]++;
  }
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &p, &q);
    int x1 = x[q] - x[p - 1];
    int y1 = y[q] - y[p - 1];
    int z1 = z[q] - z[p - 1];
    if ((q - p + 1) < 3)
      printf("YES\n");
    else {
      int div = (q - p + 1) / 3;
      int rem = (q - p + 1) % 3;
      if (rem == 0) {
        if (x1 == y1 && y1 == z1)
          printf("YES\n");
        else
          printf("NO\n");
      } else if (rem == 1) {
        if (x1 == div && y1 == div && z1 == div + 1)
          printf("YES\n");
        else if (x1 == div && y1 == div + 1 && z1 == div + 1)
          printf("YES\n");
        else if (x1 == div + 1 && y1 == div && z1 == div)
          printf("YES\n");
        else
          printf("NO\n");
      } else {
        if (x1 == div && y1 == div + 1 && z1 == div + 1)
          printf("YES\n");
        else if (x1 == div + 1 && y1 == div && z1 == div + 1)
          printf("YES\n");
        else if (x1 == div + 1 && y1 == div + 1 && z1 == div)
          printf("YES\n");
        else
          printf("NO\n");
      }
    }
  }
  return 0;
}
