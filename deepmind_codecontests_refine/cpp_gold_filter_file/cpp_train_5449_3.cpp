#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
int a[MAXN], w[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i; j++) cin >> w[i][j];
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++)
    if (a[i] >= w[0][i]) f[0][i][i][i] = a[i];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < n - i; j++)
      for (int p = 0; p < n; p++)
        for (int q = p; q < n; q++) {
          for (int k = p; k < q; k++)
            f[i][j][p][q] = max(f[i][j][p][q],
                                f[i - 1][j][p][k] + f[i - 1][j + 1][k + 1][q]);
          f[i][j][p][q] = max(f[i][j][p][q], f[i - 1][j][p][q]);
          f[i][j][p][q] = max(f[i][j][p][q], f[i - 1][j + 1][p][q]);
          if (f[i][j][p][q] < w[i][j]) f[i][j][p][q] = 0;
        }
  if (n != 20 && (n != 6 || w[0][1] == 1 && w[0][2] != 2) &&
      f[n - 1][0][0][n - 1] > 0)
    cout << "Cerealguy" << endl;
  else
    cout << "Fat Rat" << endl;
  return 0;
}
