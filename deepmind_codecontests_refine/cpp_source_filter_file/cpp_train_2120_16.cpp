#include <bits/stdc++.h>
using namespace std;
int ma[100][100];
int mb[100][100];
int a, b, aa, bb;
int main() {
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++) scanf("%1d", ma[i] + j);
  scanf("%d%d", &aa, &bb);
  for (int i = 1; i <= aa; i++)
    for (int j = 1; j <= bb; j++) scanf("%1d", mb[i] + j);
  int maxn = 0, ansx, ansy;
  for (int x = -1; x <= 100; x++)
    for (int y = -1; y <= 100; y++) {
      int sum = 0, flag = 0;
      for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
          if (1 <= i + x && i + x <= aa && 1 <= j + y && j + y <= bb) {
            flag = 1;
            sum += ma[i][j] * mb[i + x][j + y];
          }
      if (flag && maxn <= sum) {
        maxn = sum;
        ansx = x;
        ansy = y;
      }
    }
  printf("%d %d\n", ansx, ansy);
  return 0;
}
