#include <bits/stdc++.h>
using namespace std;
const int maxn = 404;
int a[404], tmp[maxn], p[maxn], q[maxn];
int c[1002];
int b[maxn][maxn], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n * n; i++) c[a[i]]++;
  if (n % 2 == 0) {
    int t = 1, k = 1;
    for (int i = 1; i <= 1000; i++)
      if (c[i] % 4 == 0 && c[i]) p[t++] = i;
    for (int i = 1; i < t; i++)
      for (int j = 1; j <= c[p[i]] / 4; j++) tmp[k++] = p[i];
    if (k != n * n / 4 + 1)
      puts("NO");
    else {
      int r = 1;
      for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= n / 2; j++)
          b[i][j] = b[i][n - j + 1] = b[n - i + 1][j] =
              b[n - i + 1][n - j + 1] = tmp[r++];
      puts("YES");
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", b[i][j]);
        puts("");
      }
    }
  } else {
    int t = 1, k = 1;
    for (int i = 1; i <= 1000; i++) {
      if (c[i] % 4 == 0 && c[i]) {
        int ww = c[i];
        for (int j = 1; j <= ww / 4; j++) tmp[k++] = i;
      } else if (c[i] % 4 == 2) {
        int ww = c[i];
        for (int j = 1; j <= ww / 4; j++) tmp[k++] = i, c[i] -= 4;
      } else if (c[i] % 4 == 1) {
        b[n / 2 + 1][n / 2 + 1] = i;
        c[i]--;
        int ww = c[i];
        for (int j = 1; j <= ww / 4; j++) tmp[k++] = i, c[i] -= 4;
      } else if (c[i] % 2 == 1) {
        b[n / 2 + 1][n / 2 + 1] = i;
        c[i]--;
        int ww = c[i];
        for (int j = 1; j <= ww / 4; j++) tmp[k++] = i, c[i] -= 4;
      }
    }
    int dd = ((n / 2) * (n / 2));
    for (int i = dd + 1; i < k; i++)
      for (int j = 1; j <= 2; j++) q[t++] = tmp[i];
    for (int i = 1; i <= 1000; i++) {
      if (c[i] % 2 == 0 && c[i] && c[i] % 4 != 0) {
        int ww = c[i];
        for (int j = 1; j <= ww / 2; j++) q[t++] = i;
      }
    }
    int r = 1;
    for (int i = 1; i <= n / 2; i++)
      for (int j = 1; j <= n / 2; j++)
        b[i][j] = b[i][n - j + 1] = b[n - i + 1][j] = b[n - i + 1][n - j + 1] =
            tmp[r++];
    int x = 1;
    for (int i = 1; i <= n / 2; i++)
      b[n / 2 + 1][i] = b[n / 2 + 1][n - i + 1] = q[x++];
    for (int i = 1; i <= n / 2; i++)
      b[i][n / 2 + 1] = b[n - i + 1][n / 2 + 1] = q[x++];
    int fg = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (b[i][j] == 0) fg = 1;
    if (fg)
      puts("NO");
    else {
      puts("YES");
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", b[i][j]);
        puts("");
      }
    }
  }
  return 0;
}
