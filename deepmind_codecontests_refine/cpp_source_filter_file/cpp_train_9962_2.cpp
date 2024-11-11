#include <bits/stdc++.h>
bool x[50][2000];
long long f[50];
int n = 0;
int main() {
  scanf("%d", &n);
  f[0] = 1;
  for (int i = 0, t = 0; i <= 20; i++)
    for (int j = 0; j <= 20; j++)
      for (int k = 0; k <= 20; k++)
        for (int l = 0; l <= 20; l++)
          if (i + j + k + l <= 20)
            x[i + j + k + l][i + j * 5 + k * 10 + l * 50] = 1;
  for (int i = 0; i <= 20; i++)
    for (int j = 0; j < 2000; j++) f[i] += x[i][j];
  if (n <= 13)
    printf("%I64d\n", f[n]);
  else
    printf("%I64d\n", (n - 13) * 49LL + f[n]);
  return 0;
}
