#include <bits/stdc++.h>
using namespace std;
int main() {
  int na, nb, ma, mb;
  scanf("%d %d", &na, &ma);
  int a[na][ma];
  char buff[55];
  for (int i = (0); i < (na); i++) {
    scanf("%s", buff);
    for (int j = (0); j < (ma); j++) a[i][j] = buff[j] - 48;
  }
  scanf("%d %d", &nb, &mb);
  int b[nb][mb], xmax = 0, ymax = 0, of = 0;
  for (int i = (0); i < (nb); i++) {
    scanf("%s", buff);
    for (int j = (0); j < (mb); j++) b[i][j] = buff[j] - 48;
  }
  for (int x = (-na + 1); x < (na); x++)
    for (int y = (-ma + 1); y < (ma); y++) {
      int temp = 0;
      for (int i = (0); i < (na); i++)
        for (int j = (0); j < (ma); j++) {
          if (i + x >= nb || j + y >= mb) continue;
          if (i + x < 0 || j + y < 0) continue;
          temp += a[i][j] * b[x + i][y + j];
        }
      if (of < temp) {
        xmax = x;
        ymax = y;
        of = temp;
      }
    }
  printf("%d ", xmax);
  printf("%d\n", ymax);
  return 0;
}
