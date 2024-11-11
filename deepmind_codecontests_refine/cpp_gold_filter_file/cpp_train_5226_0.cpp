#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = 1010;
int n, m, k, w;
int nex[M << 2][M], ed[M][M], deg[N], col[M], now[N];
void solve(int now, int a, int b) {
  swap(ed[now][b], ed[now][a]);
  swap(nex[now][b], nex[now][a]);
  col[ed[now][b]] = b;
  if (nex[now][b]) solve(nex[now][b], b, a);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  int x, y, c1, c2, T = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &x);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    y += n;
    c1 = c2 = 0;
    if (deg[x] % k == 0) now[x] = ++T;
    deg[x]++;
    x = now[x];
    if (deg[y] % k == 0) now[y] = ++T;
    deg[y]++;
    y = now[y];
    for (int j = 1; j <= k; j++)
      if (!nex[x][j] && !nex[y][j]) {
        c1 = j;
        break;
      }
    if (!c1) {
      for (int j = 1; j <= k; j++)
        if (!nex[x][j]) {
          c1 = j;
          break;
        }
      for (int j = 1; j <= k; j++)
        if (!nex[y][j]) {
          c2 = j;
          break;
        }
      solve(y, c1, c2);
    }
    nex[x][c1] = y;
    nex[y][c1] = x;
    ed[x][c1] = i;
    ed[y][c1] = i;
    col[i] = c1;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", col[i]);
}
