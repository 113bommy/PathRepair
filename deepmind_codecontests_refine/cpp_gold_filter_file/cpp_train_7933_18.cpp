#include <bits/stdc++.h>
using namespace std;
char m[20][20], r[20][20][20];
bool rec(int i, int j, int t) {
  int k, l;
  if (t > 9) return 1;
  if (r[i][j][t]) return r[i][j][t] - 1;
  for (k = -1; k <= 1; k++)
    for (l = -1; l <= 1; l++)
      if (i + k >= 0 && i + k < 8 && j + l >= 0 && j + l < 8)
        if ((i + k - t < 0 || m[i + k - t][j + l] != 'S') &&
            (i + k - t - 1 < 0 || m[i + k - t - 1][j + l] != 'S') &&
            rec(i + k, j + l, t + 1)) {
          r[i][j][t] = 2;
          return 1;
        }
  r[i][j][t] = 1;
  return 0;
}
int main() {
  int i;
  for (i = 0; i < 8; scanf("%s", m[i]), i++)
    ;
  if (rec(7, 0, 0))
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
