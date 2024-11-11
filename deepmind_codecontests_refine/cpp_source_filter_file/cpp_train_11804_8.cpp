#include <bits/stdc++.h>
using namespace std;
int a, c;
char b[59][59];
int main() {
  scanf("%d %d", &a, &c);
  int mnx = 99, mny = 99, mxx = 0, mxy = 0;
  for (int i = 0; i < a; i++) scanf("%s", b[i]);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < c; j++)
      if (b[i][j] == 'B') {
        for (int l = i; l < a; l++)
          for (int k = j; k < c; k++)
            if (b[l][k] == 'B') {
              int z = 0;
              for (int t = i; t <= l; t++)
                if (b[t][j] == 'W') z = 1;
              if (z == 0) {
                for (int t = j; t <= k; t++)
                  if (b[l][t] == 'W') z = 1;
              }
              if (z == 1) {
                z = 0;
                for (int t = i; t <= l; t++)
                  if (b[t][k] == 'W') z = 1;
                if (z == 0) {
                  for (int t = j; t <= k; t++)
                    if (b[i][t] == 'W') z = 1;
                }
              }
              if (z == 1) {
                printf("NO");
                return 0;
              }
            }
      }
  printf("YES");
  getchar();
  getchar();
}
