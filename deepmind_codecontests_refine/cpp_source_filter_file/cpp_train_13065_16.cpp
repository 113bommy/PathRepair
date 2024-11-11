#include <bits/stdc++.h>
using namespace std;
int main() {
  const int k = 102;
  int n, m, i, j, lum = 0, mat[k][k];
  cin >> n >> m;
  int p = 2 * m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= p; j++) cin >> mat[i][j];
  for (i = 1; i <= n; i++)
    for (j = 2; j <= p; j = j + 2)
      if (mat[i][j] == 1 || mat[i][j - 1] == 1) lum++;
  cout << lum;
  return 0;
}
