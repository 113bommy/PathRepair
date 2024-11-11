#include <bits/stdc++.h>
using namespace std;
const int Mn = 1000 + 10;
const int M = 1e9 + 7;
long long f[Mn][Mn][5];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  f[1][0][0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= n; j++) {
      (f[i + 1][j][0] += f[i][j][0]) %= M;
      (f[i + 1][j + 2][3] += f[i][j][0]) %= M;
      (f[i + 1][j][2] += (i - 1 - j) * f[i][j][0] % M) %= M;
      (f[i + 1][j - 1][2] += j * f[i][j][0] % M) %= M;
      (f[i + 1][j][0] += f[i][j][1]) %= M;
      (f[i + 1][j + 1][1] += f[i][j][1]) %= M;
      (f[i + 1][j][4] += f[i][j][1]) %= M;
      (f[i + 1][j][2] += (i - 2 - (j - 1)) * f[i][j][1] % M) %= M;
      (f[i + 1][j - 1][2] += (j - 1) * f[i][j][1] % M) %= M;
      (f[i + 1][j][0] += f[i][j][2]) %= M;
      (f[i + 1][j + 1][1] += f[i][j][2]) %= M;
      (f[i + 1][j + 1][4] += f[i][j][2]) %= M;
      (f[i + 1][j][2] += (i - 2 - j) * f[i][j][2] % M) %= M;
      (f[i + 1][j - 1][2] += j * f[i][j][2] % M) %= M;
      (f[i + 1][j][0] += f[i][j][3]) %= M;
      (f[i + 1][j][1] += f[i][j][3]) %= M;
      (f[i + 1][j][4] += f[i][j][3]) %= M;
      (f[i + 1][j][2] += (i - 2 - (j - 2)) * f[i][j][3] % M) %= M;
      (f[i + 1][j - 1][2] += (j - 2) * f[i][j][3] % M) %= M;
      (f[i + 1][j][0] += f[i][j][4]) %= M;
      (f[i + 1][j][1] += f[i][j][4]) %= M;
      (f[i + 1][j + 1][4] += f[i][j][4]) %= M;
      (f[i + 1][j][2] += (i - 2 - (j - 1)) * f[i][j][4] % M) %= M;
      (f[i + 1][j - 1][2] += (j - 1) * f[i][j][4] % M) %= M;
    }
  cout << (f[n][k][0] + f[n][k][1] + f[n][k][2] + f[n][k][3] + f[n][k][4]) % M
       << endl;
  return 0;
}
