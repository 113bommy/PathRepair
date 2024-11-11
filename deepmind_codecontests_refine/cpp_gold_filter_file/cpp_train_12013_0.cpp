#include <bits/stdc++.h>
int main() {
  long long a[31][1001][5];
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < 1001; j++) {
      for (int k = 1; k < 4; k++) {
        if (k > 1) {
          a[i][j][k] = 0;
          for (int s = 0; s < j + 1; s++) {
            a[i][j][k] += (a[i][s][k - 1] * a[i][j - s][1]) % 7340033;
          }
          a[i][j][k] %= 7340033;
        } else if (k == 1) {
          if (j == 0) {
            a[i][j][k] = 1;
          } else if (j > 0 && i == 0) {
            a[i][j][k] = 0;
          } else {
            a[i][j][k] = 0;
            for (int s = 0; s < j; s++) {
              a[i][j][k] += (a[i - 1][s][1] * a[i - 1][j - 1 - s][3]) % 7340033;
            }
            a[i][j][k] %= 7340033;
          }
        }
      }
    }
  }
  int count;
  scanf("%d", &count);
  int n, k;
  while (count-- > 0) {
    scanf("%d%d", &n, &k);
    int round = 0;
    while ((n % 2 == 1) && (n >= 2)) {
      round++;
      n /= 2;
    }
    printf("%ld\n", a[round][k][1]);
  }
  return 0;
}
