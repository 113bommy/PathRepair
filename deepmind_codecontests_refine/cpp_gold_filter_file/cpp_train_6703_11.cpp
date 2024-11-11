#include <bits/stdc++.h>
int t[1000][1000][2];
int m[1000][1000][2];
int n;
inline void tbuild(int base) {
  int ind, i, j;
  if (base == 2)
    ind = 0;
  else
    ind = 1;
  for (i = 1; i != n; i++)
    for (j = 1; j != n; j++) {
      t[i][j][ind] = m[i][j][ind];
      if (t[i - 1][j][ind] < t[i][j - 1][ind])
        t[i][j][ind] += t[i - 1][j][ind];
      else
        t[i][j][ind] += t[i][j - 1][ind];
    }
}
inline void way(int ind) {
  int i = n - 1, j = n - 1, ic = (n - 1) * 2 - 1;
  char buf[2010];
  buf[ic + 1] = '\0';
  while (i != 0 || j != 0)
    if (i != 0)
      if (t[i][j][ind] == t[i - 1][j][ind] + m[i][j][ind]) {
        buf[ic] = 'D';
        i--;
        ic--;
      } else {
        buf[ic] = 'R';
        j--;
        ic--;
      }
    else {
      buf[ic] = 'R';
      j--;
      ic--;
    }
  fprintf(stdout, "%s", buf);
}
inline void way0(int i0, int j0) {
  int i, j;
  for (i = 0; i != i0; i++) fprintf(stdout, "D");
  for (j = 0; j != j0; j++) fprintf(stdout, "R");
  for (; i != n - 1; i++) fprintf(stdout, "D");
  for (; j != n - 1; j++) fprintf(stdout, "R");
}
void tprint() {
  int i, j;
  for (i = 0; i != n; i++) {
    fprintf(stdout, "\n");
    for (j = 0; j != n; j++) fprintf(stdout, "%d", t[i][j][0]);
  }
  for (i = 0; i != n; i++) {
    fprintf(stdout, "\n");
    for (j = 0; j != n; j++) fprintf(stdout, "%d", t[i][j][1]);
  }
  for (i = 0; i != n; i++) {
    fprintf(stdout, "\n");
    for (j = 0; j != n; j++) fprintf(stdout, "%d", m[i][j][0]);
  }
  for (i = 0; i != n; i++) {
    fprintf(stdout, "\n");
    for (j = 0; j != n; j++) fprintf(stdout, "%d", m[i][j][1]);
  }
}
int main() {
  int i, j, i0 = -1, j0 = -1, temp1;
  fscanf(stdin, "%d", &n);
  for (i = 0; i != n; i++)
    for (j = 0; j != n; j++) {
      fscanf(stdin, "%d", &temp1);
      if (temp1) {
        while (!(temp1 % 5)) {
          m[i][j][1] += 1;
          temp1 /= 5;
        }
        while (!(temp1 % 2)) {
          m[i][j][0] += 1;
          temp1 /= 2;
        }
      } else {
        m[i][j][0] = m[i][j][1] = 1;
        i0 = i;
        j0 = j;
      }
    }
  t[0][0][0] = m[0][0][0];
  t[0][0][1] = m[0][0][1];
  for (i = 1; i != n; i++) {
    t[i][0][0] = t[i - 1][0][0] + m[i][0][0];
    t[i][0][1] = t[i - 1][0][1] + m[i][0][1];
    t[0][i][0] = t[0][i - 1][0] + m[0][i][0];
    t[0][i][1] = t[0][i - 1][1] + m[0][i][1];
  }
  tbuild(2);
  tbuild(5);
  int min, minind;
  if (t[n - 1][n - 1][0] > t[n - 1][n - 1][1]) {
    min = t[n - 1][n - 1][1];
    minind = 1;
  } else {
    min = t[n - 1][n - 1][0];
    minind = 0;
  }
  if (min > 1 && i0 != -1) {
    fprintf(stdout, "1\n");
    way0(i0, j0);
  } else {
    fprintf(stdout, "%d\n", min);
    way(minind);
  }
  return 0;
}
