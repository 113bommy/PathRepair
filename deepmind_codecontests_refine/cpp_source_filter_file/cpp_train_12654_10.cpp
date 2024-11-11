#include <bits/stdc++.h>
int check(int n, long long mat[500][500]) {
  long long sum = 0;
  long long i, j;
  for (i = 0; i < n; i++) {
    sum += mat[0][i];
  }
  int b = 1;
  for (i = 0; i < n; i++) {
    long long s = 0;
    for (j = 0; j < n; j++) {
      s += mat[i][j];
    }
    if (s != sum) b = 0;
  }
  for (i = 0; i < n; i++) {
    long long s = 0;
    for (j = 0; j < n; j++) {
      s += mat[j][i];
    }
    if (s != sum) b = 0;
  }
  long long s = 0;
  for (i = 0; i < n; i++) {
    s += mat[i][i];
  }
  if (s != sum) b = 0;
  s = 0;
  for (i = 0; i < n; i++) {
    s += mat[i][n - i];
  }
  if (s != sum) b = 0;
  return b;
}
int main(int argc, const char *argv[]) {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("1");
  } else {
    long long mat[500][500];
    int x, y;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long a;
        scanf("%lld", &a);
        mat[i][j] = a;
        if (a == 0) {
          x = i;
          y = j;
        }
      }
    }
    long long sum = 0;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      sum += mat[i][(y + 1) % n];
      s += mat[i][y];
    }
    mat[x][y] = (sum - s);
    if (mat[x][y] <= 0 || check(n, mat) == -1) {
      printf("-1\n");
    } else {
      printf("%lld\n", mat[x][y]);
    }
  }
  return 0;
}
