#include <bits/stdc++.h>
using namespace std;
int org[1007][1007], row[1007], col[1007], n, m, k, x, y;
char c;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    row[i] = i;
    for (int j = 0; j < m; j++) {
      scanf("%d", &org[i][j]);
      col[j] = j;
    }
  }
  for (int i = 0; i < k; i++) {
    scanf(" %c%d%d", &c, &x, &y);
    if (c == 'r')
      swap(row[x - 1], row[y - 1]);
    else if (c == 'c')
      swap(col[x - 1], col[y - 1]);
    else
      printf("%d\n", org[row[x - 1]][col[y - 1]]);
  }
  return 0;
}
