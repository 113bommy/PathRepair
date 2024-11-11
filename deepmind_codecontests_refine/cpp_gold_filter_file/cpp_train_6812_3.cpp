#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
char s[101][101];
int dp[101][101][12], dd[101][101][101], N, M, K, x = -int(1e9 + 1), y, w;
int dyn(int x, int y, int r) {
  if (!~x) return r ? -int(1e9 + 1) : 0;
  if (y == M || !~y) return -int(1e9 + 1);
  int &v = dp[x][y][r], &w = dd[x][y][r], h;
  if (~v) return v;
  r = (r + s[x][y] - 48) % K;
  v = dyn(x - 1, y + 1, r), w = 0;
  h = dyn(x - 1, y - 1, r);
  if (h > v) v = h, w = 1;
  return v += s[x][y] - 48;
}
void prt(int x, int y, int r) {
  if (!x) return;
  int w = dd[x][y][r];
  r = (r + s[x][y] - 48) % K;
  putchar(w ? 'L' : 'R');
  prt(x - 1, y + (w ? -1 : 1), r);
}
int main(void) {
  (memset(dp, -1, sizeof(dp))), scanf("%d%d%d", &N, &M, &K), ++K;
  for (int i(0); i < N; i++) scanf("%s", s[i]);
  for (int i(0); i < M; i++) {
    y = dyn(N - 1, i, 0);
    if (y > x) x = y, w = i;
  }
  if (x < 0) return puts("-1");
  printf("%d\n%d\n", x, w + 1);
  prt(N - 1, w, 0), puts("");
  return 0;
}
