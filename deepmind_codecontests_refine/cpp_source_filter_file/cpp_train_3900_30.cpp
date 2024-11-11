#include <bits/stdc++.h>
const int N = 5010;
using namespace std;
map<int, long long> mn, sc;
long long grid[N][N], res[2];
int x[2], y[2];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &grid[i][j]);
      mn[i + j] += grid[i][j];
      sc[i - j] += grid[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int parity = (i + j) & 1;
      if (res[parity] < mn[i + j] + sc[i - j] - grid[i][j]) {
        res[parity] = mn[i + j] + sc[i - j] - grid[i][j];
        x[parity] = i;
        y[parity] = j;
      }
    }
  }
  printf("%lld\n%d %d %d %d\n", res[0] + res[1], x[0], y[0], x[1], y[1]);
  return 0;
}
