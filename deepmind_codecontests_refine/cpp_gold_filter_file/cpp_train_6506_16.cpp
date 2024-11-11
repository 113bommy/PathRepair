#include <bits/stdc++.h>
using namespace std;
long long f[100100][8];
int n, m, a[100100];
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = getchar() - 'a';
  a[n + 1] = a[0] = -1;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (f[i - 1][0]) {
      f[i][0] += f[i - 1][0];
      if (a[i] != a[i + 1] && a[i + 1] >= 0) f[i][7] += f[i - 1][0];
      if (a[i] == a[i + 1] || a[i + 1] < 0)
        f[i][2] += f[i - 1][0] * (long long)(m - 1);
      else
        f[i][2] += f[i][0] * (long long)(m - 2);
    }
    if (f[i - 1][1]) f[i][1] += f[i - 1][1];
    if (f[i - 1][2]) {
      if (a[i] != a[i - 1]) f[i][1] += f[i - 1][2];
      f[i][3] += f[i - 1][2];
    }
    if (f[i - 1][3]) {
      f[i][3] += f[i - 1][3];
      if (a[i] != a[i - 1]) f[i][1] += f[i - 1][3];
    }
    if (f[i - 1][4]) {
      if (a[i] != a[i - 1] && a[i] != a[i - 2]) f[i][1] += f[i - 1][4];
      if (a[i] != a[i - 2]) f[i][3] += f[i - 1][4];
      if (a[i] == a[i - 2] && a[i + 1] != a[i - 1] && a[i + 1] >= 0)
        f[i][5] += f[i - 1][4];
      if (a[i] == a[i - 2]) f[i][4] += f[i - 1][4];
      if (a[i] == a[i - 2]) {
        if (a[i + 1] < 0 || a[i + 1] == a[i - 1])
          f[i][6] += f[i - 1][4] * (long long)(m - 1);
        else
          f[i][6] += f[i - 1][4] * (long long)(m - 2);
      }
    }
    if (f[i - 1][5]) {
      if (a[i + 1] >= 0) f[i][5] += f[i - 1][5];
      if (a[i + 1] < 0)
        f[i][6] += f[i - 1][5] * (long long)m;
      else
        f[i][6] += f[i - 1][5] * (long long)(m - 1);
    }
    if (f[i - 1][6]) f[i][1] += f[i - 1][6];
    if (f[i - 1][7]) {
      f[i][4] += f[i - 1][7];
      if (a[i + 1] >= 0 && a[i + 1] != a[i - 1]) f[i][5] += f[i - 1][7];
      if (a[i + 1] < 0 || a[i + 1] == a[i - 1])
        f[i][6] += f[i - 1][7] * (long long)(m - 1);
      else
        f[i][6] += f[i - 1][7] * (long long)(m - 2);
    }
  }
  printf("%I64d",
         f[n][1] + f[n][2] + f[n][3] + f[n][4] + f[n][5] + f[n][6] + f[n][7]);
  return 0;
}
