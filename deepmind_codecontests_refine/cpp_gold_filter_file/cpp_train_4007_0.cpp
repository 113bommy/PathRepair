#include <bits/stdc++.h>
using namespace std;
int color[1024][1024];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (color[x - 1][y - 1] && color[x][y - 1] && color[x - 1][y]) {
      printf("%d\n", i);
      exit(0);
    }
    if (color[x - 1][y] && color[x - 1][y + 1] && color[x][y + 1]) {
      printf("%d\n", i);
      exit(0);
    }
    if (color[x][y - 1] && color[x + 1][y - 1] && color[x + 1][y]) {
      printf("%d\n", i);
      exit(0);
    }
    if (color[x + 1][y] && color[x][y + 1] && color[x + 1][y + 1]) {
      printf("%d\n", i);
      exit(0);
    }
    color[x][y] = 1;
  }
  printf("%d\n", 0);
}
