#include <bits/stdc++.h>
using namespace std;
char my[5][15], ach[40][15];
int main() {
  int p[24][4] = {0, 1, 2, 3, 0, 1, 3, 2, 0, 2, 1, 3, 0, 2, 3, 1, 0, 3, 1, 2,
                  0, 3, 2, 1, 1, 0, 2, 3, 1, 0, 3, 2, 1, 2, 0, 3, 1, 2, 3, 0,
                  1, 3, 0, 2, 1, 3, 2, 0, 2, 0, 1, 3, 2, 0, 3, 1, 2, 1, 0, 3,
                  2, 1, 3, 0, 2, 3, 0, 1, 2, 3, 1, 0, 3, 0, 1, 2, 3, 0, 2, 1,
                  3, 1, 0, 2, 3, 1, 2, 0, 3, 2, 0, 1, 3, 2, 1, 0};
  int n, m, k;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%s", my[i]);
    scanf("%d", &m);
    int P = -4, ans;
    for (int h = 1; h <= m; h++) {
      scanf("%d", &k);
      for (int i = 0; i < k; i++) scanf("%s", ach[i]);
      if (k < n) continue;
      for (int j, i = 0; i < 24; i++) {
        j = 0;
        for (int r = 0; r < k && j < n; r++)
          if (strcmp(my[p[i][j]], ach[r]) == 0) j++;
        if (j >= n) {
          int cnt = 0;
          for (int i1 = 1; i1 < 4; i1++)
            for (int i2 = 0; i2 < i1; i2++)
              if (p[i][i1] < p[i][i2]) cnt++;
          int tmp = n * (n - 1) / 2 + 1 - cnt;
          if (P < tmp) P = tmp, ans = h;
        }
      }
    }
    if (P < 0)
      puts("Brand new problem!");
    else {
      printf("%d\n[:", ans);
      for (int i = 0; i < P; i++) putchar('|');
      puts(":]");
    }
  }
  return 0;
}
