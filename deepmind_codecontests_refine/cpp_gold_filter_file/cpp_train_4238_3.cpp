#include <bits/stdc++.h>
using namespace std;
const int mmax = 2000 + 5;
const int inf = 0x3f3f3f3f;
int n, u[mmax], v[mmax], f[mmax][11][11][11][11];
int dfs(int i, int cur, int a, int b, int c) {
  if (~f[i][cur][a][b][c]) return f[i][cur][a][b][c];
  int ret = inf;
  if (i > n) {
    if (a == 0 && b == 0 & c == 0) return 0;
    if (a)
      ret = (ret) < dfs(i, a, 0, b, c) + abs((cur) - (a)) + 1
                ? ret
                : dfs(i, a, 0, b, c) + abs((cur) - (a)) + 1;
    if (b)
      ret = (ret) < dfs(i, b, a, 0, c) + abs((cur) - (b)) + 1
                ? ret
                : dfs(i, b, a, 0, c) + abs((cur) - (b)) + 1;
    if (c)
      ret = (ret) < dfs(i, c, a, b, 0) + abs((cur) - (c)) + 1
                ? ret
                : dfs(i, c, a, b, 0) + abs((cur) - (c)) + 1;
    return f[i][cur][a][b][c] = ret;
  }
  if (a)
    ret = (ret) < dfs(i, a, 0, b, c) + abs((cur) - (a)) + 1
              ? ret
              : dfs(i, a, 0, b, c) + abs((cur) - (a)) + 1;
  if (b)
    ret = (ret) < dfs(i, b, a, 0, c) + abs((cur) - (b)) + 1
              ? ret
              : dfs(i, b, a, 0, c) + abs((cur) - (b)) + 1;
  if (c)
    ret = (ret) < dfs(i, c, a, b, 0) + abs((cur) - (c)) + 1
              ? ret
              : dfs(i, c, a, b, 0) + abs((cur) - (c)) + 1;
  if (a && b && c) {
    ret = (ret) < dfs(i + 1, v[i], a, b, c) + abs((cur) - (u[i])) +
                      abs((u[i]) - (v[i])) + 2
              ? ret
              : dfs(i + 1, v[i], a, b, c) + abs((cur) - (u[i])) +
                    abs((u[i]) - (v[i])) + 2;
    ret = (ret) < dfs(i + 1, a, v[i], b, c) + abs((cur) - (u[i])) +
                      abs((u[i]) - (a)) + 2
              ? ret
              : dfs(i + 1, a, v[i], b, c) + abs((cur) - (u[i])) +
                    abs((u[i]) - (a)) + 2;
    ret = (ret) < dfs(i + 1, b, a, v[i], c) + abs((cur) - (u[i])) +
                      abs((u[i]) - (b)) + 2
              ? ret
              : dfs(i + 1, b, a, v[i], c) + abs((cur) - (u[i])) +
                    abs((u[i]) - (b)) + 2;
    ret = (ret) < dfs(i + 1, c, a, b, v[i]) + abs((cur) - (u[i])) +
                      abs((u[i]) - (c)) + 2
              ? ret
              : dfs(i + 1, c, a, b, v[i]) + abs((cur) - (u[i])) +
                    abs((u[i]) - (c)) + 2;
  } else {
    if (!a)
      ret = (ret) < dfs(i + 1, u[i], v[i], b, c) + abs((cur) - (u[i])) + 1
                ? ret
                : dfs(i + 1, u[i], v[i], b, c) + abs((cur) - (u[i])) + 1;
    else if (!b)
      ret = (ret) < dfs(i + 1, u[i], a, v[i], c) + abs((cur) - (u[i])) + 1
                ? ret
                : dfs(i + 1, u[i], a, v[i], c) + abs((cur) - (u[i])) + 1;
    else
      ret = (ret) < dfs(i + 1, u[i], a, b, v[i]) + abs((cur) - (u[i])) + 1
                ? ret
                : dfs(i + 1, u[i], a, b, v[i]) + abs((cur) - (u[i])) + 1;
  }
  return f[i][cur][a][b][c] = ret;
}
int main() {
  memset(f, 0xff, sizeof(f));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", u + i, v + i);
  printf("%d\n", dfs(1, 1, 0, 0, 0));
  return 0;
}
