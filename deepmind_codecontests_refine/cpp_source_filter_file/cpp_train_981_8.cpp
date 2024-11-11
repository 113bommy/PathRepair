#include <bits/stdc++.h>
using namespace std;
int counter[15000];
char grid[2015][2050];
int main() {
  int n, m, t;
  scanf("%d %d %d", &n, &m, &t);
  for (int i = 0; i < n; i++) {
    scanf("%s", &grid[i]);
  }
  for (int j = 0; j < m; j++) {
    for (int i = 1; i < n; i++) {
      if (i + i < n && grid[i + i][j] == 'U') counter[j]++;
      if (j + i < m && grid[i][j + i] == 'L') counter[j]++;
      if (i - j >= 0 && grid[i][j - i] == 'R') counter[j]++;
    }
  }
  for (int i = 0; i < m; i++) printf("%d ", counter[i]);
}
