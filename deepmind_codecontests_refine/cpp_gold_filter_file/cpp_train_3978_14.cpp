#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int v[30005];
  int f[30005];
  int fl1, fl2, f2, f1;
  int p1, p2, r1, r2;
  int i, j;
  int sol = 0, nex, flag = 0, first = 0, paux, r2aux;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  if (n == 2) {
    printf("%d\n%d\n", v[0], v[1]);
    sol = 1;
  }
  if (n > 2) {
    nex = 0;
    while (sol == 0 && first < 2) {
      if (nex < 2)
        nex++;
      else
        first++;
      memset(f, 0, sizeof(int) * n);
      sol = 1;
      r1 = v[nex] - v[first];
      p1 = v[first];
      fl1 = 0;
      fl2 = 0;
      f2 = 0;
      f1 = 0;
      flag = 0;
      for (i = 0; i < n; i++) {
        if ((fl2 == 0 || (fl2 == 1 && v[i] == p2)) && f1) {
          flag = 1;
          if (fl1 == 0) {
            paux = v[i];
            if (i + 1 < n) {
              r2aux = v[i + 1] - v[i];
            }
          } else if (fl2 == 0) {
            r2aux = v[i] - r2;
            paux = v[i];
          } else {
            r2aux = r2;
            paux = p2;
          }
          for (j = i; j < n; j++) {
            if (v[j] == paux) {
              paux += r2aux;
            } else {
              flag = 0;
              break;
            }
          }
          if (flag == 1) {
            f2 = 1;
            for (j = i; j < n; j++) {
              f[j] = 2;
            }
            break;
          }
        }
        if (v[i] == p1) {
          if (flag == 0) {
            f1 = 1;
            p1 += r1;
            f[i] = 1;
          } else {
            p2 += r2;
            f[i] = 2;
          }
        } else {
          if (fl1 == 0) {
            f[i] = 2;
            fl1 = 1;
            r2 = v[i];
            f2 = 1;
          } else if (fl2 == 0) {
            f[i] = 2;
            fl2 = 1;
            r2 = v[i] - r2;
            p2 = v[i] + r2;
          } else if (v[i] == p2) {
            p2 += r2;
            f[i] = 2;
          } else {
            sol = 0;
            break;
          }
        }
      }
      if (!f2 || !f1) {
        sol = 0;
      }
      if (sol == 1) {
        for (i = 0; i < n; i++) {
          if (f[i] == 1) {
            printf("%d ", v[i]);
          }
        }
        printf("\n");
        for (i = 0; i < n; i++) {
          if (f[i] == 2) {
            printf("%d ", v[i]);
          }
        }
        printf("\n");
        break;
      }
    }
  }
  if (sol == 0) {
    printf("No solution\n");
  }
  return 0;
}
