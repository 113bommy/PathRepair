#include <bits/stdc++.h>
const int N = 100010;
int w[N], s[N], temp[N], a[N][6], b[N][6], t2[N][3], t3[N][4];
bool p[N];
int main() {
  int n, m = 0, s2 = 0, s3 = 0, i, j, k, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &w[i]);
  memset(p, false, sizeof(p));
  for (i = 1; i <= n; i++)
    if (!p[i]) {
      p[i] = true;
      if (w[i] != i) {
        temp[0] = 1;
        temp[1] = i;
        while (w[temp[temp[0]]] != i) {
          temp[temp[0] + 1] = w[temp[temp[0]]];
          temp[0]++;
          p[temp[temp[0]]] = true;
        }
        j = 1;
        while (j < temp[0]) {
          if (j + 4 <= temp[0]) {
            m++;
            s[m] = 5;
            a[m][1] = i;
            for (k = 1; k <= 4; k++) {
              a[m][k + 1] = temp[j + k];
              b[m][k] = temp[j + k];
            }
            b[m][5] = i;
            j += 4;
          } else if (j + 3 == temp[0]) {
            m++;
            s[m] = 4;
            a[m][1] = i;
            for (k = 1; k <= 3; k++) {
              a[m][k + 1] = temp[j + k];
              b[m][k] = temp[j + k];
            }
            b[m][4] = i;
            j += 3;
          } else if (j + 2 == temp[0]) {
            s3++;
            t3[s3][1] = i;
            for (k = 1; k <= 2; k++) t3[s3][k + 1] = temp[j + k];
            j += 2;
          } else {
            s2++;
            t2[s2][1] = i;
            t2[s2][2] = temp[j + 1];
            j++;
          }
        }
      }
    }
  if (s2 < s3)
    x = s2;
  else
    x = s3;
  for (i = 1; i <= x; i++) {
    m++;
    s[m] = 5;
    for (j = 1; j <= 3; j++) {
      a[m][j] = t3[i][j];
      if (j == 3)
        b[m][j] = t3[i][1];
      else
        b[m][j] = t3[i][j + 1];
    }
    a[m][4] = t2[i][1];
    a[m][5] = t2[i][2];
    b[m][4] = a[m][5];
    b[m][5] = a[m][4];
  }
  i = x;
  while (i + 2 <= s2) {
    m++;
    s[m] = 4;
    a[m][1] = t2[i + 1][1];
    a[m][2] = t2[i + 1][2];
    b[m][1] = a[m][2];
    b[m][2] = a[m][1];
    a[m][3] = t2[i + 2][3];
    a[m][4] = t2[i + 2][4];
    b[m][3] = a[m][4];
    b[m][4] = a[m][3];
    i += 2;
  }
  while (i < s2) {
    m++;
    s[m] = 2;
    a[m][1] = t2[i + 1][1];
    a[m][2] = t2[i + 1][2];
    b[m][1] = a[m][2];
    b[m][2] = a[m][1];
    i++;
  }
  i = x;
  while (i + 3 <= s3) {
    m++;
    s[m] = 5;
    for (j = 1; j <= 3; j++) {
      a[m][j] = t3[i + 1][j];
      if (j == 3)
        b[m][j] = t3[i + 1][1];
      else
        b[m][j] = t3[i + 1][j + 1];
    }
    a[m][4] = t3[i + 3][1];
    a[m][5] = t3[i + 3][2];
    b[m][4] = a[m][5];
    b[m][5] = a[m][4];
    m++;
    s[m] = 5;
    for (j = 1; j <= 3; j++) {
      a[m][j] = t3[i + 2][j];
      if (j == 3)
        b[m][j] = t3[i + 2][1];
      else
        b[m][j] = t3[i + 2][j + 1];
    }
    a[m][4] = t3[i + 3][1];
    a[m][5] = t3[i + 3][3];
    b[m][4] = a[m][5];
    b[m][5] = a[m][4];
    i += 3;
  }
  while (i < s3) {
    m++;
    s[m] = 3;
    for (j = 1; j <= 3; j++) {
      a[m][j] = t3[i + 1][j];
      if (j == 3)
        b[m][j] = t3[i + 1][1];
      else
        b[m][j] = t3[i + 1][j + 1];
    }
    i++;
  }
  printf("%d\n", m);
  for (i = 1; i <= m; i++) {
    printf("%d\n", s[i]);
    for (j = 1; j <= s[i]; j++) printf("%d ", a[i][j]);
    printf("\n");
    for (j = 1; j <= s[i]; j++) printf("%d ", b[i][j]);
    printf("\n");
  }
  return (0);
}
