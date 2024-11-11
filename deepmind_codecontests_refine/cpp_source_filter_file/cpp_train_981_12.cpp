#include <bits/stdc++.h>
using namespace std;
char field[2002][2002];
int main() {
  int m, n, k;
  cin >> n >> m >> k;
  int res[2002] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> field[i][j];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ((2 * i <= n) && (field[i + i][j] == 'U')) res[j]++;
      if ((j >= i) && (field[i][j - i] == 'R')) res[j]++;
      if ((i + j <= m) && (field[i][j + i] == 'L')) res[j]++;
    }
  for (int i = 0; i < m; i++) cout << res[i];
  return 0;
}
