#include <bits/stdc++.h>
using namespace std;
int f[105][10005];
void output(int n, int m, int k, int t) {
  if (n == 1 && m == 1) {
    printf("%d ", k);
    return;
  }
  if (n >= 4 && m == n + 1) {
    if (n & 1) {
      printf("%d ", k + (n + 1) / 2);
      for (int i = 1; i <= n / 2; i++) {
        printf("%d ", k + i);
        printf("%d ", k + n - i + 1);
      }
    } else {
      for (int i = 1; i <= n / 2; i++) printf("%d %d ", k + n / 2 + i, k + i);
    }
    return;
  }
  if (n >= 2 && m == n * (n + 1) / 2) {
    if (t)
      for (int i = n; i >= 1; i--) printf("%d ", k + i);
    else
      for (int i = 1; i <= n; i++) printf("%d ", k + i);
    return;
  }
  for (int i = 2; i < n; i++) {
    if (f[n - i + 1][m - (i * (i + 1) / 2) + 1]) {
      if (t) {
        for (int j = n; j >= n - i + 2; j--) printf("%d ", k + j);
        output(n - i + 1, m - (i * (i + 1) / 2) + 1, k, t ^ 1);
      } else {
        for (int j = 1; j < i; j++) printf("%d ", k + j);
        output(n - i + 1, m - (i * (i + 1) / 2) + 1, k + i - 1, t ^ 1);
      }
      return;
    }
  }
}
int main() {
  f[1][1] = 1;
  for (int i = 4; i <= 100; i++) f[i][i + 1] = 1;
  for (int i = 2; i <= 100; i++)
    for (int j = 1; j <= 100 - i + 1; j++)
      for (int k = j; k <= j * (j + 1) / 2; k++)
        if (f[j][k]) {
          f[j + i - 1][k + (i * (i + 1) / 2) - 1] = 1;
        }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (f[n][m]) {
      printf("YES\n");
      output(n, m, 0, 0);
      printf("\n");
    } else
      printf("NO\n");
  }
}
