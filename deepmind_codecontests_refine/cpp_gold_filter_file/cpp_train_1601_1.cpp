#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int matrix[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &matrix[i][j]);
  long long int cost;
  cost = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) cost += matrix[i][j];
  int k;
  scanf("%d", &k);
  while (k--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    x--;
    y--;
    if (z < matrix[x][y]) {
      matrix[x][y] = z;
      matrix[y][x] = z;
      cost = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          matrix[i][j] = min(matrix[i][j], matrix[i][x] + z + matrix[y][j]);
          matrix[i][j] = min(matrix[i][j], matrix[i][y] + z + matrix[x][j]);
          matrix[j][i] = matrix[i][j];
          cost += matrix[i][j];
        }
      }
    }
    printf("%I64d\n", cost);
  }
  return 0;
}
