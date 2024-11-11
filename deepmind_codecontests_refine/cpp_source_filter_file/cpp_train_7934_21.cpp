#include <bits/stdc++.h>
using namespace std;
bool used[105][15][15];
char a[15][15];
const int n = 8, m = 8;
void dfs(int k, int x, int y) {
  if (k >= 100) return;
  used[k][x][y] = 1;
  for (int i = -1; i < 2; i++)
    for (int j = -1; j < 2; j++) {
      int xn = i + x;
      int yn = j + y;
      if (xn < 0 || xn >= n || yn < 0 || yn >= m ||
          (xn - k) >= 0 && a[xn - k][yn] == 'S' ||
          xn - k - 1 >= 0 && a[xn - k - 1][yn] == 'S' || used[k + 1][xn][yn])
        continue;
      dfs(k + 1, xn, yn);
    }
}
int main() {
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0, n - 1, 0);
  for (int i = 0; i < 101; i++)
    if (used[i][0][m - 1]) {
      puts("YES");
      return 0;
    }
  puts("NO");
  return 0;
}
