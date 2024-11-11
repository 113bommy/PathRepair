#include <bits/stdc++.h>
using namespace std;
long long p[15][5], c[15][5], pi[15];
long long d1, d2, d3, d1c, d2c, d3c, pd;
int main() {
  p[1][1] = 1;
  p[1][2] = 2;
  p[1][3] = 3;
  p[2][1] = 1;
  p[2][2] = 3;
  p[2][3] = 2;
  p[3][1] = 2;
  p[3][2] = 1;
  p[3][3] = 3;
  p[4][1] = 2;
  p[4][2] = 3;
  p[4][3] = 1;
  p[5][1] = 3;
  p[5][2] = 1;
  p[5][3] = 2;
  p[6][1] = 3;
  p[6][2] = 2;
  p[6][3] = 1;
  for (int i = 1; i <= 8; i++)
    scanf("%I64d%I64d%I64d", &c[i][1], &c[i][2], &c[i][3]);
  for (pi[1] = 1; pi[1] <= 6; pi[1]++)
    for (pi[2] = 1; pi[2] <= 6; pi[2]++)
      for (pi[3] = 1; pi[3] <= 6; pi[3]++)
        for (pi[4] = 1; pi[4] <= 6; pi[4]++)
          for (pi[5] = 1; pi[5] <= 6; pi[5]++)
            for (pi[6] = 1; pi[6] <= 6; pi[6]++)
              for (pi[7] = 1; pi[7] <= 6; pi[7]++)
                for (pi[8] = 1; pi[8] <= 6; pi[8]++) {
                  d1 = 0;
                  d2 = 0;
                  d3 = 0;
                  d1c = 0;
                  d2c = 0;
                  d3c = 0;
                  for (int i = 1; i <= 8; i++) {
                    for (int j = i + 1; j <= 8; j++) {
                      pd = (c[i][p[pi[i]][1]] - c[j][p[pi[j]][1]]) *
                           (c[i][p[pi[i]][1]] - c[j][p[pi[j]][1]]);
                      pd += (c[i][p[pi[i]][2]] - c[j][p[pi[j]][2]]) *
                            (c[i][p[pi[i]][2]] - c[j][p[pi[j]][2]]);
                      pd += (c[i][p[pi[i]][3]] - c[j][p[pi[j]][3]]) *
                            (c[i][p[pi[i]][3]] - c[j][p[pi[j]][3]]);
                      if (!d1) {
                        d1 = pd, d1c = 1;
                      } else if (pd == d1) {
                        d1c++;
                      } else if (!d2) {
                        d2 = pd, d2c = 1;
                      } else if (pd == d2) {
                        d2c++;
                      } else if (!d3) {
                        d3 = pd, d3c = 1;
                      } else if (pd == d3) {
                        d3c++;
                      } else {
                        j = 9, i = 9;
                      }
                    }
                  }
                  if (d1 > d2 && d1 > d3) {
                    if (d1c == 4 && d2c == 12 && d3c == 12) {
                      printf("YES\n");
                      for (int k = 1; k <= 8; k++)
                        printf("%I64d %I64d %I64d\n", c[k][p[pi[k]][1]],
                               c[k][p[pi[k]][2]], c[k][p[pi[k]][3]]);
                      return 0;
                    }
                  } else if (d2 > d3) {
                    if (d1c == 12 && d2c == 4 && d3c == 12) {
                      printf("YES\n");
                      for (int k = 1; k <= 8; k++)
                        printf("%I64d %I64d %I64d\n", c[k][p[pi[k]][1]],
                               c[k][p[pi[k]][2]], c[k][p[pi[k]][3]]);
                      return 0;
                    }
                  } else {
                    if (d1c == 12 && d2c == 12 && d3c == 4) {
                      printf("YES\n");
                      for (int k = 1; k <= 8; k++)
                        printf("%I64d %I64d %I64d\n", c[k][p[pi[k]][1]],
                               c[k][p[pi[k]][2]], c[k][p[pi[k]][3]]);
                      return 0;
                    }
                  }
                }
  printf("NO\n");
}
