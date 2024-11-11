#include <bits/stdc++.h>
using namespace std;
int i, j, x[8], y[8], T;
bool flag;
int main() {
  for (i = 0; i < 8; i++) scanf("%d%d", &x[i], &y[i]);
  for (i = 0; i < 8; i++)
    for (j = 0; j < 7; j++)
      if ((x[j] > x[j + 1]) || ((x[j] == x[j + 1]) && (y[j] > y[j + 1]))) {
        T = x[j];
        x[j] = x[j + 1];
        x[j + 1] = T;
        T = y[j];
        y[j] = y[j + 1];
        y[j + 1] = T;
      }
  flag = 1;
  flag &= (x[0] == x[1]) && (x[0] == x[2]);
  flag &= (x[3] == x[4]);
  flag &= (x[5] == x[6]) && (x[5] == x[7]);
  flag &= (y[0] == y[3]) && (y[0] == y[5]);
  flag &= (y[1] == y[6]);
  flag &= (y[2] == y[4]) && (y[2] == y[7]);
  flag &= (x[0] < x[3]) && (x[3] < x[5]);
  flag &= (y[0] < y[1]) && (y[1] < y[2]);
  if (flag)
    printf("respectable\n");
  else
    printf("ugly\n");
  return 0;
}
