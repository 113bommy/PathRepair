#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, t;
int a[MAX * 2][MAX * 2] = {0};
void dfs(int x, int y, int up) {
  a[x][y] += up;
  int delta = a[x][y] / 4;
  if (delta > 0) {
    a[x][y] %= 4;
    dfs(x + 1, y, delta);
    dfs(x - 1, y, delta);
    dfs(x, y + 1, delta);
    dfs(x, y - 1, delta);
  }
}
int main() {
  scanf("%d %d", &n, &t);
  dfs(MAX, MAX, n);
  while (t--) {
    int x, y, r, posx, posy;
    scanf("%d %d", &x, &y);
    posx = x + MAX;
    posy = y + MAX;
    if (posx < 0 || x > MAX || posy < 0 || y > MAX)
      r = 0;
    else
      r = a[posx][posy];
    printf("%d\n", r);
  }
  return 0;
}
