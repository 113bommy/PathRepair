#include <bits/stdc++.h>
using namespace std;
int n, i, j, a[2000][2000], z = 0, x[2000], y[2000], xx[2000], yy[2000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%1d", &a[i][j]);
  for (i = 0; i < n - 1; i++)
    for (j = n - 1; j > i; j--)
      if ((x[i] + y[j] + a[i][j]) % 2 == 1) x[i]++, y[j]++, z++;
  for (i = n - 1; i > 0; i--)
    for (j = 0; j < i; j++)
      if ((xx[i] + yy[j] + a[i][j]) % 2 == 1) xx[i]++, yy[j]++, z++;
  for (i = 0; i < n; i++)
    if ((x[i] + y[i] + xx[i] + yy[i] + a[i][i]) % 2 == 1) z++;
  cout << z;
  return 0;
}
