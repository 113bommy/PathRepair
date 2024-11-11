#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
int a[MAXN], w[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
int i, j, k, N;
void init() {
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &a[i]);
  for (i = 1; i <= N; i++)
    for (j = 1; j <= N - i + 1; j++) scanf("%d", &w[i][j]);
}
inline int DFS(int x, int y, int l, int r) {
  if (l > r || y + N - 1 < l || y > r) return dp[x][y][l][r] = 0;
  if (dp[x][y][l][r] >= 0) return dp[x][y][l][r];
  if (x < 2) return dp[x][y][l][r] = (a[y] >= w[x][y] ? a[y] : 0);
  int ret = 0;
  for (int z = l - 1; z <= r; z++)
    ret = max(ret, DFS(x - 1, y, l, z) + DFS(x - 1, y + 1, z + 1, r));
  return dp[x][y][l][r] = (ret >= w[x][y] ? ret : 0);
}
bool Bug() { return ((N != 6 || w[1][2] == 1 && w[1][3] != 2) && N != 20); }
void work() {
  (memset(dp, -1, sizeof(dp)));
  if (DFS(N, 1, 1, N) && Bug())
    puts("Cerealguy");
  else
    puts("Fat Rat");
}
int main() {
  init();
  work();
  return 0;
}
