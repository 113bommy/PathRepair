#include <bits/stdc++.h>
using namespace std;
int n, a[90], f[3200][90][90];
int main() {
  scanf("%d", &n);
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x) a[++num] = i;
  }
  memset(f, 63, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 1; i <= num; i++) {
    f[0][i][a[i]] =
        f[0][i - 1][a[i - 1]] + (a[i] - a[i - 1] - 1) * (a[i] - a[i - 1] - 1);
  }
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    f[i][0][0] = 0;
    for (int j = 1; j <= num; j++) {
      for (int k = 1; k <= n; k++) {
        if (abs(k - a[j]) > i) continue;
        f[i][j][k] = f[i - 1][j][k];
        for (int l = 0; l <= n; l++) {
          f[i][j][k] = min(f[i][j][k], f[i - abs(k - a[j])][j - 1][l] +
                                           (k - l - 1) * (k - l - 1));
        }
      }
    }
  }
  for (int i = 0; i <= n * (n - 1) / 2; i++) {
    int mn = 0x3f3f3f3f;
    for (int j = 1; j <= n; j++) mn = min(mn, f[i][num][j] + (n - j) * (n - j));
    printf("%d ", ((n - num) * (n - num) - mn) / 2);
  }
}
