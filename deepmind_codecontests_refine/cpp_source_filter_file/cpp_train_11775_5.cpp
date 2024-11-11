#include <bits/stdc++.h>
using namespace std;
int n;
int f[200000 + 5][5];
vector<int> a[200000 + 5];
int fa[200000 + 5];
int d[200000 + 5];
void read(int& x) { scanf("%d", &x); }
void dfs(int x) {
  for (int i = 0; i < a[x].size(); i++) {
    int y = a[x][i];
    if (fa[x] == y) continue;
    fa[y] = x;
    d[x] = d[y] + 1;
    dfs(y);
  }
}
int dp(int x, int w) {
  if (w == 1 && a[x].size() == 1) return f[x][w] = (1 << 30);
  if (f[x][w]) return f[x][w];
  int z = (1 << 30);
  for (int i = 0; i < a[x].size(); i++) {
    int y = a[x][i];
    if (y == fa[x]) continue;
    dp(y, 0), dp(y, 1), dp(y, 2);
    if (w != 2)
      f[x][w] += min(f[y][1], f[y][2] + 1);
    else
      f[x][w] += min(min(f[y][0], f[y][1]), f[y][2] + 1);
    z = min(z, f[y][2] - min(f[y][2], f[y][1]));
  }
  if (w == 1) f[x][w] += z;
  return f[x][w];
}
int main() {
  read(n);
  int frt = 0;
  for (int i = 1; i < n; i++) {
    int x, y;
    read(x);
    read(y);
    if (frt == 0) frt = x;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1);
  int ans = 0;
  for (int i = 0; i < a[1].size(); i++) {
    ans += dp(a[1][i], 2);
  }
  printf("%d", ans);
  return 0;
}
