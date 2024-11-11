#include <bits/stdc++.h>
using namespace std;
int n, a[305][1000], b[305], tem, ttem, ll, zz, i, j, sum, w[1000];
int main() {
  while (~scanf(" %d", &n)) {
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++) scanf(" %d", &b[i]);
    tem = b[1] / 9;
    ll = 1;
    for (j = 0; j < tem; j++) a[1][j + 1] = 9;
    if (b[1] % 9 == 0)
      a[1][0] = tem;
    else {
      a[1][0] = tem + 1;
      a[1][tem + 1] = b[1] % 9;
    }
    for (i = 2; i <= n; i++) {
      tem = b[i] - b[i - 1];
      if (tem > 0) {
        memcpy(a[i], a[i - 1], sizeof(a[i]));
        zz = 1;
        while (tem > 0 && a[i][0] >= zz) {
          if (a[i][zz] < 9) {
            a[i][zz]++;
            tem--;
          } else
            zz++;
        }
        while (tem > 0) {
          if (tem > 9) {
            a[i][zz] = 9;
            tem -= 9;
          } else {
            a[i][zz] = tem;
            tem = 0;
          }
          zz++;
          a[i][0]++;
        }
      } else {
        memcpy(a[i], a[i - 1], sizeof(a[i]));
        zz = 1;
        while (a[i][zz] == 9 && zz <= a[i][0]) {
          zz++;
        }
        while (zz <= a[i][0]) {
          if (a[i][zz] == 9) {
            zz++;
            continue;
          }
          memcpy(w, a[i], sizeof(w));
          sum = 0;
          for (j = 1; j < zz; j++) {
            sum += w[j];
            w[j] = 0;
          }
          sum += tem;
          if (sum - 1 >= 0) break;
          zz++;
        }
        if (zz <= a[i][0]) {
          sum = 0;
          for (j = 1; j < zz; j++) {
            sum += a[i][j];
            a[i][j] = 0;
          }
          sum += tem;
          if (sum - 1 >= 0) {
            a[i][zz]++;
            ttem = sum - 1;
            ll = 1;
            while (ttem > 0) {
              if (ttem > 9) {
                a[i][ll] = 9;
                ttem -= 9;
              } else {
                a[i][ll] = ttem;
                ttem = 0;
              }
              ll++;
            }
          } else {
            memset(a[i] + 1, 0, sizeof(a[i]) - 1);
            a[i][0]++;
            a[i][a[i][0]] = 1;
            ttem = b[i] - 1;
            ll = 1;
            while (ttem > 0) {
              if (ttem > 9) {
                a[i][ll] = 9;
                ttem -= 9;
              } else {
                a[i][ll] = ttem;
                ttem = 0;
              }
              ll++;
            }
          }
        } else {
          memset(a[i] + 1, 0, sizeof(a[i]) - 1);
          a[i][0]++;
          a[i][a[i][0]] = 1;
          ttem = b[i] - 1;
          ll = 1;
          while (ttem > 0) {
            if (ttem > 9) {
              a[i][ll] = 9;
              ttem -= 9;
            } else {
              a[i][ll] = ttem;
              ttem = 0;
            }
            ll++;
          }
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = a[i][0]; j > 0; j--) printf("%d", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
